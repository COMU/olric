#include "AnaPencere.h"
    void  AnaPencere::slotburn()                 //QString cdismi  anapencere sınıfının slotburn fonk içini dolduruoz
         {
             if ( QMessageBox::question(this,QString::fromUtf8("Uyarı"), QString::fromUtf8("Girilen bilgilerle iso üretilecek."),
                       QString::fromUtf8("Devam"), QString::fromUtf8("Geri"),
			QString(), 1, 0 | QMessageBox::Default | QMessageBox::Escape) == 0)
		{

  /* QString program = "/usr/bin/mkisofs";
     StringList arguments;
     arguments << "-R" << "-l"<<"-V"<<"\"OLRİC\""<<"-v"<<"-allow-multidot"<<"/home/meltem/vpn-tree/";

     QProcess *myProcess = new QProcess();
     myProcess->start(program, arguments);
    */

  /*    QProcess Pro1;           //  COMMAND1 |COMMANT2
             QProcess Pro2;
             Pro1.setStandardOutputProcess(&Pro2);

            Pro1.start("/usr/bin/mkisofs -R -l -V \"OLRİC\" -v -allow-multidot /home/meltem/vpn-tree/");
            Pro2.start("create_compressed_fs - 65536 > /home/meltem/vpn-cd-tree/KNOPPIX/KNOPPIX ");
      */
                                                    //PAREMATREDEN ONCE  SLASH KOYARAK da DENEDİM 
            /* QProcess *pro=new QProcess();       //SHELL KOMUTU DİREK YAZIMI 
             pro->start("mkisofs -pad -l -r -J -V \"OLRİC\" -no-emul-boot -boot-load-size 4 -boot-info-table -b boot/isolinux/isolinux.bin -c boot/isolinux/boot.cat -hide-rr-moved -o yourvpn.iso /home/meltem/vpn-cd-tree/"); 
          */ 

        QProcess process;          //klasor olusmadı state hata yok 
         process.start("mkdir \"/home/meltem/pelit\"");  


  /*       QProcess gzip;         //ornekler calişmıo????????? fonk donusu bool yapılıp denendi 
     gzip.start("gzip", QStringList() << "-c");
     if (!gzip.waitForStarted())
         return ;

     gzip.write("Qt rocks!");
     gzip.closeWriteChannel();

     if (!gzip.waitForFinished())
           qDebug() << "Make failed:" << gzip.errorString();
     else
           qDebug() << "Make output:" << gzip.readAll();
*/
          if (process.state() !=QProcess::Running){
            QMessageBox::information(this, process.errorString(), QString::fromUtf8("komut kosulanadı\n"));
                     }

                  }

           }
