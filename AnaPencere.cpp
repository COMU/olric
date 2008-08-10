#include "AnaPencere.h"
    void  AnaPencere::slotburn()                 //QString cdismi  anapencere sınıfının slotburn fonk içini dolduruoz
         {
             if ( QMessageBox::question(this,QString::fromUtf8("Uyarı"), QString::fromUtf8("Girilen bilgilerle iso üretilecek."),
                       QString::fromUtf8("Devam"), QString::fromUtf8("Geri"),
			QString(), 1, 0 | QMessageBox::Default | QMessageBox::Escape) == 0)
		{

                   //proc dosyası umount 
                 //  QString cd=cdismi;   //komutta ismi yerleştirme??????????
     QString program = "/usr/bin/mkisofs";
     QStringList arguments;
     arguments << "-L" << "-R"<<"-l"<<"\"olric\""<<"-v"<<"-allow-multidot"<<"/home/meltem/vpn-tree/";
     QProcess *Process = new QProcess(this);
     Process->start(program, arguments);


              }
}