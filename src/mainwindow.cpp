#include <QtGui>
#include <QDir>
#include <stdlib.h>
#include "mainwindow.h"
#include <QDebug>

Mainwindow::Mainwindow():QMainWindow()
{
    setupUi(this);

    connect(actionAbout_olric, SIGNAL(activated()), this, SLOT(aboutOlric()));
    connect(actionAbout_Qt, SIGNAL(activated()), this, SLOT(aboutQt()));
    connect(actionConfig_olric, SIGNAL(activated()), this, SLOT(actionConfig()));
    connect(action_Exit, SIGNAL(activated()), this, SLOT(close()));

    connect(ButtonBurn, SIGNAL(clicked()), this, SLOT(slotBurn()));
    connect(ButtonNewClient , SIGNAL(clicked()), this, SLOT(slotCleanClientUI()));

    rx_ipv4.setPattern("((2[0-5]{2}|2[0-4]\\d|1\\d{2}|[1-9]\\d|\\d)\\.){3}(2[0-5]{2}|2[0-4]\\d|1\\d{2}|[1-9]\\d|\\d)(/(3[012]|[12]\\d|\\d))?");
    rx_Email.setPattern( "\\b[A-Za-z0-9._%+-]{1,20}@[A-Za-z0-9.-]{1,10}\\.[A-Za-z]{2,4}\\b" );
  
}

void Mainwindow::actionConfig()
{
    Server *olric = new Server(this);
    olric->exec();

}

bool Mainwindow::clientControl()
{
    if(line_user_name->text().isEmpty() || password->text().isEmpty()  || machine_name->text().isEmpty()
        || email->text().isEmpty() || unit_name->text().isEmpty() || company_name->text().isEmpty())
    {
        QMessageBox::critical(this, tr("Missing Information"), tr("Please check fields"));
        return false;
    }

    if(!rx_ipv4.exactMatch( machine_name->text() ) )
    {
        QMessageBox::critical(this, tr("False Client Ip"), tr("Please check field"));
        return false;
    }

    if(!rx_Email.exactMatch( email->text() ) )
    {
        QMessageBox::critical(this, tr("False E-Mail"), tr("Please check field"));
        return false;
    }

    if( password->text().length() < 5 )
    {
        QMessageBox::critical(this, tr("False passwd"), tr("passwd must be minimum five chracters"));
        return false;
    }
    return true;
}

void Mainwindow::WriteRoute()
{
    QString inside="#!/bin/bash  \n# put other system startup command here \nroute add -host "
                   + machine_name->text()
                   +" gw 10.10.10.1 dev tun0";

    writeContent( getVpnTreePath()+"/vpn-tree/opt/bootlocal.sh" , inside);

}

void Mainwindow::rdesktop()
{
    user_name = line_user_name->text();

    QString rdesktop = "/usr/bin/rdesktop -u " + user_name + "  " + machine_name->text() + " " ;

    QString content = getFileContent( getVpnTreePath()+"/vpn-tree/etc/skel/.xinitrc");

    int first = content.indexOf("/usr/bin/rdesktop");
    content.replace( first , content.indexOf("&",first)-first ,rdesktop);

    writeContent( getVpnTreePath() + "/vpn-tree/etc/skel/.xinitrc", content );
}

void Mainwindow::buildCilentKey()
{
    QByteArray byt_arry="\n\n\n\n";
    byt_arry.append(unit_name->text());
    byt_arry.append("\n");
    byt_arry.append( user_name );
    byt_arry.append("\n\n");
    byt_arry.append(password->text());
    byt_arry.append("\n");
    byt_arry.append(company_name->text());
    byt_arry.append("\n");

    QString str = "openssl req -days 3650 -nodes -new -keyout " + user_name + ".key -out " + user_name + ".csr -config openssl.cnf";
    qDebug()<< user_name << line_user_name->text();

    QProcess process1;
    process1.setWorkingDirectory(getOpenVPNPath()+"/keys");
    qDebug() << getOpenVPNPath()+"/keys";
    process1.start(str);
    process1.write(byt_arry);

    if (!process1.waitForFinished())
        qDebug() << "Make failed:" << process1.errorString();
    else
        qDebug() << "Output  :build client" << process1.readAll();

    str = "openssl ca -days 3650 -out " + user_name + ".crt -in " + user_name + ".csr -config openssl.cnf";

    process1.start(str);
    process1.write("y\ny\n");

    if (!process1.waitForFinished())
        qDebug() << "Make failed:" << process1.errorString();
    else
        qDebug() << "Output : II  client.crt olusturuldu" << process1.readAll();

    QFile::setPermissions( getOpenVPNPath() + "/" +user_name +".key" , QFlag(0x0600));


}

void Mainwindow::cpCrtToClient()
{

    QDir dir( getVpnTreePath() + "/vpn-tree/etc/openvpn/keys" );

    QFileInfoList fileInfoList = dir.entryInfoList();

    for(int j=0 ; j<fileInfoList.size() ; ++j)
    {
        QFileInfo fileInfo = fileInfoList.at(j);
        dir.remove( fileInfo.fileName());
    }

    QFile caCrt( getOpenVPNPath() + "/keys/ca.crt");
    caCrt.copy( getVpnTreePath() + "/vpn-tree/etc/openvpn/keys/ca.crt");

    QFile userCrt( getOpenVPNPath() + "/keys/" + user_name + ".crt");
    userCrt.copy( getVpnTreePath() + "/vpn-tree/etc/openvpn/keys/"+ user_name +".crt");

    QFile userKey( getOpenVPNPath() + "/keys/"+ user_name + ".key");
    userKey.copy( getVpnTreePath() + "/vpn-tree/etc/openvpn/keys/"+ user_name +".key");

}

void Mainwindow::orderClientCnf()  //iki odsya olusturuo ??????????????????????
{
    QString inside = "client \ndev tun \nproto tcp \nremote "
                     + getServerIp() + " 1194 \nresolv-retry infinite \nnobind \nuser nobody \ngroup nogroup \npersist-key \npersist-tun \nca /etc/openvpn/keys/ca.crt \ncert /etc/openvpn/keys/"
                     + user_name + ".crt \nkey /etc/openvpn/keys/"
                     + user_name + ".key \nns-cert-type server \ncomp-lzo \nverb 3 \nmute 20 \n#auth-retry interact";

    writeContent( getVpnTreePath() + "/vpn-tree/etc/openvpn/client.cnf",inside);
    qDebug() << getServerIp();
}


void Mainwindow::slotCleanClientUI()
{
    line_user_name->clear();
    password->clear();
    machine_name->clear();
    email->clear();
    company_name->clear();
    unit_name->clear();
}

void Mainwindow::aboutQt()
{
    QMessageBox::aboutQt(this);
}

void Mainwindow::aboutOlric()
{
   // QString aboutText = QString(tr("   OLRIC \n  Olric burn Cds that users at the Institution where I currently work part-time have expressed a need for a robust and secure connection to the internal network   "));
   // QMessageBox::information(this, tr("About Olric"), aboutText , tr("Show License") , "OK");
   About *olric = new About(this);
   olric->exec();

}


void Mainwindow::burn()
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

void Mainwindow::slotBurn()
{
    if( clientControl() )
    {
        qDebug()<< getCertificaExist() << getOpenVPNPath() << getRDesktopPath() << getVpnTreePath() ;
        if (!getCertificaExist()) QMessageBox::information(this, tr("About Olric"),  tr("you must build server-"));
        else{

            rdesktop();
            WriteRoute();
            buildCilentKey();
            orderClientCnf();
            cpCrtToClient();

            burn();
        }
    }

}
