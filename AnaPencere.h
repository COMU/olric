#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>  //ayar dosyasına ulasmak için (home altında rc)
#include <QLabel>
#include <qprocess.h>

#include "ui_AnaPencere.h"

class AnaPencere:public QMainWindow, Ui::MainWindow     //anapencereqMainwindowdan turemiş mainwindowadlıformuyuklenmıs
{
	Q_OBJECT
	public:

	AnaPencere():QMainWindow()       //yapıcı
	{

		setupUi(this);
                setWindowTitle("OLRIC");
	        connect(buttonBURN, SIGNAL(clicked()), this, SLOT(slotburn()));   //linecdismi->text()
                
        }

        public slots:
              void slotburn();
     
         
};			