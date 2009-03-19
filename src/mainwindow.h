#include <QMainWindow>
#include <QProcess>
#include <QtCore/QDir>
#include <QDebug>
#include <QByteArray>

#include "ui_mainwindow.h"
#include "server.h"
#include "tool.h"
#include "about.h"

class Mainwindow:public QMainWindow, Ui::MainWindow
{
    Q_OBJECT
    
private :

    QString user_name;
    QRegExp rx_Email;
    QRegExp rx_ipv4;
    
public:
    Mainwindow();

private:

    void rdesktop();
    void buildCilentKey();
    void cpCrtToClient();
    void orderClientCnf();
    bool clientControl();

public slots:
    void aboutOlric();
    void aboutQt();
    void slotBurn();
    void slotCleanClientUI();
    void actionConfig();

};
