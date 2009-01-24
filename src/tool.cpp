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

QFileInfoList findFile(QString Path,QString SearchFile ){
  QDir dir(Path);

  QStringList filters;
  filters << SearchFile;
  dir.setNameFilters(filters);

  QFileInfoList list = dir.entryInfoList();
  for (int i = 0; i < list.size(); ++i) {
    QFileInfo fileInfo = list.at(i);
    qDebug()<< fileInfo.fileName();     //QString("%1").arg(fileInfo.fileName());

  }
  return list;
}
