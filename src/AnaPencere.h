#include <QMainWindow>
#include <QProcess>
#include <QtCore/QDir>
#include <QDebug>
#include <QByteArray>

#include "ui_anapencere.h"
#include "client.h"
#include "tool.h"

class AnaPencere:public QMainWindow, Ui::MainWindow
{
       Q_OBJECT
       public:

             AnaPencere();

       private :

             bool line_kontrol();
             bool whoiam();
             void OpensslOrder();
             void BuildServerKey();
             void WriteRoute();
             void burn();
             void temizle();

       public slots:
             void slotburn();
};
