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


    QFile file("/home/meltem/olric/serial");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out<<"01";

    QFile file1("/home/meltem/olric/src/readme");
    QFile::copy("/home/meltem/olric/README" ,"/home/meltem/olric/src/readme");



    int s = QFile::FileError();
    qDebug()<<s;

    if ( setVariable() )
    {
        AnaPencere p;
        p.show();
        return app.exec();
    }

}
