#include <QDialog>
#include <QMessageBox>
#include <QProcess>
#include <QtGui>
//#include "ui_burn.h"
class QGroupBox;

class burn:public QDialog         //,Ui::formBURN //formadı
{
        Q_OBJECT
    public:

      burn(QWidget *parent):QDialog(parent)
      {
           //   setupUi(this);
           buttonBurn=new QPushButton(tr("I&so Olustur"));
           connect (buttonBurn, SIGNAL(clicked()), this, SLOT(burndevam()));

          GridGroupBox = new QGroupBox(this);
          QGridLayout *layout = new QGridLayout;

          layout->addWidget(buttonBurn,1,1);

          GridGroupBox->setLayout(layout);
          setWindowTitle(tr("ISO"));

        }

    private :
            QGroupBox *GridGroupBox;
            QPushButton *buttonBurn;
            QString yr;

    public slots:
       void  burndevam()
       {
             yr=="/home/meltem";
             //label->setText(QString::fromUtf8("işleminiz sür...")); 

             QStringList env = QProcess::systemEnvironment();  //QProcess members
              // environment = {"PATH=/usr/bin:/usr/local/bin", "USER=greg", "HOME=/home/greg"} 
             //   QStringList home= env.filter("home");
                QString hhome=env.join("     ");
             QMessageBox::information(this, QString::fromUtf8("system bilgisi\n"), hhome); 

             QProcess Pro1;           //  COMMAND1 |COMMANT2
             QProcess Pro2;
             Pro1.setStandardOutputProcess(&Pro2);

             QString strpro1="/usr/bin/mkisofs -R -l -V \"OLRIC\" -v -allow-multidot $QTyr/vpn-tree/";
             strpro1.replace("$QTyr",yr);
             Pro1.start(strpro1);

             QString strpro2="create_compressed_fs - 65536 > $Qtyr/vpn-cd-tree/KNOPPIX/KNOPPIX ";
              strpro2.replace("$Qtyr",yr);
              Pro2.start(strpro2);

             QString  strpro3="mkisofs -pad -l -r -J -V \"OLRIC\" -no-emul-boot -boot-load-size 4 -boot-info-table -b boot/isolinux/isolinux.bin -c boot/isolinux/boot.cat -hide-rr-moved -o  olric.iso $Qtyr/vpn-cd-tree/";
             strpro3.replace("$QTyr",yr);
             QProcess *pro=new QProcess();
             pro->start(strpro3); 

              QProcess *cdrecord=new QProcess();
               cdrecord->setStandardErrorFile("/home/meltem/error",QIODevice:: Truncate);
              cdrecord->start("cdrecord -v  -pad -dao  speed=4 /home/meltem/olric.iso ");
                        //"cdrecord -v -isosize -pad -dao dev=ATAPI:0,1,0 speed=4 dosya_ismi.iso "
                        //" mkisofs −R /master/tree | cdrecord −v fs=6m speed=2 dev=2,0 ‐"  man dosyasında
             if (cdrecord->waitForFinished())
                  //label->setText(cdrecord->errorString()); 
                  QMessageBox::information(this, QString::fromUtf8("if\n"), cdrecord->errorString());  //readAll ??

             else   //cd takmayınca else calişio
                   // label->setText(cdrecord->readAllStandardOutput());
                    QMessageBox::information(this, QString::fromUtf8("else\n"), cdrecord->readAllStandardOutput());  //readAll ??


                  QMessageBox::information(this, QString::fromUtf8("bilgilendrir\n"), cdrecord->errorString());  //readAll ??
        }
 };
