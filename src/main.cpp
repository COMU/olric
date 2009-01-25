#include <QApplication>
#include <QTranslator>
#include <QtGui>
#include <QDebug>
#include <QProcess>



#include "AnaPencere.h"
#include "QLocale"
#include "tool.h"


QFileInfoList findPath(QString Path,QString SearchFile ){
  QDir dir(Path);

  QStringList filters;
  filters << SearchFile;
  dir.setNameFilters(filters);

  QFileInfoList list = dir.entryInfoList();
  for (int i = 0; i < list.size(); ++i) {
    QFileInfo fileInfo = list.at(i);
    qDebug()<< fileInfo.fileName();     //QString("%1").arg(fileInfo.fileName());

  }
  return list;
}


QString openvpnPath(){
   QStringList pathList;
   pathList << QDir::homePath() << "/tmp";
   for(int i=0; i<pathList.size(); ++i){
       QString path = pathList.at(i);
       QFileInfoList list = findPath(path , "openvpn*");

       for(int j=0; j<list.size();++j){
         QFileInfo fileInfo=list.at(j);
         QFileInfoList listI= findPath(path+"/"+fileInfo.fileName() ,"easy-rsa");

         for(int k=0; k<list.size();++k){
           QFileInfo fileInfoI=listI.at(k);            //root mu sahıp kontrolu yapmalımı???
           if(fileInfoI.isDir() && !fileInfoI.isRoot()) return  path+"/"+fileInfo.fileName() +"/easy-rsa";
         }
      }
   }
   return " ";
}

int main(int argv, char *args[])
{

     /*QProcess process;
     QStringList env = QProcess::systemEnvironment();
     qDebug()<<env;
     env << "TMPDIR=C:\\MyApp\\temp"<< "KEY_CONFIG=/home/meltem/Desktop/easy-rsa/2.0/openssl.cnf"<<"key_dir=melltemmmmmmm";  //<<"KEY_DIR=/home/meltem/Desktop/key"<<"KEY_SIZE=1024"; // Add an environment variable
     //env.replaceInStrings(QRegExp("^PATH=(.*)", Qt::CaseInsensitive), "PATH=\\1;C:\\Bin");

     */


     QApplication app(argv, args);

        QString locale=QLocale::system().name();
        QTranslator translator;
        translator.load(QString(":/olric_")+locale);
        app.installTranslator(&translator);

        static QString path;
        path = openvpnPath();
        if(path==" ") qDebug()<<"sistemde vpn yok kurmalı bilgilendirme ing:)";

        else{
            qDebug()<<path;

            AnaPencere p;
            p.show();
            return app.exec();
        }


}
