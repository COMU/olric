#include <QApplication>
#include <QTranslator>
#include <QtGui>
#include "AnaPencere.h"


int main(int argv, char *args[])
{
        QApplication app(argv, args);

         QString locale = QLocale::system().name();

         QTranslator translator;
       //  translator.load(QString("olric_") + locale);
         translator.load("olric_en");
         app.installTranslator(&translator);

          AnaPencere p;
          p.setGeometry(100,100,800,500);
          p.show();

           return app.exec();

}