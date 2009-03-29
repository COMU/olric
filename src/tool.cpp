#include "tool.h"

QString getFileContent( QString file_name )
{
    QString content = "";
    QFile file(file_name);
    if (file.exists())
    {
        if (file.open(QFile::ReadOnly | QFile::Text))
        {
            content = file.readAll();
            file.close();
        }
    }
    return content;
}


bool writeContent(QString file_Name, QString content)
{
    QString data = content;
    QFile f( file_Name );
    if ( f.open( QFile::WriteOnly | QFile::Text ) )
    {
        QTextStream sw( &f );
        sw << data;
        f.close();
        return true;
    }
    return false;
}


QFileInfoList fileExist(QString Path,QString SearchFile )
{
    QDir dir(Path);
    QStringList filters;

    filters << SearchFile;
    dir.setNameFilters(filters);

    QFileInfoList list = dir.entryInfoList();

    return list;
}




/*QString findOpenVPNPath()
{
    QStringList pathList( search_path_list );
    pathList << QDir::homePath() ;     // homepath  atama???????

    for(int i=0; i<pathList.size(); ++i)
    {
        QString path = pathList.at(i);
        QFileInfoList fileInfoList = findFilePath(path , "openvpn*");

        for(int j=0 ; j<fileInfoList.size() ; ++j)
        {
            QFileInfo fileInfo = fileInfoList.at(j);
            QFileInfoList listI = findFilePath(path + "/" + fileInfo.fileName() ,"easy-rsa");

            for(int k=0; k<fileInfoList.size() ; ++k)
            {
                QFileInfo fileInfoI = listI.at(k);            //root mu sahıp kontrolu yapmalımı???
                if(fileInfoI.isDir() && !fileInfoI.isRoot())
                    return  path+"/"+fileInfo.fileName() +"/easy-rsa";
            }
        }
    }
    return " ";
}*/


/*void setOpenVPNPath()
{
    QString temp_openvpn_path = findOpenVPNPath();

    if( temp_openvpn_path == " ")
        qDebug()<<"sistemde vpn yok kurmalı bilgilendirme ing:)";

    else
    {
        openvpn_path = temp_openvpn_path;

        QProcess process;
        process.start("rm -rf " + temp_openvpn_path + "/keys");

        if (!process.waitForFinished())
            qDebug() << "Failed :keys" << process.errorString();
        else
            qDebug() << "Output : keys silindi." << process.readAll();
    }
}
*/



bool setVariable()
{
    QDomDocument doc;
    
    QFile opmlFile( ":/olric.xml" );
    if ( !opmlFile.open( QFile::ReadOnly | QFile::Text) ) {
        return false;
    }
    if ( !doc.setContent( &opmlFile ) ) {
        opmlFile.close();
        return false;
    }
    opmlFile.close();
    
    QDomElement root = doc.documentElement();
    QDomNodeList nl = root.childNodes();
    
    for( int i=0  ;  i < nl.length() ;  i++){
        
        if (nl.at(i).nodeName() == "rdesktop_path")
            rdesktop_path =  nl.item(i).toElement().attribute( "value" );
        
        else if (nl.at(i).nodeName() == "vpn_tree_path")
            vpn_tree_path = nl.item(i).toElement().attribute( "value" );
       
        else if (nl.at(i).nodeName() == "openvpn_path")

            openvpn_path = nl.item(i).toElement().attribute( "value" )+"/easy-rsa";

        else if (nl.at(i).nodeName()=="server_ip")
            server_ip = nl.item(i).toElement().attribute( "value" );
    }
   return true;
}


void setOpenVPNPath( QString path)
{
    openvpn_path = path;
}


void setServerIp( QString ip)        //???????????????ikincide caliştirmada  silinir.Dosya ya kayıt yap yada xml yaz..........
{
    server_ip = ip;
}

void setCertificaExist( bool sexist)
{
    certifica_exist = sexist ;
}



QString getOpenVPNPath()
{
    return openvpn_path;
}

QString getVpnTreePath()
{
    return vpn_tree_path;
}

QString getRDesktopPath()
{
    return rdesktop_path;
}

QString getServerIp()
{
    return server_ip;
}

bool  getCertificaExist()
{
    return certifica_exist;
}


