#include <QMessageBox>
#include <QDialog>
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

   public slots:
   void slotnesneclient()
   {
       client c(lineemail->text(),lineparola->text(),linemakina_adi->text(),linekullanici_adi->text());

     if(c.email==" " || c.parola==" "|| c.makina_adi==" " || c.kullanici_adi==" ")
      { 
       QMessageBox::critical(this, QString::fromUtf8("Eksik Bilgi"), QString::fromUtf8("lütfen bilgileri kontrol ediniz."));
          return;
      }
   }
};