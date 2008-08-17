#include <QMessageBox>
#include <QDialog>
#include <QFile>
#include <QTextStream> 
#include <QDataStream>
#include <QtGlobal>

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
               
     bool dosyaya_yazma(QString FileName,QString knm,QString giris) //dosya icerigini silio
    {
        QString konum=knm;
        QString  veri= giris;
        qint64 pos;
        QFile f( FileName );
	if ( f.open( QFile::ReadWrite | QFile::Text ) )
	{
	       QTextStream in(&f);
               while (!in.atEnd()) {
                 QString line = in.readLine();
                 if(line==konum){ 
                   pos=f.QIODevice::pos();
                    break; 
                    }
                }
                QTextStream out( &f );
                f.QIODevice::seek(pos); 
		out << veri;
		f.close();
		return true;
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
         QStringList rdesk;
          rdesk.clear();
          rdesk.append("rdesktop");
          rdesk.append("-u");
          rdesk.append(c.kullanici_adi);
          rdesk.append(c.makina_adi);
         QString rdesktop=QString(rdesk.join(" "));

          dosyaya_yazma(dosya,"rdesktop",rdesktop);
    //     dosyaya_yazma(dosya,rdesktop);

      
        /* QFile file(dosya);  //  	rdesktop    -u     c d    d c binary dosya
         file.open(QIODevice::WriteOnly  | QIODevice::Text); 
         QDataStream out(&file);
             out<<"rdesktop"<<"-u"<<c.kullanici_adi<<c.makina_adi;
  */

        // FILE *f = fopen("/home/meltem/dosya", "a+t");  //text
        // if(!f)
/*             
         QFile file("box.txt");
         if (file.open(QFile::ReadOnly)) {
             char buf[1024];
             qint64 lineLength = file.readLine(buf, sizeof(buf));
             if (lineLength != -1) {
                 // the line is available in buf
             }
         }
            
            QFile file("in.txt");
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
   

*/

      temizle(); 
      accept();  //bilgileri sıfırlıo yeni giriiler için 
     }
};

