#include <QMainWindow>
#include <QProcess>
#include <QtCore/QDir>
#include <QRegExp>
#include <QDebug>

#include "ui_anapencere.h"
#include "client.h"
class AnaPencere:public QMainWindow, Ui::MainWindow
{
       Q_OBJECT
       public:

             AnaPencere();


       private :
          
            static QString dosya_icerik_al( QString );
            static bool icerik_yaz(QString ,QString);

             bool line_kontrol();
             bool whoiam();
             void rdesktop(QString ,QString);
             void build_ca();
             void burn();
             void temizle();

       public slots:
             void slotburn();
};
