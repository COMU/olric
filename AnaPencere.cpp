#include <QtGui>
#include <QBoxLayout>

#include "AnaPencere.h"
#include "pencereclient.h"
 static const char * const listEntries[] = {
     QT_TRANSLATE_NOOP("MainWindow", "First"),
     0
 };

AnaPencere::AnaPencere():QMainWindow()
{
               actions();
               menus();
               buttongrouplayout();

               QGridLayout *mainLayout = new QGridLayout;

              iconolric=new QLabel;
              iconolric->setPixmap(QPixmap(":/icons/olric.png"));
              LangComboBox=new QComboBox();
              LangComboBox->addItem(tr("tr"));
              LangComboBox->addItem(tr("eng"));
            connect(LangComboBox, SIGNAL(currentIndexChanged(int)),this, SLOT(LanguageChooser()));

             mainLayout->addWidget(buttongroup,0,0);
             mainLayout->addWidget(iconolric,0,1);
             mainLayout->addWidget(LangComboBox,2,3/2);
 
              QWidget *widget=new QWidget;
               widget->setLayout(mainLayout);

               setCentralWidget(widget);
               setWindowTitle(tr("OpenvpnLIvecdCreator"));

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
            connect(progressDialog, SIGNAL(canceled()), this, SLOT(cancelDownload()));
            progressDialog->setWindowTitle(tr("baslıkkkkkkkk:)"));
             progressDialog->setLabelText(tr("metinnnnnn"));
            qApp->processEvents();

            QString yr= "/home/meltem" ;
             //label->setText(QString::fromUtf8("işleminiz sür...")); 

             QStringList env = QProcess::systemEnvironment();  //QProcess members
              // environment = {"PATH=/usr/bin:/usr/local/bin", "USER=greg", "HOME=/home/greg"} 
             //   QStringList home= env.filter("home");
                QString hhome=env.join("     ");
            // QMessageBox::information(this, QString::fromUtf8("system bilgisi\n"), hhome); 

             QProcess Pro1;           //  COMMAND1 |COMMANT2
             QProcess Pro2;
             Pro1.setStandardOutputProcess(&Pro2);

             QString strpro1="/usr/bin/mkisofs -R -l -V \"OLRIC\" -v -allow-multidot $QTyr/vpn-tree/";
             strpro1.replace("$QTyr",yr);
             Pro1.start(strpro1);

             QString strpro2="create_compressed_fs - 65536 > $Qtyr/vpn-cd-tree/KNOPPIX/KNOPPIX ";
              strpro2.replace("$Qtyr",yr);
              Pro2.start(strpro2);

             QString  strpro3="mkisofs -pad -l -r -J -V \"OLRIC\" -no-emul-boot -boot-load-size 4 -boot-info-table -b boot/isolinux/isolinux.bin -c boot/isolinux/boot.cat -hide-rr-moved -o  olric.iso $Qtyr/vpn-cd-tree/";
             strpro3.replace("$QTyr",yr);
             QProcess *pro=new QProcess();
             pro->start(strpro3); 

              QProcess *cdrecord=new QProcess();
               cdrecord->setStandardErrorFile("/home/meltem/error",QIODevice:: Truncate);
              cdrecord->start("cdrecord -v  -pad -dao  speed=4 /home/meltem/olric.iso ");
                        //"cdrecord -v -isosize -pad -dao dev=ATAPI:0,1,0 speed=4 dosya_ismi.iso "
                        //" mkisofs −R /master/tree | cdrecord −v fs=6m speed=2 dev=2,0 ‐"  man dosyasında
             if (cdrecord->waitForFinished())  ;
         
                  //label->setText(cdrecord->errorString()); 
     /*             QMessageBox::information(this, if (progressDialog.wasCanceled())
                     break;QString::fromUtf8("if\n"), cdrecord->errorString());  //readAll ??

             else   //cd takmayınca else calişio
                   // label->setText(cdrecord->readAllStandardOutput());
                    QMessageBox::information(this, QString::fromUtf8("else\n"), cdrecord->readAllStandardOutput());  //readAll ??


                  QMessageBox::information(this, QString::fromUtf8("bilgilendrir\n"), cdrecord->errorString());  //readAll ??
*/};

void AnaPencere::LanguageChooser()
{
        QStringList lst = getDirectoryList("qm");
        QRegExp rx((".*"+LangComboBox->currentText()));
        rx.setPatternSyntax(QRegExp::Wildcard);

        for (int i = 0; i < lst.size(); ++i) {
             if(rx.exactMatch(lst[i])){
                newtranslator(lst[i]);

                QMessageBox::information(this, QString::fromUtf8("bilgilendrir\n"),qmFiles[i]);
             }

};

 void AnaPencere::newtranslator(const QString &qmFile)
{
         static QTranslator* translator = NULL;
         QString langFile;
         langFile = "qt_" + LangComboBox->currentText + ".qm";
        if (translator!=NULL) {
            App->removeTranslator(translator);
            delete  translator;
        }
        translator = new QTranslator(0);
        if (translator->load(langFile,(*qmFile))) {
            App->installTranslator(translator);

            }
};


QStringList AnaPencere::getDirectoryList(const QString& subDirectory) {
    RS_StringList dirList;

#ifdef __APPLE__

    if (subDirectory!="library") {
#endif
        //local (application) directory has priority over other dirs:
        if (!appDir.isEmpty() && appDir!="/" && appDir!=getHomeDir()) {
            dirList.append(appDir + "/" + subDirectory);
        }

        // Redhat style:
        dirList.append("/usr/share/" + appDirName + "/" + subDirectory);

        // SuSE style:
        dirList.append("/usr/X11R6/" + appDirName + "/" + subDirectory);

        dirList.append("/usr/X11R6/share/" + appDirName + "/" + subDirectory);
        dirList.append(getHomeDir() + "/." + appDirName + "/" + subDirectory);

#ifdef __APPLE__

    }
#endif

#ifdef __APPLE__
    // Mac OS X - don't scan for library since this might lead us into the
    //  wrong directory tree:
    if (!appDir.isEmpty() && appDir!="/" /*&& subDirectory!="library"*/) {
        dirList.append(appDir + "/../Resources/" + subDirectory);
        dirList.append(appDir + "/../../../" + subDirectory);
    }
#endif

    // Individual directories:
    RS_SETTINGS->beginGroup("/Paths");
    if (subDirectory=="fonts") {
        dirList += RS_StringList::split(RS_RegExp("[;]"),
                                        RS_SETTINGS->readEntry("/Fonts", ""));
    } else if (subDirectory=="patterns") {
        dirList += RS_StringList::split(RS_RegExp("[;]"),
                                        RS_SETTINGS->readEntry("/Patterns", ""));
    } else if (subDirectory.startsWith("scripts")) {
        dirList += RS_StringList::split(RS_RegExp("[;]"),
                                        RS_SETTINGS->readEntry("/Scripts", ""));
    } else if (subDirectory.startsWith("library")) {
        dirList += RS_StringList::split(RS_RegExp("[;]"),
                                        RS_SETTINGS->readEntry("/Library", ""));
    } else if (subDirectory.startsWith("po")) {
        dirList += RS_StringList::split(RS_RegExp("[;]"),
                                        RS_SETTINGS->readEntry("/Translations", ""));
    }
    RS_SETTINGS->endGroup();

    RS_StringList ret;

    RS_DEBUG->print("RS_System::getDirectoryList: Paths:");
    for (RS_StringList::Iterator it = dirList.begin();
            it!=dirList.end(); ++it ) {

        if (RS_FileInfo(*it).isDir()) {
            ret += (*it);
            RS_DEBUG->print(*it);
        }
    }

    return ret;
}



