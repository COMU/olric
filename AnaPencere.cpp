#include "AnaPencere.h"
    void  AnaPencere::slotburn()                 //QString cdismi
         {
             if ( QMessageBox::question(this,QString::fromUtf8("Uyarı"), QString::fromUtf8("Girilen bilgilerle iso üretilecek."),
                       QString::fromUtf8("Devam"), QString::fromUtf8("Geri"),
			QString(), 1, 0 | QMessageBox::Default | QMessageBox::Escape) == 0)
		{

                   //proc dosyası umount 
                 //  QString cd=cdismi;   //komutta ismi yerleştirme????????????

             QProcess *proc1;
                      //Qprocess p;p.start("dir \"documents\"");
                   proc1 = new QProcess(this);
                    proc1->addArgument("mkisofs");
                    proc1->addArgument("-L");
                    proc1->addArgument("-R");
                    proc1->addArgument("-l");
                    proc1->addArgument("-V");
                    proc1->addArgument("\"OLRİC\"");
                    proc1->addArgument("-v");
                    proc1->addArgument("-allow-multidot");
                    proc1->addArgument("/home/meltem/vpn-tree/|");
                    proc1->addArgument("create_compressed_fs");
                    proc1->addArgument(" - 65536 > ");
                    proc1->addArgument("/home/meltem/vpn-cd-tree/KNOPPIX/KNOPPIX");
                    if(proc1->start()) 
                     {
                         QMessageBox::critical(this,"!", QString::fromUtf8("sıkıstırlmıs dosya goruntusu olusturulamadı???????????????"));
                     }
 
                       QProcess *proc2;
                         proc2= new QProcess(this);
                      proc2->addArgument("mkisofs"); 
                      proc2->addArgument("-pad"); 
                      proc2->addArgument("-l"); 
                      proc2->addArgument("-r"); 
                      proc2->addArgument("-J");
                      proc2->addArgument("-V"); 
                      proc2->addArgument("\"OLRİC \""); 
                      proc2->addArgument("-no-emul-boot");
                      proc2->addArgument("-boot-load-size"); 
                      proc2->addArgument("4"); 
                      proc2->addArgument("-boot-info-table");
                      proc2->addArgument("-b");
                      proc2->addArgument(" boot/isolinux/isolinux.bin");
                      proc2->addArgument("-c");
                      proc2->addArgument(" boot/isolinux/boot.cat"); 
                      proc2->addArgument("-hide-rr-moved");
                      proc2->addArgument("-o");
                      proc2->addArgument("yourvpn.iso ");
                      proc2->addArgument("/home/meltem/vpn-cd-tree/");
                     if(proc2->start())
                     {
                       QMessageBox::critical(this,"!", QString::fromUtf8("iso  oluruldu"));
                      } 

              }
}