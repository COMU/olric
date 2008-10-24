#include <QtGui>
#include <QBoxLayout>

#include "AnaPencere.h"
#include "burn.h"
#include "pencereclient.h"

AnaPencere::AnaPencere():QMainWindow()
{
               actions();
               menus();
               buttongrouplayout();

               QHBoxLayout *mainLayout = new QHBoxLayout;
     //       const QString filename=":/yeni/icons/olpic.png";
     //       const QPixmap pixmap=new QPixmap(filename);
      //         lpixmap=new QLabel;
        //       lpixmap->setPixmap(pixmap);
              iconolric=new QLabel;
              iconolric->setPixmap(QPixmap(":/yeni/icons/olpic.png"));

               mainLayout->addWidget(buttongroup);
               mainLayout->addWidget(iconolric);

               QWidget *widget=new QWidget;
               widget->setLayout(mainLayout);

               setCentralWidget(widget);
               setWindowTitle(tr("OpenvpnLIvecdCreator"));

};
void AnaPencere::buttongrouplayout()
{
          buttongroup=new QGroupBox;
          QGridLayout *layout = new QGridLayout;
         // QVBoxLayout *layout=new QVBoxLayout;

         serverbutton = new QPushButton(tr("&Sunucu"));
         serverbutton->setDefault(true);

         clientbutton = new QPushButton(tr("&Istemci"));
         burnbutton = new QPushButton(tr("&Burn"));

         connect(burnbutton, SIGNAL(clicked()), this, SLOT(slotburn()));
         connect(clientbutton, SIGNAL(clicked()), this, SLOT(slotclient())); 

          layout->addWidget(serverbutton,1,0);
          layout->addWidget(clientbutton,2,0);
          layout->addWidget(burnbutton,3,0);

          //layout->setColumnStretch(1, 10);
        //  layout->setColumnStretch(2, 20);

           buttongroup->setLayout(layout);
};

void  AnaPencere::slotburn()
{
     burn  *b=new burn(this);
     b->setGeometry(70,70,500,190); 
     b->exec();
  };

void  AnaPencere::slotclient()
{
       pencereclient  *c= new pencereclient(this);
       c->setGeometry(80,80,750,250);
       c->exec();
 };

 void AnaPencere::about()
 {
     QMessageBox::about(this, tr("Hakkinda OLRIC"),
             tr("The <b>OLRIC</b> how to "
                "bhhgghgj."));
 };

void  AnaPencere::actions()
{
      cikisAct = new QAction(tr("Ç&ik"), this);
      cikisAct->setShortcut(tr("Ctrl+Q", "Quit"));
      connect(cikisAct, SIGNAL(triggered()), this, SLOT(close()));

      aboutolric = new QAction(tr("&Hakkinda"), this);
      connect(aboutolric, SIGNAL(triggered()), this, SLOT(about()));

     aboutQtAct = new QAction(tr("&Qt Hakkinda"), this);
     connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
};

void AnaPencere::menus()
{
          helpMenu = new QMenu(tr("&Yardim"),this);
          helpMenu->addAction(aboutolric);
          helpMenu->addAction(aboutQtAct);
           helpMenu->addSeparator();
           helpMenu->addAction(cikisAct);

         menuBar()->addMenu(helpMenu);
};
