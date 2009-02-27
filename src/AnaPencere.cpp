#include <QtGui>
#include <QDir>
#include <stdlib.h>
#include "AnaPencere.h"
#include <QDebug>

AnaPencere::AnaPencere():QMainWindow()
{
    setupUi(this);

    connect(ButtonBurn, SIGNAL(clicked()), this, SLOT(slotBurn()));
    connect(ButtonNewClient , SIGNAL(clicked()), this, SLOT(slotCleanClientUI()));

    server_exist=false; 
}

bool  AnaPencere::whoIAm()
{
    QStringList user_id = QProcess::systemEnvironment().filter("UID");
    QString User_id = user_id.first().split("=").last();

    if(User_id=="1000")
        return true;
    else
        return false;
}



bool AnaPencere::lineControl()
{
    if(client_userName->text().isEmpty() ||client_passwd->text().isEmpty() ||client_2passwd->text().isEmpty() || client_machineName->text().isEmpty() ||client_email->text().isEmpty() || client_UnitName->text().isEmpty() || client_CompanyName->text().isEmpty())
    {
        QMessageBox::critical(this, tr("Missing Information"), tr("Please check fields"));
        qDebug() << "More information";
        return false;
    }
    else if(client_passwd->text()!=client_2passwd->text())
    {
        QMessageBox::critical(this, tr("Olric"), tr("Wrong password and password"));
        return false;
    }
    return true;
}



void AnaPencere::burn()
{
    QStringList environment = QProcess::systemEnvironment();

    QProcess process1;
    QProcess process2;
    process1.setStandardOutputProcess(&process2);

    QString str1("mkisofs -R -l -V \"OLRIC\" -v -allow-multidot "+getVpnTreePath()+"/vpn-tree/"); // /usr/bin/
    process1.start(str1);

    QString str2="create_compressed_fs - 65536 > "+getVpnTreePath()+"/vpn-cd-tree/KNOPPIX/KNOPPIX";
    process2.start(str2);

    QString str3="mkisofs -pad -l -r -J -V \"OLRIC\" -no-emul-boot -boot-load-size 4 -boot-info-table -b boot/isolinux/isolinux.bin -c boot/isolinux/boot.cat -hide-rr-moved -o  olric.iso vpn-cd-tree/";
    QProcess process3;

    process3.setWorkingDirectory(getVpnTreePath());
    process3.setProcessChannelMode(QProcess::MergedChannels);
    process3.start(str3);

    if (!process3.waitForFinished())
        qDebug() << "Make failed1:" << process3.errorString();
    else
        qDebug() << "Make output1:" << process3.readAll();

    str3="cdrecord -v  -pad -dao  speed=4 "+getVpnTreePath()+"/olric.iso";
    process3.start(str3);

    if (!process3.waitForFinished())
        qDebug() << "Make failed2:" << process3.errorString();
    else
        qDebug() << "Make output2:" << process3.readAll();
}


void AnaPencere::buildDHParam()
{
    QProcess process2;
    process2.setWorkingDirectory(getOpenVPNPath());
    process2.waitForFinished(5000);
    process2.start( "openssl dhparam -out dh1024.pem 1024");

    if (!process2.waitForFinished())   qDebug() << "failed:dh" << process2.errorString();
    else   qDebug() << "output :dh" << process2.readAll();

}
void AnaPencere::buildCertificateAuthority()
{
    QByteArray byt_arry="\n\n\n\n";
    byt_arry.append(Key_unitName->text());
    byt_arry.append("\n");
    byt_arry.append(Key_commonName->text());
    byt_arry.append("\n\n");

    QString str="openssl req -days 3650 -nodes -new -x509 -keyout ca.key -out ca.crt -config openssl.cnf";

    QProcess process1;
    process1.setWorkingDirectory(getOpenVPNPath());
    process1.start(str);
    process1.write(byt_arry);

    if (!process1.waitForFinished())
        qDebug() << "failed: build ca" << process1.errorString();
    else
        qDebug() << "output: ca olusturuldu." << process1.readAll();

    process1.start("chmod 0600 ca.key");

    if (!process1.waitForFinished())
        qDebug() << "failed: chmod ca" << process1.errorString();
    else
        qDebug() << "Make output: chmod ca" << process1.readAll();
}



void AnaPencere::buildKeyServer()
{
    QString str = "openssl req -days 3650 -nodes -new -keyout server.key -out server.csr -extensions server -config openssl.cnf";

    QByteArray byte_arry ;
    byte_arry.append(Server_country->text()+"\n");
    byte_arry.append(Server_province->text()+"\n");
    byte_arry.append(Server_locality->text()+"\n");
    byte_arry.append(Server_organization->text()+"\n");
    byte_arry.append(Server_organization_unit->text()+"\n");
    byte_arry.append(Server_commonName->text()+"\n");
    byte_arry.append(Server_email->text()+"\n");
    byte_arry.append(Server_passwd->text()+"\n");
    byte_arry.append(Server_companyName->text()+"\n");


    QProcess process3;
    process3.setWorkingDirectory(getOpenVPNPath());   
    process3.waitForFinished(5000);
    process3.start(str);
    process3.write(byte_arry);

    if (!process3.waitForFinished())
        qDebug() << "Failed :build server" << process3.errorString();
    else
        qDebug() << "Output : I server.crt " << process3.readAll();

    str="openssl ca -days 3650 -out server.crt -in server.csr -extensions server -config openssl.cnf";
    process3.start(str);
    process3.write("y\ny\n");

    if (!process3.waitForFinished())
        qDebug() << "Failed :server" << process3.errorString();
    else
        qDebug() << "Output :Server.crt olusturuldu." << process3.readAll();

    process3.start("chmod 0600 server.key");

    if (!process3.waitForFinished())
        qDebug() << "Make failed: chmod server" << process3.errorString();
    else
        qDebug() << "Make output: chmod server" << process3.readAll();
}

void AnaPencere::WriteRoute()
{
    QString inside="#!/bin/bash  \n# put other system startup command here \nroute add -host "
                   +ServerIp->text()
                   +" gw 10.10.10.1 dev tun0";

    writeContent( getVpnTreePath()+"/vpn-tree/opt/bootlocal.sh" , inside);


}

void AnaPencere::orderOpenSSLCNF()
{

    QString ssl_files= getFileContent(getOpenVPNPath()+"/openssl.cnf");

    ssl_files.replace("$ENV::KEY_DIR" ,	getOpenVPNPath()+"/keys");
    ssl_files.replace("$ENV::KEY_SIZE" ,"1024");
    ssl_files.replace("$ENV::KEY_COUNTRY", Key_country->text());
    ssl_files.replace("$ENV::KEY_PROVINCE" , Key_province->text());
    ssl_files.replace("$ENV::KEY_CITY", Key_city->text());
    ssl_files.replace("$ENV::KEY_ORG" ,	Key_organization->text());
    ssl_files.replace("$ENV::KEY_EMAIL" ,Key_email->text());

    writeContent(getOpenVPNPath()+"/keys/openssl.cnf",ssl_files);
}

void AnaPencere::cleanAll()
{
    QProcess process;    
    process.start("mkdir " + getOpenVPNPath() + "/keys");

    if (!process.waitForFinished())
        qDebug() << "failed: mkdir" << process.errorString();
    else
        qDebug() << "output: mkdir" << process.readAll();


    process.setWorkingDirectory(getOpenVPNPath());

    process.start("chmod go-rwx keys/");
    
    if (!process.waitForFinished())
        qDebug() << "failed: chmod" << process.errorString();
    else
        qDebug() << "output:chmod" << process.readAll();

    process.start("touch keys/index.txt");
    
    if (!process.waitForFinished())
        qDebug() << "failed:touch" << process.errorString();
    else
        qDebug() << "output:touch" << process.readAll();

  //  QString str= "echo 01 > keys/serial";
    process.start("touch keys/serial");                 // < işareti için QString::from ???????????????

    if (!process.waitForFinished())
        qDebug() << "failed: echo" << process.errorString();
    else
        qDebug() << "output:echo " << process.readAll();

    writeContent(getOpenVPNPath()+"/keys/serial","01");

    process.start("touch "+getOpenVPNPath()+"/keys/openssl.cnf ");
    
    if (!process.waitForFinished())
        qDebug() << "failed: touchopenssl" << process.errorString();
    else
        qDebug() << "output:touch openssl" << process.readAll();

    orderOpenSSLCNF();

    setOpenVPNPath(getOpenVPNPath() + "/keys");
}

void  AnaPencere::slotBurn()
{    
    if(!server_exist){    //line boş ve dogru giris kontrolleri ekle???????????????
        cleanAll();
        buildCertificateAuthority();
        WriteRoute();
        buildKeyServer();
        buildDHParam();
        server_exist=true;
    }

    //if(line_kontrol()) {  //dogru giriş kontrollleri????????????

    client client(client_userName->text(),client_passwd->text(), client_machineName->text(),client_email->text(), client_UnitName->text(), client_CompanyName->text(), ServerIp->text());
    client.run();
    burn()  ;
    //}

}

void AnaPencere::slotCleanClientUI()
{
    client_userName->clear();
    client_passwd->clear();
    client_2passwd->clear();
    client_machineName->clear();
    client_email->clear();
    client_CompanyName->clear();
    client_UnitName->clear();
}
