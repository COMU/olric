#ifndef CLIENT_H
#define CLIENT_H
 #include <QtCore/QString>
class client
{
   private:

     QString eposta;
     QString parola;
     QString makine_adi;
     QString kullanici_adi;

   public:
     client( QString, QString, QString, QString);

};

#endif // CLIENT_H
