#include <QtGui>
#include <QDir>
#include <stdlib.h>
#include "AnaPencere.h"
#include <QDebug>

AnaPencere::AnaPencere():QMainWindow()
{
    setupUi(this);

    connect(actionAbout_olric, SIGNAL(activated()), this, SLOT(aboutOlric()));
    connect(actionAbout_Qt, SIGNAL(activated()), this, SLOT(aboutQt()));

    connect(ButtonBurn, SIGNAL(clicked()), this, SLOT(slotBurn()));
    connect(ButtonNewClient , SIGNAL(clicked()), this, SLOT(slotCleanClientUI()));

    server_exist=false;
    rx_ipv4.setPattern("((2[0-5]{2}|2[0-4]\\d|1\\d{2}|[1-9]\\d|\\d)\\.){3}(2[0-5]{2}|2[0-4]\\d|1\\d{2}|[1-9]\\d|\\d)(/(3[012]|[12]\\d|\\d))?");
    rx_Email.setPattern( "\\b[A-Za-z0-9._%+-]{1,20}@[A-Za-z0-9.-]{1,10}\\.[A-Za-z]{2,4}\\b" );
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


void AnaPencere::burn()
{
    QStringList environment = QProcess::systemEnvironment();

    QProcess process1;
    QProcess process2;
    process1.setStandardOutputProcess(&process2);
    process1.waitForFinished(8000);
    process2.waitForFinished(8000);


    QString str1("mkisofs -R -l -V \"OLRIC\" -v -allow-multidot " + getVpnTreePath() + "/vpn-tree/"); // /usr/bin/

    QString str2="/home/meltem/Desktop/cloop-2.628/create_compressed_fs - 65536 > "+getVpnTreePath()+"/vpn-cd-tree/KNOPPIX/KNOPPIX";

    process1.start(str1);
    process2.start(str2);

    QProcess process3;
    process3.setWorkingDirectory(getVpnTreePath());
    process3.setProcessChannelMode(QProcess::MergedChannels);
    process3.waitForFinished(20000);

    QString str3="mkisofs -pad -l -r -J -V \"OLRIC\" -no-emul-boot -boot-load-size 4 -boot-info-table -b boot/isolinux/isolinux.bin -c boot/isolinux/boot.cat -hide-rr-moved -o  olric.iso vpn-cd-tree/";

    process3.start(str3);

    if (!process3.waitForFinished())
        qDebug() << "failed1 :mkisofs" << process3.errorString();
    else
        qDebug() << "output1: mkisofs" << process3.readAll();

    str3="cdrecord -v -pad -dao "+getVpnTreePath()+"/olric.iso"; //speed=16
    process3.start(str3);

    if (!process3.waitForFinished())
        qDebug() << "failed2: cdrecord" << process3.errorString();
    else
        qDebug() << "output2: cdrecord" << process3.readAll();
}


void AnaPencere::buildDHParam()
{
    QProcess process2;
    process2.setWorkingDirectory(getOpenVPNPath());
    process2.waitForFinished(10000);
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

     QFile::setPermissions( getOpenVPNPath() + "/ca.key" ,QFlag(0x0600));
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
    byte_arry.append(Server_passwd->text()+"\n");       //parola 4 kaakterden fazla olmalı
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

    QFile::setPermissions( getOpenVPNPath() + "/server.key" ,QFlag(0x0600));

}

void AnaPencere::WriteRoute()
{
    QString inside="#!/bin/bash  \n# put other system startup command here \nroute add -host "
                   +ServerIp->text()
                   +" gw 10.10.10.1 dev tun0";

    writeContent( getVpnTreePath()+"/vpn-tree/opt/bootlocal.sh" , inside);


}

void AnaPencere::cleanAll()
{
   
    QDir keyDir( getOpenVPNPath() + "/keys" );

    if(!keyDir.exists())
    {
        QDir d(getOpenVPNPath());
        d.mkdir("keys");
    }

    QFileInfoList fileInfoList = keyDir.entryInfoList();

    for(int j=0 ; j<fileInfoList.size() ; ++j)
    {
        QFileInfo fileInfo = fileInfoList.at(j);
        keyDir.remove( fileInfo.fileName());
    }

    QProcess process;
    process.setWorkingDirectory(getOpenVPNPath());

    process.start("chmod go-rwx keys/");
    
    if (!process.waitForFinished())
        qDebug() << "failed: chmod" << process.errorString();
    else
        qDebug() << "output:chmod" << process.readAll();


    QString content= getFileContent(getOpenVPNPath()+"/openssl.cnf");

    content.replace("$ENV::KEY_DIR" ,	getOpenVPNPath()+"/keys");
    content.replace("$ENV::KEY_SIZE" ,"1024");
    content.replace("$ENV::KEY_COUNTRY", Key_country->text());
    content.replace("$ENV::KEY_PROVINCE" , Key_province->text());
    content.replace("$ENV::KEY_CITY", Key_city->text());
    content.replace("$ENV::KEY_ORG" ,	Key_organization->text());
    content.replace("$ENV::KEY_EMAIL" ,Key_email->text());

    setOpenVPNPath(getOpenVPNPath() + "/keys");

    QFile opensslFile(getOpenVPNPath()+"/openssl.cnf");
    opensslFile.open(QIODevice::WriteOnly);
    QTextStream outt(&opensslFile);
    outt << content;
    opensslFile.close();

    QFile index(getOpenVPNPath()+"/index.txt");
    index.open(QIODevice::WriteOnly);
    index.close();

    QFile serial(getOpenVPNPath()+"/serial");
    serial.open(QIODevice::WriteOnly);
    QTextStream out(&serial);
    out<<"01";
    serial.close();


}

void  AnaPencere::slotBurn()
{

   //if(!server_exist && serverControl() )
   //{
        cleanAll();
        buildCertificateAuthority();
        WriteRoute();
        buildKeyServer();
        buildDHParam();
        server_exist=true;
   // }

  //  if( clientControl() )
    //{
    client client(client_userName->text(),client_passwd->text(), client_machineName->text(),client_email->text(), client_UnitName->text(), client_CompanyName->text(), ServerIp->text());
    client.run();
    burn()  ;
    //}

}


bool AnaPencere::clientControl()
{
    if(client_userName->text().isEmpty() ||client_passwd->text().isEmpty()  || client_machineName->text().isEmpty()
        ||client_email->text().isEmpty() || client_UnitName->text().isEmpty() || client_CompanyName->text().isEmpty())
    {
        QMessageBox::critical(this, tr("Missing Information"), tr("Please check fields"));
        return false;
    }

    if(!rx_ipv4.exactMatch( client_machineName->text() ) )
    {
        QMessageBox::critical(this, tr("False Client Ip"), tr("Please check field"));
        return false;
    }

    if(!rx_Email.exactMatch( client_email->text() ) )
    {
        QMessageBox::critical(this, tr("False E-Mail"), tr("Please check field"));
        return false;
    }

    if( client_passwd->text().length() < 5 )
    {
        QMessageBox::critical(this, tr("False passwd"), tr("passwd must be minimum five chracters"));
        return false;
    }
    return true;
}

bool AnaPencere::serverControl()
{
    if (  Server_commonName->text().isEmpty() || Server_companyName->text().isEmpty()  || Server_country->text().isEmpty() ||
          Server_email->text().isEmpty() || Server_locality->text().isEmpty() || Server_locality->text().isEmpty() ||
          Server_organization->text().isEmpty() || Server_organization_unit->text().isEmpty() || Server_passwd->text().isEmpty() ||
          Server_province->text().isEmpty() )
    {
        QMessageBox::critical(this, tr("Missing Information"), tr("Please check fields"));
        return false;
    }

    if( Key_city->text().isEmpty() || Key_commonName->text().isEmpty() || Key_country->text().isEmpty() ||
        Key_email->text().isEmpty() || Key_organization->text().isEmpty() || Key_province->text().isEmpty() ||
        Key_unitName->text().isEmpty() )
    {
        QMessageBox::critical(this, tr("Missing Information"), tr("Please check fields"));
        return false;
    }

    if( !rx_ipv4.exactMatch( ServerIp->text() ) )
    {
        QMessageBox::critical(this, tr("False Server Ip"), tr("Please check field"));
        return false;
    }

    if( !rx_Email.exactMatch( Server_email->text() ) || !rx_Email.exactMatch( Key_email->text() ) )
    {
        QMessageBox::critical(this, tr("False E-Mail address"), tr("Please check field"));
        return false;
    }

    if( Server_passwd->text().length() < 5  && Server_country->text().length() == 2 && Key_country->text().length() == 2 )
    {
        QMessageBox::critical(this, tr("False passwd"), tr("passwd must be minimum five chracters"));
        return false;
    }
    return true;
}


void AnaPencere::slotCleanClientUI()
{
    client_userName->clear();
    client_passwd->clear();
    client_machineName->clear();
    client_email->clear();
    client_CompanyName->clear();
    client_UnitName->clear();
}


void AnaPencere::aboutQt()
{
    QMessageBox::aboutQt(this);
}


void AnaPencere::aboutOlric()
{
   // QString aboutText = QString(tr("   OLRIC \n  Olric burn Cds that users at the Institution where I currently work part-time have expressed a need for a robust and secure connection to the internal network   "));
   // QMessageBox::information(this, tr("About Olric"), aboutText , tr("Show License") , "OK");
   About *olric = new About(this);
   olric->exec();

}
