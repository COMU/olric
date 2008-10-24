#include <QMessageBox>
//#include <QDialog>
#include <QFile>
#include <QTextStream> 
#include <QDataStream>
#include <QtGlobal>
#include <QProcess>
#include <iostream>
#include <fstream>
#include <QTranslator>
#include "client.h"
class QGroupBox;
class QLineEdit;

class pencereclient:public QDialog
{
        Q_OBJECT
	public:
         pencereclient(QWidget *parent);
         void temizle();
         QString dosya_icerik_al( QString filename );
         bool icerik_yaz(QString fullFileName,QString veri);
         void rdesktop_yaz(client c);
         void boot_duzenle();

        public slots:
         void slotnesneclient();

       private :
            QGroupBox *GridGroupBox;
           
          QLabel *labelkullanici;
          QLabel *labelmakine;
          QLabel *labelparola;
          QLabel *labeleposta;
          QLineEdit *lineKullanici_adi;
          QLineEdit *lineMakine_adi;
          QLineEdit *lineParola;
          QLineEdit *lineEposta;
          QPushButton *buttonKaydet;

};

