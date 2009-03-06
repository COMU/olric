#include <QApplication>
#include <QTranslator>
#include <QtGui>
#include <QDebug>
#include <QProcess>
#include "AnaPencere.h"
#include "QLocale"


int main(int argv, char *args[])
{
    QApplication app(argv, args);
    QString locale=QLocale::system().name();
    QTranslator translator;

    translator.load(QString(":/olric_")+locale);
    app.installTranslator(&translator);


   /* QFile file("/home/meltem/olric/serial");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out<<"01";

    QFile file1("/home/meltem/olric/src/readme");
    QFile::copy("/home/meltem/olric/README" ,"/home/meltem/olric/src/readme");


   QDir dir("/home/meltem/openvpn-2.0.9/easy-rsa/keys");

    QFileInfoList fileInfoList = dir.entryInfoList();

    for(int j=0 ; j<fileInfoList.size() ; ++j)
    {
        QFileInfo fileInfo = fileInfoList.at(j);
        dir.remove( fileInfo.fileName());
    }*/


    if ( setVariable() )
    {
        AnaPencere p;
        p.show();
        return app.exec();
    }

}
