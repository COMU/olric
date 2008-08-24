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
 
                                                                          //iki  farklı yoldan  ulastıgında konumlanma aynı yer
      /*  bool dosyaac_yaz(char* FileName,QString knm,QString giris) //tek  Qtextstream ile de sona yazıo???????????????
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
          }*/
      /* bool dosyaac_yaz(char* file,char* knm,char* giris,int boyut)
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
                                         //fflush
                      QMessageBox::information(this,QString::fromUtf8("bilgilendrir\n"),QString:: fromLatin1(buf)) ; 
                      if(strncmp(konum,buf,boyut)==0) {
                                QMessageBox::information(this,QString::fromUtf8("bilgilendrir\n"),QString:: fromLatin1(buf)) ;      //rdesktop buluo 
                                fputs(veri,f);              //dosya sonuna yazıo???????????
                                 return true;
                                   } 
                        }
                  return false;
           }  */

              bool dosya_byte_yaz(char* oku_dosya, char* yaz_dosya,char* knm,char* giris,int boyut){  //olusturulan koppyada istedigin yere yazıo
                  char* konum=knm;
                  char*  veri= giris;
                  char* buf=(char*)malloc(boyut*sizeof(char)); 
                  FILE * oku_f=fopen(oku_dosya,"r+t");
                  FILE * yaz_f=fopen(yaz_dosya,"w+t");
                   fgets(buf,boyut,oku_f);
                   while(strncmp(konum,buf,boyut)!=0){
                      fputs(buf,yaz_f); 
                      fgets(buf,boyut,oku_f);
                       }
                   fputs(buf,yaz_f);
                   fputs(veri,yaz_f);
                   while(!feof(oku_f)) {
                       fgets(buf,boyut,oku_f);
                       fputs(buf,yaz_f); 
                     }
                  fclose(oku_f);
                  fclose(yaz_f); 
                   return true;
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
          char* ydosya="/home/meltem/ydosya";
          char* odosya="/home/meltem/odosya";
       /*  QStringList rdesk;
          rdesk.clear();
          rdesk.append("");
          rdesk.append("-u");
          rdesk.append(c.kullanici_adi);
          rdesk.append(c.makina_adi);
          QString rdeskt=QString(rdesk.join(" "));*/
          char*  rdesktop= "metin"  ;

        //  dosyaac_yaz(ddosya,"rdesktop",rrdesktop,9);
        //  dosyaac_yazma(dosya,"rdesktop",rdesktop);
          dosya_byte_yaz(odosya,ydosya,"rdesktop",rdesktop,9);  //"metni" "rdesktop" dan  sonra yazıyor
 

              temizle(); 
              accept();  //bilgileri sıfırlıo yeni giriiler için 
     }
};

