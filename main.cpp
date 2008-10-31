#include <QApplication>
#include <QTranslator>
#include <QtGui>
#include "AnaPencere.h"


int main(int argv, char *args[])
{
        QApplication app(argv, args);

         QString locale = QLocale::system().name();
         QString qtdir = QLibraryInfo::location(QLibraryInfo::TranslationsPath);

         QTranslator translator;
       //  translator.load(QString("olric_") + locale);
         translator.load("olric_"+locale , qtdir);
         app.installTranslator(&translator);

         QString appdir   = app.applicationDirPath();
         QString filename = QString("olric_") + locale;

         if(!translator.load(filename, appdir + "/translations/"))
	 translator.load(filename, appdir + "/../share/olric/translations/");
         app.installTranslator(&translator);

         AnaPencere p;
          p.setGeometry(100,100,800,500);
          p.show();

         return app.exec();

}