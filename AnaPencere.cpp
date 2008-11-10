#include <QtGui>
#include <QBoxLayout>

#include "AnaPencere.h"
#include "pencereclient.h"


AnaPencere::AnaPencere():QMainWindow()
{
      actions();
      menus();
      buttongrouplayout();

      QGridLayout *mainLayout = new QGridLayout;

      iconolric=new QLabel;
      iconolric->setPixmap(QPixmap("/home/meltem/necdet/olric/icons/olric.png"));
      LangComboBox=new QComboBox();
      LangComboBox->addItem(tr("tr"));
      LangComboBox->addItem(tr("en"));
      connect(LangComboBox, SIGNAL(currentIndexChanged(int)),this, SLOT(LanguageChooser()));

      mainLayout->addWidget(buttongroup,0,0);
      mainLayout->addWidget(iconolric,0,1);
      mainLayout->addWidget(LangComboBox,2,3/2);
 
      QWidget *widget=new QWidget;
      widget->setLayout(mainLayout);
 
      setCentralWidget(widget);
      setWindowTitle(tr("OpenvpnLIvecdCreator"));

};

 QStringList AnaPencere::findQmFiles()
 {
     QDir dir("/home/meltem/necdet/translations");
     QStringList fileNames = dir.entryList(QStringList("*.qm"), QDir::Files,
                                           QDir::Name);
     QMutableStringListIterator i(fileNames);
     while (i.hasNext()) {
         i.next();
         i.setValue(dir.filePath(i.value()));
     }
     return fileNames;
 };

void AnaPencere::LanguageChooser()
{
        QStringList lst = findQmFiles();
        QRegExp rx((".*"+LangComboBox->currentText()));
        rx.setPatternSyntax(QRegExp::Wildcard);

        for (int i = 0; i < lst.size(); ++i) 
        {
             if(rx.exactMatch(lst[i])){
                newtranslator(lst[i]);
                }
        }
};

 void AnaPencere::newtranslator(const QString &qmFile)
{
      /*   static QTranslator* translator = NULL;
         //QString langFile;
         //langFile = "olric_" + LangComboBox->currentText + ".qm";
        if (translator!=NULL) {
            qApp->removeTranslator(translator);
            delete  translator;
        }
        translator = new QTranslator(0);
        if (translator->load(qmFile)) {
            qApp->installTranslator(translator);
          }*/
         QTranslator translator;
         translator.load(qmFile);
         qApp->installTranslator(&translator);

         AnaPencere *window = new AnaPencere;
         //window->installEventFilter(this);
         window->show();

};


void AnaPencere::buttongrouplayout()
{
     buttongroup=new QGroupBox;
     QGridLayout *layout = new QGridLayout;

     serverbutton = new QPushButton(tr("&Sunucu"));
     serverbutton->setDefault(true);

     clientbutton = new QPushButton(tr("&Istemci"));
     burnbutton = new QPushButton(tr("&Burn"));

     connect(burnbutton, SIGNAL(clicked()), this, SLOT(slotburn()));
     connect(clientbutton, SIGNAL(clicked()), this, SLOT(slotclient())); 

     layout->addWidget(serverbutton,1,0);
     layout->addWidget(clientbutton,2,0);
     layout->addWidget(burnbutton,3,0);

     buttongroup->setLayout(layout);
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

void  AnaPencere::slotburn()
{
      progressDialog = new QProgressDialog();
      progressDialog->setCancelButtonText(tr("&Cancel"));
           // connect(progressDialog, SIGNAL(canceled()), this, SLOT(cancelDownload()));
      progressDialog->setWindowTitle(tr("başlık:)"));
      progressDialog->setLabelText(tr("metinnnnnn"));
      QString yr= "/home/meltem/necdet" ;

      QStringList env = QProcess::systemEnvironment();  //QProcess members
            //environment = {"PATH=/usr/bin:/usr/local/bin", "USER=greg", "HOME=/home/greg"} 
            //QStringList home= env.filter("home");
            //QString hhome=env.join("     ");
            //QMessageBox::information(this, QString::fromUtf8("system bilgisi\n"), hhome); 

      QProcess Pro1;           //  COMMAND1 |COMMANT2
      QProcess Pro2;
      Pro1.setStandardOutputProcess(&Pro2);

      QString strpro1="/usr/bin/mkisofs -R -l -V \"OLRIC\" -v -allow-multidot yr/vpn-tree/";
      strpro1.replace(QString("yr"),yr);
      Pro1.setStandardErrorFile("/home/meltem/necdet/error",QIODevice:: Truncate);
      Pro1.start(strpro1);

      QString strpro2="create_compressed_fs - 65536 > yr/vpn-cd-tree/KNOPPIX/KNOPPIX ";
      strpro2.replace(QString("yr"),yr);
      Pro2.setStandardErrorFile("/home/meltem/necdet/error",QIODevice:: Truncate);
      Pro2.start(strpro2);

      QString  strpro3="mkisofs -pad -l -r -J -V \"OLRIC\" -no-emul-boot -boot-load-size 4 -boot-info-table -b boot/isolinux/isolinux.bin -c boot/isolinux/boot.cat -hide-rr-moved -o  olric.iso yr/vpn-cd-tree/";
      strpro3.replace(QString("yr"),yr);
      QProcess *pro=new QProcess();
      //pro->setStandardErrorFile("/home/meltem/necdet/error",QIODevice:: Truncate);
      pro->start(strpro3); 

      QProcess *cdrecord=new QProcess();
      cdrecord->start("cdrecord -v  -pad -dao  speed=4 /home/meltem/olric.iso ");
      //"cdrecord -v -isosize -pad -dao dev=ATAPI:0,1,0 speed=4 dosya_ismi.iso "
      //" mkisofs −R /master/tree | cdrecord −v fs=6m speed=2 dev=2,0 ‐"  man dosyasında
      progressDialog->exec();
      if (cdrecord->waitForFinished())
      //label->setText(cdrecord->errorString()); 
      QMessageBox::information(this, QString::fromUtf8("if\n"), cdrecord->errorString());  //readAll ??

     else   //cd takmayınca else calişio
      // label->setText(cdrecord->readAllStandardOutput());
      QMessageBox::information(this, QString::fromUtf8("else\n"), cdrecord->readAllStandardOutput());  //readAll ??


     QMessageBox::information(this, QString::fromUtf8("bilgilendrir\n"), cdrecord->errorString());  //readAll ??
};




