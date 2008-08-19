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
               
      /* bool dosyaya_yazma(QString FileName,QString knm,QString giris)
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
                                                                          //iki  farklı yoldan  ulastıgında konumlanma aynı yer
        bool dosyaac_yaz(char* FileName,QString knm,QString giris) //tek  Qtextstream ile de sona yazıo???????????????
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
      

           
         bool dosyaac_yaz(char* file,char* knm,char* giris,int boyut)
          {
                char* konum=knm;
                char*  veri= giris;
                char* buf=(char*)malloc(boyut*sizeof(char)); 
                //  int counter=0;
                FILE* f=fopen(file,"a+t");
                if(!f)QMessageBox::information(this,QString::fromUtf8("bilgilendrir\n"), QString::fromUtf8("dosya acılamıo")) ;
                while(!feof(f)){ 
                   //  fseek(f,counter*1024,0);
                  //   counter++;
                      fgets(buf,boyut,f);
                      QMessageBox::information(this,QString::fromUtf8("bilgilendrir\n"),QString:: fromLatin1(buf)) ; 
                      if(strncmp(konum,buf,boyut)==0) {
                                QMessageBox::information(this,QString::fromUtf8("bilgilendrir\n"),QString:: fromLatin1(buf)) ;      //rdesktop buluo 
                                fputs(veri,f);              //dosya sonuna yazıo???????????
                                 return true;
                                   } 
                        }
                  return false;
           }  
	
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
         char* ddosya="/home/meltem/dosya";
         QStringList rdesk;
          rdesk.clear();
          rdesk.append("");
          rdesk.append("-u");
          rdesk.append(c.kullanici_adi);
          rdesk.append(c.makina_adi);
         QString rdesktop=QString(rdesk.join(" "));
         char*  rrdesktop="meltemmmm";
       // dosyaac_yaz(ddosya,"rdesktop",rdesktop);
          dosyaac_yaz(ddosya,"rdesktop",rrdesktop,9);
      
       /* QFile file(dosya);  //  	rdesktop    -u     c d    d c binary dosya
         file.open(QIODevice::WriteOnly  | QIODevice::Text); 
         QDataStream out(&file);
             out<<"rdesktop"<<"-u"<<c.kullanici_adi<<c.makina_adi; rdesk.append("-u");
       */

 
      temizle(); 
      accept();  //bilgileri sıfırlıo yeni giriiler için 
     }
};

