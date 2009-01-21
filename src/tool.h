#ifndef TOOL_H
#define TOOL_H

#include <stdio.h>
#include <stdlib.h>
#include <QtCore/QDir>
#include <QtCore/QString>
#include <QTextStream>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QDebug>


using namespace std;
 QString dosya_icerik_al( QString filename );
 bool icerik_yaz(QString FileName,QString veri );


#endif // TOOL_H
