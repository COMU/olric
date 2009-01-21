#ifndef CLIENT_H
#define CLIENT_H

#include <QtCore/QString>
#include <QByteArray>

#include "tool.h"

class client
{
   private:

     QString eposta;
     QString passwd;
     QString machineName;
     QString userName;
     QString UnitName;
     QString CompanyName;

   public:
     client( QString, QString, QString, QString ,QString, QString);
     void rdesktop();
     void buildCilentKey();
     void run();
};

#endif // CLIENT_H

