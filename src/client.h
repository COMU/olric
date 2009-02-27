#ifndef CLIENT_H
#define CLIENT_H

#include <QtCore/QString>
#include <QByteArray>

#include "tool.h"

class client
{
   private:
     QString email;
     QString password;
     QString machine_name;
     QString user_name;
     QString unit_name;
     QString company_name;
     QString server_ip;


     void rdesktop();
     void buildCilentKey();
     void cpCrtToClient();
     void orderClientCnf();

   public:
     client( QString, QString, QString, QString ,QString, QString,QString);
     void run();



};

#endif // CLIENT_H

