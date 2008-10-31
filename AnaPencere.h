//#ifndef AnaPencere_H
//#define AnaPencere_H


#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>  //ayar dosyasına ulasmak için (home altında rc)

#include <QBoxLayout>
#include <QtCore/QDebug>
#include <QtCore/QProcess>
#include <QtCore/QDir>
#include <QTranslator>
#include <QMainWindow>
#include <QTranslator>
#include <QRegExp>


class QAction;
class QMenu;
class QLabel;
class QGroupBox;
class QProgressDialog;
class QComboBox;

class AnaPencere:public QMainWindow
{
       Q_OBJECT
       public:

	     AnaPencere();

       private :

              void actions();
              void menus();
              void buttongrouplayout();


              QProgressDialog *progressDialog;
              QGroupBox *buttongroup;

              QLabel *iconolric;
              QPushButton *serverbutton;
              QPushButton *clientbutton; 
              QPushButton *burnbutton;
              QComboBox *LangComboBox;

              QMenuBar *menubar;
              QMenu *helpMenu;
              QAction *cikisAct;
              QAction *aboutolric;
              QAction *aboutQtAct;

        public slots:
              void slotburn();
              void slotclient();
              void about();

};

