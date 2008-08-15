

class client
{
     public:
      QString email;
      QString parola;
      QString makina_adi;
      QString kullanici_adi; 

       client(QString cemail, QString cparola, QString cmakina_adi,
       QString ckullanici_adi)
       {
           this->email=cemail;
           this->parola=cparola;
           this->makina_adi=cmakina_adi;
           this->kullanici_adi=ckullanici_adi; 

       }
};