#include <QApplication>
#include <QTranslator>
#include <QtGui>
#include <QDebug>
#include <QProcess>



#include "AnaPencere.h"
#include "QLocale"
#include "tool.h"

int main(int argv, char *args[])
{


     /*QProcess process;
     QStringList env = QProcess::systemEnvironment();
     qDebug()<<env;
     env << "TMPDIR=C:\\MyApp\\temp"<< "KEY_CONFIG=/home/meltem/Desktop/easy-rsa/2.0/openssl.cnf"<<"key_dir=melltemmmmmmm";  //<<"KEY_DIR=/home/meltem/Desktop/key"<<"KEY_SIZE=1024"; // Add an environment variable
     //env.replaceInStrings(QRegExp("^PATH=(.*)", Qt::CaseInsensitive), "PATH=\\1;C:\\Bin");

     process.setEnvironment(env);
     process.setProcessChannelMode(QProcess::MergedChannels);
     process.start("mkdir /home/meltem/Desktop/");
     QStringList env1 = QProcess::systemEnvironment();
     qDebug()<<"sonnnnnnn \n"<<env1;
        */

  // QStringList QDir::searchPaths ( const QString & prefix )


   
/*#include <QTextStream>
#include <QDir>


int main()
{
  QTextStream out(stdout);
  QDir dir;

  QStringList filters;
  filters << "*.c" << "*.c~";
  dir.setNameFilters(filters);

  QFileInfoList list = dir.entryInfoList();

  for (int i = 0; i < list.size(); ++i) {
    QFileInfo fileInfo = list.at(i);
    out << QString("%1").arg(fileInfo.fileName());
    out << endl;
  } 
}

       /*QProcess process;
       process.start("find /home/meltem -name *easy-rsa");

          if (!process.waitForFinished())   qDebug() << "Make failed3:" << process.errorString();
          else                              qDebug() << "Make output3:" << process.readAll();
*/

   QStringList pathList;
   pathList << "/home/meltem"<< "tmp";
   for(int i=0; i<pathList.size(); ++i){
       QString path = pathList.at(i);
       QFileInfoList list = findFile(path , "openvpn*");

       for(int j=0; j<list.size();++j){
         QFileInfo fileInfo=list.at(j);
         qDebug()<<"------------"<<path+fileInfo.fileName();
         findFile(path+"/"+fileInfo.fileName() ,"easy-rsa");
       }
   }

   QDir dir("/home/meltem/openvpn-2.0.9");

  QStringList filters;
  filters << "easy-rsa";
  dir.setNameFilters(filters);

  QFileInfoList list = dir.entryInfoList();
  for (int i = 0; i < list.size(); ++i) {
    QFileInfo fileInfo = list.at(i);
    qDebug()<< fileInfo.fileName();     //QString("%1").arg(fileInfo.fileName());

  }


   QApplication app(argv, args);

        QString locale=QLocale::system().name();
        QTranslator translator;
        translator.load(QString(":/olric_")+locale);
        app.installTranslator(&translator);

        AnaPencere p;
        p.show();
        return app.exec();

}
