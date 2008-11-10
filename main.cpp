#include <QApplication>
#include <QTranslator>
#include <QtGui>
#include "AnaPencere.h"


int main(int argv, char *args[])
{
        QApplication app(argv, args);

        AnaPencere p;
        p.setGeometry(100,100,800,500);
        p.show();

        return app.exec();

}