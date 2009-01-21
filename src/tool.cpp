#include "tool.h"

QString dosya_icerik_al( QString filename )
{

    QString inside = "";
    QFile file(filename);
    if (file.exists())
    {
       if (file.open(QFile::ReadOnly | QFile::Text))
       {
          inside =file.readAll();
          file.close();
        }
    }
    return inside;
}

bool icerik_yaz(QString fullFileName,QString veri)
{
      QString data = veri;
      QFile f( fullFileName );
      if ( f.open( QFile::WriteOnly | QFile::Text ) )
      {
         QTextStream sw( &f );
         sw << data;
         f.close();
         return true;
      }
      return false;
}
