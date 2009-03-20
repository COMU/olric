#ifndef TOOL_H
#define TOOL_H

#include <stdio.h>
#include <stdlib.h>
#include <QtCore/QString>
#include <QTextStream>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNodeList>
#include <QDomElement>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QDebug>
#include <QDir>
#include <QFileInfo>


using namespace std;


 static QString openvpn_path;
 static QString vpn_tree_path;
 static QString rdesktop_path;
 static QString server_ip;
 static bool certifica_exist;

 static QStringList search_path_list;


 QString getFileContent( QString file_name );
 bool writeContent(QString file_name,QString content);

 //QString findOpenVPNPath();
 //QFileInfoList findFilePath(QString Path,QString SearchFile );

 QString getOpenVPNPath();
 QString getVpnTreePath();
 QString getRDesktopPath();
 QString getServerIp();
 bool getCertificaExist();
 

 void setOpenVPNPath(QString);
 void setVpnTreePath(QString);
 void setRDesktopPath(QString);
 void setServerIp(QString);
 void setCertificaExist(bool);

 void setOpenVPNPath();
 bool setVariable();

#endif // TOOL_H
