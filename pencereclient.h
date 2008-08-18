#include <QMessageBox>
#include <QDialog>
#include <QFile>
#include <QTextStream> 
#include <QDataStream>
#include <QtGlobal>

#include <iostream>
#include <fstream>

#include "client.h"
#include "ui_client.h"

class pencereclient:public QDialog, Ui::Dialogclient
{
        Q_OBJECT
	public:
         pencereclient(QWidget *parent):QDialog(parent)
	 {
             setupUi(this);
             connect(buttonkaydet, SIGNAL(clicked()), this, SLOT(slotnesneclient()));
         }
       
       void temizle()
	{
		lineemail->clear();
		lineparola->clear();
		linemakina_adi->clear();
                linekullanici_adi->clear();
         }
               
      /* bool dosyaya_yazma(QString FileName,QString knm,QString giris) //dosya icerigini silio
        {
        QString konum=knm;
        QString  veri= giris;
        QFile f( FileName );
	if ( f.open( QFile::ReadWrite | QFile::Text ) )  //append yazmıo
	{
              QTextStream out_in(&f, QIODevice::ReadWrite);
              while(!out_in.atEnd()){
                    QString line = out_in.readLine();
                     if(line==konum){ 
                         out_in << veri;
		         return true; 
                          } 
           }      }
           f.close();
	  return false;
          }*/
     
        bool dosyaac_yaz(char* FileName,QString knm,QString giris) //tek  Qtextstream ile de sona yazıo
        {
        QString konum=knm;
        QString  veri= giris;
        FILE *f = fopen(FileName, "a+t"); 
        if(!f) QMessageBox::information(this,QString::fromUtf8("bilgilendrir\n"), QString::fromUtf8("dosya acılamıo")) ;	
              QTextStream out_in(f, QIODevice::ReadWrite);
              while(!out_in.atEnd()){
                    QString line = out_in.readLine();
                     if(line==konum){                               //rdesktop buluo
                         QMessageBox::information(this, QString::fromUtf8("bilgilendrir\n"), QString::fromUtf8("rdesktop bulundu."));
                         out_in << veri;
		         return true; 
                          } 
                 }
          fclose(f);
	  return false;
          }
        
     
/*             
         QFile file("box.txt");// qint64 QIODevice::readLine ( char * data, qint64 maxSize )This function reads a line of ASCII characters from the device
          char buf[knm.size()];
          
          if (file.open(QFile::ReadOnly)) {
            char buf[1024];
             qint64 lineLength = file.readLine(buf, sizeof(buf));
             if (lineLength != -1) {
                 // the line is available in buf
             }
         }
*/	
   public slots:
   void slotnesneclient()
   {
       client c(lineemail->text(),lineparola->text(),linemakina_adi->text(),linekullanici_adi->text());

     if(c.email==QString::null || c.parola==QString::null || c.makina_adi== QString::null || c.kullanici_adi==QString::null )
      { 
       QMessageBox::critical(this, QString::fromUtf8("Eksik Bilgi"), QString::fromUtf8("lütfen bilgileri kontrol ediniz."));
          return;
      }
         QString dosya="/home/meltem/dosya";
         char* dddosya="/home/meltem/dosya";
         QStringList rdesk;
          rdesk.clear();
          rdesk.append("");
          rdesk.append("-u");
          rdesk.append(c.kullanici_adi);
          rdesk.append(c.makina_adi);
         QString rdesktop=QString(rdesk.join(" "));

          dosyaac_yaz(dddosya,"rdesktop",rdesktop);
        /* QFile file(dosya);  //  	rdesktop    -u     c d    d c binary dosya
         file.open(QIODevice::WriteOnly  | QIODevice::Text); 
         QDataStream out(&file);
             out<<"rdesktop"<<"-u"<<c.kullanici_adi<<c.makina_adi; rdesk.append("-u");
       */

 
  /*          QFile file("in.txt");
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         return;

          QTextStream in(&file);
          while (!in.atEnd()) {
          QString line = in.readLine();

         QFile file("box.txt");
         if (file.open(QFile::ReadOnly)) {
             char buf[1024];
             qint64 lineLength = file.readLine(buf, sizeof(buf));
             if (lineLength != -1) {
                 // the line is available in buf
             }
         }

     }
   
 QMessageBox::information(this, QString::fromUtf8("bilgilendrir\n"), line); 
*/

      temizle(); 
    //  accept();  //bilgileri sıfırlıo yeni giriiler için 
     }
};

