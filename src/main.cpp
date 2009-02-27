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


    if ( setVariable() )
    {
        AnaPencere p;
        p.show();
        return app.exec();
    }

}
