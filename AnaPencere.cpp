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

             QProcess Pro1;           //  COMMAND1 |COMMANT2   iso kalıbı olusturuldu
             QProcess Pro2;
             Pro1.setStandardOutputProcess(&Pro2);

             Pro1.start("/usr/bin/mkisofs -R -l -V \"OLRIC\" -v -allow-multidot /home/vpn-tree/");
             Pro2.start("create_compressed_fs - 65536 > /home/vpn-cd-tree/KNOPPIX/KNOPPIX ");

             QProcess *pro=new QProcess();
             pro->start("mkisofs -pad -l -r -J -V \"OLRIC\" -no-emul-boot -boot-load-size 4 -boot-info-table -b boot/isolinux/isolinux.bin -c boot/isolinux/boot.cat -hide-rr-moved -o  olric.iso /home/vpn-cd-tree/"); 
                                  //konsolda caliştırınca kdecore (KAction): WARNING: KActionCollection::operator+=(): function is severely deprecated hatasını verio.masaustunde k33b acılıo cd kalıbı yaz acılıo;başlat a basınca yazıo.
              QProcess *k3b=new QProcess();
              k3b->start("k3b --image /home/olric/olric.iso");

             if (!k3b->waitForFinished())                   //????????????
                qDebug() << "Make failed:" << k3b->errorString();
             else
                qDebug() << "Make output:" << k3b->readAll();
       /*     QString pro3 = "K3b";
            QStringList arg;
            arg <<"--image" << "/home/olric/olric.iso";

           QProcess *k3b = new QProcess();
           k3b->start(pro3, arg);
        */
/*QProcess process;          
         process.start("mkdir \"/home/meltem/pelit\"");
*/

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
          /*if (process.state() !=QProcess::Running){
            QMessageBox::information(this, process.errorString(), QString::fromUtf8("komut kosulanadı\n"));
                     }*/
                  }

           }
