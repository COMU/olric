
#include <QtGui>
#include "pencereclient.h"

pencereclient::pencereclient(QWidget *parent):QDialog(parent)
{
       QLabel *label=new QLabel(tr("KULLANICI SERTIFIKASI OLUSTURULACAKTIR.GEREKLI BILGILERI GIRINIZ. "));
        QLabel *labelbos=new QLabel(tr(""));
     labelkullanici= new QLabel(tr("&KULLANICI ADI :"));
     lineKullanici_adi = new QLineEdit;
     labelkullanici->setBuddy(lineKullanici_adi);

     labelparola = new QLabel(tr("&PAROLA :"));
     lineParola = new QLineEdit;
     lineParola->setEchoMode(QLineEdit::Password);
     labelparola->setBuddy(lineParola);
 
     labelparolaTekrar = new QLabel(tr("&PAROLA &TEKRAR :"));
     lineParolaTekrar = new QLineEdit;
     lineParolaTekrar->setEchoMode(QLineEdit::Password);
     labelparolaTekrar->setBuddy(lineParolaTekrar);

     labelmakine= new QLabel(tr("&MAKINE ADI :"));
     lineMakine_adi= new QLineEdit;
     labelmakine->setBuddy(lineMakine_adi);

     labeleposta= new QLabel(tr("&E-POSTA :"));
     lineEposta = new QLineEdit;
     labeleposta->setBuddy(lineEposta);

     buttonKaydet=new QPushButton(tr("&KAYDET"));
    // buttonKaydet->setEnabled(false);
     connect(buttonKaydet, SIGNAL(clicked()), this, SLOT(slotnesneclient()));

       //GridGroupBox = new QGroupBox(this);  //(tr("grup ismi"))
       QGridLayout *layout = new QGridLayout;

      layout->addWidget(labelbos,0,0);
      layout->addWidget(label,1,1);
       layout->addWidget(labelkullanici,2,0 );
      layout->addWidget(lineKullanici_adi,2,1);
       layout->addWidget(labelparola,3,0 );
      layout->addWidget(lineParola,3,1);
      layout->addWidget(labelparolaTekrar,4,0 );
      layout->addWidget(lineParolaTekrar,4,1);
       layout->addWidget(labelmakine,6,0 );
      layout->addWidget(lineMakine_adi,6,1);
       layout->addWidget(labeleposta,7,0 );
      layout->addWidget(lineEposta,7,1);
      layout->addWidget(buttonKaydet,8,2);

      setLayout(layout); 
      setWindowTitle(tr("ISTEMCI"));

};

void pencereclient::temizle()
{
     lineKullanici_adi->clear();
     lineMakine_adi->clear();
     lineParola->clear();
     lineEposta->clear();
     lineParolaTekrar->clear(); 
};


QString pencereclient::dosya_icerik_al( QString filename )
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
};

bool pencereclient::icerik_yaz(QString fullFileName,QString veri)
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
};

void pencereclient::rdesktop_yaz(client c)
{
       QString rdesk="rdesktop ";       //rdesktop dosyaya yazılıo
       rdesk.append(" -u ");
       rdesk.append(c.kullanici_adi);
       rdesk.append(" ");
       rdesk.append(c.makine_adi);
           //  int bas;int son;

       QString inside=dosya_icerik_al("/home/meltem/necdet/odosya");
          //  bas= inside.QString::indexOf("rdesktop");
          //  son=inside.QString::indexOf("//strsonu");
          //  inside.QString::remove(bas,son-bas+9);
          //  inside.QString::insert(bas, rdesk);
       QRegExp::QRegExp  rx("[^\t] *rdesktop -u* "); 
       rx.setPatternSyntax(QRegExp::Wildcard);
       if(rx.exactMatch(inside)){
           inside.QString::replace(rx,rdesk);
           }
       else 
           inside += "\t"+rdesk+"\t";
       icerik_yaz("/home/meltem/necdet/odoya",inside);
};

void pencereclient::boot_duzenle()       //vpn-cd-tree kullanıcı olusturmussa
{
        QString inside =dosya_icerik_al("/home/meltem/necdet/ydosya");
        inside.replace("PROMPT 1", "PROMPT O");
        icerik_yaz("/home/meltem/necdet/ydosya",inside);
};

void pencereclient::slotnesneclient()
{
        if(lineParolaTekrar->text()!=lineParola->text())
         {
            QMessageBox::critical(this, QString::fromUtf8("Uyarı"), QString::fromUtf8("Parola eşlesme??"));
            return;
         }

        client  c(lineKullanici_adi->text(),lineMakine_adi->text(),lineParola->text(),lineEposta->text(),lineParolaTekrar->text());

        if(c.eposta.isEmpty() ||c.parola.isEmpty() || c.makine_adi.isEmpty() || c.kullanici_adi.isEmpty() || c.parola_tekrar.isEmpty() )
        {
            QMessageBox::critical(this, QString::fromUtf8("Eksik Bilgi"), QString::fromUtf8("lütfen bilgileri kontrol ediniz."));
            return;
        }
        rdesktop_yaz(c);

        temizle();
        accept();  //bilgileri sıfırlıo yeni giriiler için 
 };
