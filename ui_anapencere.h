/********************************************************************************
** Form generated from reading ui file 'anapencere.ui'
**
** Created: Tue Jan 13 01:09:45 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ANAPENCERE_H
#define UI_ANAPENCERE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOlric;
    QAction *actionQt;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_userName;
    QLabel *label_2;
    QLineEdit *lineEdit_passwd;
    QLabel *label_3;
    QLineEdit *lineEdit_2passwd;
    QLabel *label_4;
    QLineEdit *lineEdit_machineName;
    QLabel *label_5;
    QLineEdit *lineEdit_email;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Burn;
    QMenuBar *menubar;
    QMenu *menuHakk_nda;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(368, 315);
    actionOlric = new QAction(MainWindow);
    actionOlric->setObjectName(QString::fromUtf8("actionOlric"));
    actionOlric->setVisible(true);
    actionQt = new QAction(MainWindow);
    actionQt->setObjectName(QString::fromUtf8("actionQt"));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayout_2 = new QGridLayout(centralwidget);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    tabWidget = new QTabWidget(centralwidget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    tabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    gridLayout = new QGridLayout(tab_2);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label = new QLabel(tab_2);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 0, 0, 1, 1);

    lineEdit_userName = new QLineEdit(tab_2);
    lineEdit_userName->setObjectName(QString::fromUtf8("lineEdit_userName"));

    gridLayout->addWidget(lineEdit_userName, 0, 1, 1, 1);

    label_2 = new QLabel(tab_2);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 1, 0, 1, 1);

    lineEdit_passwd = new QLineEdit(tab_2);
    lineEdit_passwd->setObjectName(QString::fromUtf8("lineEdit_passwd"));
    lineEdit_passwd->setEchoMode(QLineEdit::Password);

    gridLayout->addWidget(lineEdit_passwd, 1, 1, 1, 1);

    label_3 = new QLabel(tab_2);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout->addWidget(label_3, 2, 0, 1, 1);

    lineEdit_2passwd = new QLineEdit(tab_2);
    lineEdit_2passwd->setObjectName(QString::fromUtf8("lineEdit_2passwd"));
    lineEdit_2passwd->setMouseTracking(true);
    lineEdit_2passwd->setEchoMode(QLineEdit::Password);

    gridLayout->addWidget(lineEdit_2passwd, 2, 1, 1, 1);

    label_4 = new QLabel(tab_2);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout->addWidget(label_4, 3, 0, 1, 1);

    lineEdit_machineName = new QLineEdit(tab_2);
    lineEdit_machineName->setObjectName(QString::fromUtf8("lineEdit_machineName"));

    gridLayout->addWidget(lineEdit_machineName, 3, 1, 1, 1);

    label_5 = new QLabel(tab_2);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    gridLayout->addWidget(label_5, 4, 0, 1, 1);

    lineEdit_email = new QLineEdit(tab_2);
    lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));

    gridLayout->addWidget(lineEdit_email, 4, 1, 1, 1);

    tabWidget->addTab(tab_2, QString());

    gridLayout_2->addWidget(tabWidget, 0, 0, 1, 2);

    horizontalSpacer = new QSpacerItem(262, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

    pushButton_Burn = new QPushButton(centralwidget);
    pushButton_Burn->setObjectName(QString::fromUtf8("pushButton_Burn"));

    gridLayout_2->addWidget(pushButton_Burn, 1, 1, 1, 1);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 368, 26));
    menuHakk_nda = new QMenu(menubar);
    menuHakk_nda->setObjectName(QString::fromUtf8("menuHakk_nda"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

#ifndef QT_NO_SHORTCUT
    label->setBuddy(lineEdit_userName);
    label_2->setBuddy(lineEdit_passwd);
    label_3->setBuddy(lineEdit_2passwd);
    label_4->setBuddy(lineEdit_machineName);
    label_5->setBuddy(lineEdit_email);
#endif // QT_NO_SHORTCUT

    QWidget::setTabOrder(tabWidget, lineEdit_userName);
    QWidget::setTabOrder(lineEdit_userName, lineEdit_passwd);
    QWidget::setTabOrder(lineEdit_passwd, lineEdit_2passwd);
    QWidget::setTabOrder(lineEdit_2passwd, lineEdit_machineName);
    QWidget::setTabOrder(lineEdit_machineName, lineEdit_email);
    QWidget::setTabOrder(lineEdit_email, pushButton_Burn);

    menubar->addAction(menuHakk_nda->menuAction());
    menuHakk_nda->addSeparator();
    menuHakk_nda->addAction(actionOlric);
    menuHakk_nda->addAction(actionQt);

    retranslateUi(MainWindow);

    tabWidget->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    actionOlric->setText(QApplication::translate("MainWindow", "olric", 0, QApplication::UnicodeUTF8));
    actionQt->setText(QApplication::translate("MainWindow", "qt", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "&Server", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("MainWindow", "User name", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainWindow", "Passwd", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("MainWindow", "Passwd again", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("MainWindow", "Machine name", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("MainWindow", "E-mail", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "&Client", 0, QApplication::UnicodeUTF8));
    pushButton_Burn->setText(QApplication::translate("MainWindow", "Burn", 0, QApplication::UnicodeUTF8));
    menuHakk_nda->setTitle(QApplication::translate("MainWindow", "about", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANAPENCERE_H
