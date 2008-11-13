 

class client
{
     public:
      QString eposta;
      QString parola;
      QString makine_adi;
      QString kullanici_adi; 
      QString parola_tekrar;


       client( QString ckullanici_adi, QString cparola, QString cmakine_adi, QString ceposta,QString cParolaTekrar)
       {
           this->eposta=ceposta;
           this->parola=cparola;
           this->makine_adi=cmakine_adi;
           this->kullanici_adi=ckullanici_adi; 
           this->parola_tekrar=cParolaTekrar;
       }
};