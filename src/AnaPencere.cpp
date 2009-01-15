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

QString AnaPencere::dosya_icerik_al( QString filename )
{

    QString inside = "";
    QFile file(filename);
    if (file.exists())
    {
       if (file.open(QFile::ReadOnly | QFile::Text))
       {
          inside =file.readAll();
          file.close();
        }
    }
    return inside;
}

bool AnaPencere::icerik_yaz(QString fullFileName,QString veri)
{
      QString data = veri;
      QFile f( fullFileName );
      if ( f.open( QFile::WriteOnly | QFile::Text ) )
      {
         QTextStream sw( &f );
         sw << data;
         f.close();
         return true;
      }
      return false;
}


bool  AnaPencere::whoiam()
{

    QStringList userId = QProcess::systemEnvironment().filter("UID");
    QString UserId = userId.first().split("=").last();
   if(UserId=="1000") return true;
   else return false;

}

void AnaPencere::rdesktop(QString kullanici_adi,QString makine_adi)
{
       QString rdesktop="/usr/bin/rdesktop -u "+kullanici_adi+"  "+makine_adi +" " ;

       QString inside=dosya_icerik_al("home/meltem/Olric/.xinitrc");
       int first = inside.indexOf("/usr/bin/rdesktop");
       inside.replace( first , inside.indexOf("&",first)-first ,rdesktop);
       icerik_yaz("home/meltem/Olric/.x,initrc", inside);
};


void AnaPencere::temizle()
{
     lineEdit_userName->clear();
     lineEdit_passwd->clear();
     lineEdit_2passwd->clear();
     lineEdit_machineName->clear();
     lineEdit_email->clear();
};

bool AnaPencere::line_kontrol()
{
        if(lineEdit_userName->text().isEmpty() ||lineEdit_passwd->text().isEmpty() ||lineEdit_2passwd->text().isEmpty() ||lineEdit_machineName->text().isEmpty() ||lineEdit_email->text().isEmpty()  )
        {
            QMessageBox::critical(this, tr("Missing Information"), tr("Please check fields"));
            qDebug() << "More information";
            return false;
        }
        else if(lineEdit_passwd->text()!=lineEdit_2passwd->text())
         {
            QMessageBox::critical(this, tr("Olric"), tr("Wrong password and password"));
            return false;
         }
        return true;
}



void AnaPencere::burn()
{
      QString yr= QDir::homePath();  //home/meltem

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

      QString strpro1("/usr/bin/mkisofs -R -l -V \"OLRIC\" -v -allow-multidot " + yr + "/Olric/vpn-tree/");
        Pro1.start(strpro1);
    //    if (!Pro1.waitForFinished())   qDebug() << "Make failed:" << Pro1.errorString();
    //    else                           qDebug() << "Make output:" << Pro1.readAll();

      QString strpro2="create_compressed_fs - 65536 > "+yr+"/Olric/vpn-cd-tree/KNOPPIX/KNOPPIX";
        Pro2.start(strpro2);
   //      if (!Pro2.waitForFinished())  qDebug() << "Make failed:" << Pro2.errorString();
   //      else                          qDebug() << "Make output:" << Pro2.readAll();

      QString strpro3="mkisofs -pad -l -r -J -V \"OLRIC\" -no-emul-boot -boot-load-size 4 -boot-info-table -b boot/isolinux/isolinux.bin -c boot/isolinux/boot.cat -hide-rr-moved -o  olric.iso "+yr+"/Olric/vpn-cd-tree/";
      QProcess pro;
      pro.setProcessChannelMode(QProcess::MergedChannels);
      pro.start(strpro3);
       if (!pro.waitForFinished())   qDebug() << "Make failed1:" << pro.errorString();
       else                          qDebug() << "Make output1:" << pro.readAll();

      QProcess cdrecord;
      cdrecord.setProcessChannelMode(QProcess::MergedChannels);

      cdrecord.start("cdrecord -v  -pad -dao  speed=4 "+yr+"/Olric/olric/olric.iso");
       if (!pro.waitForFinished())   qDebug() << "Make failed2:" << cdrecord.errorString();
       else                          qDebug() << "Make output2:" << cdrecord.readAll();

    //   QByteArray result = pro.readAllStandardOutput();
    //   if(result.size()>0 ) QMessageBox::information(this," ", (QString)result);

      /* "cdrecord -v -isosize -pad -dao dev=ATAPI:0,1,0 speed=4 dosya_ismi.iso"
         "mkisofs −R /master/tree | cdrecord −v fs=6m speed=2 dev=2,0 ‐" man dosyasında
    */
}

void AnaPencere::build_ca()
{

}

void  AnaPencere::slotburn()
{
     build_ca();

     if(whoiam())    {
              if(line_kontrol()) {

 //client client(lineEdit_userName->text(),lineEdit_passwd->text(), lineEdit_machineName->text(),lineEdit_email->text());

                     rdesktop(lineEdit_userName->text(),lineEdit_machineName->text());
                     burn()  ;
      }
     }
     else         QMessageBox::critical(this, tr("USERID"), tr("you must be root??? "));

}

