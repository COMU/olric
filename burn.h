#include <QDialog>
#include <QMessageBox>
#include <QtCore/QProcess>

#include "ui_burn.h"


class burn:public QDialog,Ui::formBURN //formadı
{
        Q_OBJECT
        public:
       //QWidget *parent;
        burn(QWidget *parent):QDialog(parent)
        {
           // parent=p; 
            setupUi(this);
            connect (devamButton, SIGNAL(clicked()), this, SLOT(burndevam()));
        }


       public slots:
       void  burndevam()
         {
             label->setText(QString::fromUtf8("işleminiz sürdürülüyor...")); 


             QProcess Pro1;           //  COMMAND1 |COMMANT2   iso kalıbı olusturuldu
             QProcess Pro2;
             Pro1.setStandardOutputProcess(&Pro2);

             Pro1.start("/usr/bin/mkisofs -R -l -V \"OLRIC\" -v -allow-multidot /home/vpn-tree/");
             Pro2.start("create_compressed_fs - 65536 > /home/vpn-cd-tree/KNOPPIX/KNOPPIX ");

             QProcess *pro=new QProcess();
             pro->start("mkisofs -pad -l -r -J -V \"OLRIC\" -no-emul-boot -boot-load-size 4 -boot-info-table -b boot/isolinux/isolinux.bin -c boot/isolinux/boot.cat -hide-rr-moved -o  olric.iso /home/vpn-cd-tree/"); 

              QProcess *cdrecord=new QProcess();
              cdrecord->start("cdrecord -v  -pad -dao  speed=4 /home/meltem/olric.iso ");
                        //"cdrecord -v -isosize -pad -dao dev=ATAPI:0,1,0 speed=4 dosya_ismi.iso "
                        //" mkisofs −R /master/tree | cdrecord −v fs=6m speed=2 dev=2,0 ‐"  man dosyasında

          if (!cdrecord->waitForFinished())
                 label->setText(cdrecord->errorString()); 
          else
                 label->setText(cdrecord->readAllStandardOutput());


                  QMessageBox::information(this, QString::fromUtf8("bilgilendrir\n"), cdrecord->readAllStandardOutput());  //readAll ??


          /*  if (!cdrecord->waitForFinished())                   //????????????
                qDebug() << "Make failed:" << cdrecord->errorString();// QDEBUG function does nothing if QT_NO_DEBUG_OUTPUT was defined during compilation.
             else
                qDebug() << "Make output:" << cdrecord->readAll();
            QMessageBox::information(this, QString::fromUtf8("bilgilendrir\n"), cdrecord->readAllStandardOutput());  //readAll ??
         */
                      //konsolda caliştırınca kdecore (KAction): WARNING: KActionCollection::operator+=(): function is severely deprecated hatasını verio.masaustunde k33b acılıo cd kalıbı yaz acılıo;başlat a basınca iso kalıbını .
        /*   QString pro3 = "K3b"; 
            QStringList arg;
            arg <<"--image" << "/home/olric/olric.iso";

           QProcess *k3b = new QProcess();
           k3b->start(pro3, arg); */

        }
};