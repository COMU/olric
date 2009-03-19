#include <QDialog>
#include "ui_about.h"

class About:public QDialog,Ui::Dialog_about
{
        Q_OBJECT
        public:

        About(QWidget *parent):QDialog(parent)
        {
                setupUi(this);
                connect(pushButton_close, SIGNAL(clicked()), this, SLOT(close()));
        }

};

