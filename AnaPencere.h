#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>  //ayar dosyasına ulasmak için (home altında rc)
#include <QLabel>
#include <QtCore/QDebug>
#include <QtCore/QProcess>
#include <QtCore/QDir>


#include "ui_AnaPencere.h"

class AnaPencere:public QMainWindow, Ui::MainWindow     //anapencereqMainwindowdan turemiş mainwindowadlıformuyuklenmıs
{
	Q_OBJECT
	public:

	AnaPencere():QMainWindow()       //yapıcı
	{

		setupUi(this);
                setWindowTitle("OpenvpnLeCreator");
	        connect(buttonBURN, SIGNAL(clicked()), this, SLOT(slotburn()));
                connect(buttonclient, SIGNAL(clicked()), this, SLOT(slotclient()));
 
        }

        public slots:
              void slotburn();
              void slotclient();

};			