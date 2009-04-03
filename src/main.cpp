#include <QApplication>
#include <QTranslator>
#include <QtGui>
#include <QDebug>
#include <QProcess>
#include <QRegExp>
#include <QFileInfo>
#include "QLocale"

#include "mainwindow.h"



int main(int argv, char *args[])
{
    QApplication app(argv, args);
    QString locale=QLocale::system().name();
    QTranslator translator;

    translator.load(QString(":/olric_")+locale);
    app.installTranslator(&translator);

    setVariable();


        QFileInfoList fileInfoList1 = fileExist( getOpenVPNPath()+"/keys" , "server.crt" );
        QFileInfoList fileInfoList2 = fileExist( getOpenVPNPath()+"/keys" , "ca.crt" );
        QFileInfoList fileInfoList3 = fileExist( getOpenVPNPath()+"/keys" , "dh1024.pem" );
        QFileInfoList fileInfoList4 = fileExist( getOpenVPNPath()+"/keys" , "openssl.cnf" );

        if( fileInfoList1.size() <= 0 || fileInfoList2.size() <= 0 || fileInfoList3.size() <= 0 || fileInfoList4.size() <= 0  )
            setCertificaExist(false);

        else
            setCertificaExist(true);


         qDebug()<<getOpenVPNPath()<< fileInfoList1.size()<< fileInfoList2.size() << fileInfoList3.size() << fileInfoList4.size() ;



        Mainwindow main;
        main.show();
        return app.exec();

}
