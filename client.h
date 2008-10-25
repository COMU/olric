 

class client
{
     public:
      QString eposta;
      QString parola;
      QString makine_adi;
      QString kullanici_adi; 

       client( QString ckullanici_adi, QString cparola, QString cmakine_adi, QString ceposta)
       {
           this->eposta=ceposta;
           this->parola=cparola;
           this->makine_adi=cmakine_adi;
           this->kullanici_adi=ckullanici_adi; 

       }
};