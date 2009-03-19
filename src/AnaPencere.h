#include <QMainWindow>
#include <QProcess>
#include <QtCore/QDir>
#include <QDebug>
#include <QByteArray>

#include "ui_anapencere.h"
#include "client.h"
#include "tool.h"
#include "about.h"

class AnaPencere:public QMainWindow, Ui::MainWindow
{
    Q_OBJECT
    
private :
    bool server_exist;
    QRegExp rx_Email;
    QRegExp rx_ipv4;
    
public:
    AnaPencere();   

private:
    bool serverControl();
    bool clientControl();
    bool whoIAm();    
    void WriteRoute();
    void cleanAll();
    void buildCertificateAuthority();
    void buildDHParam();
    void buildKeyServer();
    void burn();

public slots:
    void aboutOlric();
    void aboutQt();
    void slotBurn();
    void slotCleanClientUI();

};
