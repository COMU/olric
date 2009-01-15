#include <QApplication>
#include <QTranslator>
#include <QtGui>
#include "AnaPencere.h"
#include "QLocale"

#include <QDebug>
#include <QProcess>

int main(int argv, char *args[])
{


     QProcess process;
     QStringList env = QProcess::systemEnvironment();
     qDebug()<<env;
     env << "TMPDIR=C:\\MyApp\\temp"<< "KEY_CONFIG=/home/meltem/Desktop/easy-rsa/2.0/openssl.cnf";  //<<"KEY_DIR=/home/meltem/Desktop/key"<<"KEY_SIZE=1024"; // Add an environment variable
     //env.replaceInStrings(QRegExp("^PATH=(.*)", Qt::CaseInsensitive), "PATH=\\1;C:\\Bin");

     process.setEnvironment(env);
     process.setProcessChannelMode(QProcess::MergedChannels);
     process.start("app");
     QStringList env1 = QProcess::systemEnvironment();
     qDebug()<<"sonnnnnnn \n"<<env1;


       if (!process.waitForFinished())   qDebug() << "Make failed3:" << process.errorString();
       else                             qDebug() << "Make output3:" << process.readAll();

        QApplication app(argv, args);

        QString locale=QLocale::system().name();
        QTranslator translator;
        translator.load(QString(":/olric_")+locale);
        app.installTranslator(&translator);

        AnaPencere p;
        p.show();
        return app.exec();

}
