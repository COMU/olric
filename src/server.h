#include <QProcess>
#include <QtCore/QDir>
#include <QDebug>
#include <QByteArray>

#include "ui_config.h"
#include "tool.h"

class Server : public QDialog, private Ui::config_server
{
    Q_OBJECT

private :

    QRegExp rx_Email;
    QRegExp rx_ipv4;

public:
    Server(QWidget *parent);

private:
    bool serverControl();
    void cleanAll();
    void buildCertificateAuthority();
    void buildDHParam();
    void buildKeyServer();
    void serverConf();
    void writeVariablesToXml();

public slots:
    void slotBurn();

};
