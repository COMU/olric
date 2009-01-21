#include <QtGui>
#include <QDir>
#include <stdlib.h>
#include "AnaPencere.h"
#include <QDebug>

AnaPencere::AnaPencere():QMainWindow()
{
     setupUi(this);
     connect(pushButton_Burn, SIGNAL(clicked()), this, SLOT(slotburn()));
}




bool  AnaPencere::whoiam()
{

    QStringList userId = QProcess::systemEnvironment().filter("UID");
    QString UserId = userId.first().split("=").last();
   if(UserId=="1000") return true;
   else return false;

}


void AnaPencere::temizle()
{
     client_userName->clear();
     client_passwd->clear();
     client_2passwd->clear();
     client_machineName->clear();
     client_email->clear();
};

bool AnaPencere::line_kontrol()
{
        if(client_userName->text().isEmpty() ||client_passwd->text().isEmpty() ||client_2passwd->text().isEmpty() ||client_machineName->text().isEmpty() ||client_email->text().isEmpty()  )
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
      QString homePath= QDir::homePath();  //home/meltem

      QStringList env = QProcess::systemEnvironment();  //QProcess members
            //environment = {"PATH=/usr/bin:/usr/local/bin", "USER=greg", "HOME=/home/greg"} 
            //QStringList home= env.filter("home");
            //QString hhome=env.join("     ");
            //QMessageBox::information(this, QString::fromUtf8("system bilgisi\n"), hhome); 

      QProcess Pro1;
      QProcess Pro2;
      // Pro1.setProcessChannelMode(QProcess::MergedChannels);
      // Pro2.setProcessChannelMode(QProcess::MergedChannels);
       Pro1.setStandardOutputProcess(&Pro2);

      QString strpro1("/usr/bin/mkisofs -R -l -V \"OLRIC\" -v -allow-multidot " + homePath + "/Olric/vpn-tree/");
        Pro1.start(strpro1);
    //    if (!Pro1.waitForFinished())   qDebug() << "Make failed:" << Pro1.errorString();
    //    else                           qDebug() << "Make output:" << Pro1.readAll();

      QString strpro2="create_compressed_fs - 65536 > "+homePath+"/Olric/vpn-cd-tree/KNOPPIX/KNOPPIX";
        Pro2.start(strpro2);
   //      if (!Pro2.waitForFinished())  qDebug() << "Make failed:" << Pro2.errorString();
   //      else                          qDebug() << "Make output:" << Pro2.readAll();

      QString strpro3="mkisofs -pad -l -r -J -V \"OLRIC\" -no-emul-boot -boot-load-size 4 -boot-info-table -b boot/isolinux/isolinux.bin -c boot/isolinux/boot.cat -hide-rr-moved -o  olric.iso "+homePath+"/Olric/vpn-cd-tree/";
      QProcess pro;
      pro.setProcessChannelMode(QProcess::MergedChannels);
      pro.start(strpro3);
       if (!pro.waitForFinished())   qDebug() << "Make failed1:" << pro.errorString();
       else                          qDebug() << "Make output1:" << pro.readAll();

      QProcess cdrecord;
      cdrecord.setProcessChannelMode(QProcess::MergedChannels);

      cdrecord.start("cdrecord -v  -pad -dao  speed=4 "+homePath+"/Olric/olric/olric.iso");
       if (!pro.waitForFinished())   qDebug() << "Make failed2:" << cdrecord.errorString();
       else                          qDebug() << "Make output2:" << cdrecord.readAll();

    //   QByteArray result = pro.readAllStandardOutput();
    //   if(result.size()>0 ) QMessageBox::information(this," ", (QString)result);

      /* "cdrecord -v -isosize -pad -dao dev=ATAPI:0,1,0 speed=4 dosya_ismi.iso"
         "mkisofs −R /master/tree | cdrecord −v fs=6m speed=2 dev=2,0 ‐" man dosyasında
    */
}

void AnaPencere::OpensslOrder()
{
     QString KeyConfig="/home/meltem/openvpn-2.0.9/easy-rsa/openssl.cnf";
     QString KeyDir="/home/meltem/openvpn-2.0.9/easy-rsa/keys";

     QString sslfiles= dosya_icerik_al("/home/meltem/openvpn-2.0.9/easy-rsa/openssl.cnf");
     sslfiles.replace("$ENV::KEY_DIR" ,	KeyDir);
     sslfiles.replace("$ENV::KEY_SIZE" ,"1024");
     sslfiles.replace("$ENV::KEY_COUNTRY", Key_Country->text());
     sslfiles.replace("$ENV::KEY_PROVINCE" , Key_Province->text());
     sslfiles.replace("$ENV::KEY_CITY", Key_City->text());
     sslfiles.replace("$ENV::KEY_ORG" ,	Key_Org->text());
     sslfiles.replace("$ENV::KEY_EMAIL" ,Key_Email->text());

     icerik_yaz("/home/meltem/openvpn-2.0.9/easy-rsa/openssl.cnf",sslfiles);


}

 void AnaPencere::BuildServerKey()
 {
      QString KeyConfig="/home/meltem/openvpn-2.0.9/easy-rsa/openssl.cnf";
      QString KeyDir="/home/meltem/openvpn-2.0.9/easy-rsa/keys";

     QProcess process;
     process.setWorkingDirectory(KeyDir);
     QString str="openssl req -days 3650 -nodes -new -x509 -keyout ca.key -out ca.crt -config ../openssl.cnf";
     QByteArray bytArr="\n\n\n\n";
        bytArr.append(Key_UnitName->text()); bytArr.append("\n");
        bytArr.append(Key_CommonName->text()); bytArr.append("\n\n");
     process.start(str);
     process.write(bytArr);

       if (!process.waitForFinished())   qDebug() << "Make failed3:" << process.errorString();
       else   qDebug() << "Make output3: ca olusturuldu." << process.readAll();

      str="openssl req -days 3650 -nodes -new -keyout server.key -out server.csr -extensions server -config "+KeyConfig;
      bytArr="\n\n\n\n"; bytArr.append(Key_UnitName->text()); bytArr.append("\n");
         bytArr.append(Key_CommonName->text()); bytArr.append("\n\n");
         bytArr.append(Server_passwd->text()); bytArr.append("\n");
         bytArr.append(Server_CompanyName->text()); bytArr.append("\n");
      process.start(str);
      process.write(bytArr);

       if (!process.waitForFinished())   qDebug() << "Make failed3:" << process.errorString();
       else   qDebug() << "Ikısım server" << process.readAll();

      str="openssl ca -days 3650 -out server.crt -in server.csr -extensions server -config "+ KeyConfig;
      process.start(str);
      process.write("y\ny\n");

       if (!process.waitForFinished())   qDebug() << "Make failed3:" << process.errorString();
       else   qDebug() << "II kısım Server.crt olusturuldu." << process.readAll();


 }

void AnaPencere::WriteRoute()
{
       QString inside="#!/bin/bash  \n# put other system startup command here \nroute add -host "+ServerIp->text()+" gw 10.10.10.1 dev tun0";

        //vpn-tree/opt/bootlocal.sh içine yaz

}
void  AnaPencere::slotburn()
{
      OpensslOrder();
      if(line_kontrol()) {

          client client(client_userName->text(),client_passwd->text(), client_machineName->text(),client_email->text(), client_UnitName->text(), client_CompanyName->text());
          client.run();
                        burn()  ;
      }

       else         QMessageBox::critical(this, tr("USERID"), tr("you must be root??? "));

}

