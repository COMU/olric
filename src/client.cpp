#include "client.h"

client::client(QString username, QString passwd, QString machine_name, QString email, QString unit_name, QString company_name,QString server_ip)
{
    this->user_name = username;
    this->password = passwd;
    this->machine_name = machine_name;
    this->email = email;
    this->unit_name = unit_name;
    this->company_name = company_name;
    this->server_ip = server_ip; 
}


void client::rdesktop()
{
    QString rdesktop = "/usr/bin/rdesktop -u " + user_name + "  " + machine_name + " " ;

    QString content = getFileContent( getVpnTreePath()+"/vpn-tree/etc/skel/.xinitrc");

    int first = content.indexOf("/usr/bin/rdesktop");
    content.replace( first , content.indexOf("&",first)-first ,rdesktop);

    writeContent( getVpnTreePath() + "/vpn-tree/etc/skel/.xinitrc", content );
}

void client::buildCilentKey()
{    
    QByteArray byt_arry="\n\n\n\n";
    byt_arry.append(unit_name);
    byt_arry.append("\n");
    byt_arry.append(user_name);
    byt_arry.append("\n\n");
    byt_arry.append(password);
    byt_arry.append("\n");
    byt_arry.append(company_name);
    byt_arry.append("\n");

    QString str = "openssl req -days 3650 -nodes -new -keyout " + user_name + ".key -out " + user_name + ".csr -config openssl.cnf";

    QProcess process1;
    process1.setWorkingDirectory(getOpenVPNPath());
    process1.start(str);
    process1.write(byt_arry);

    if (!process1.waitForFinished())
        qDebug() << "Make failed:" << process1.errorString();
    else
        qDebug() << "Output  :build client" << process1.readAll();

    str = "openssl ca -days 3650 -out " + user_name + ".crt -in " + user_name + ".csr -config openssl.cnf";

    process1.start(str);
    process1.write("y\ny\n");

    if (!process1.waitForFinished())
        qDebug() << "Make failed:" << process1.errorString();
    else
        qDebug() << "Output : II  client.crt olusturuldu" << process1.readAll();

    str="chmod 0600 " + user_name + ".key";

    process1.start(str);

    if (!process1.waitForFinished())
        qDebug() << "Make failed: chmod client" << process1.errorString();
    else
        qDebug() << "Make output: chmod client" << process1.readAll();
}

void client::cpCrtToClient()
{    


    QDir dir( getVpnTreePath() + "/vpn-tree/etc/openvpn/keys" );

    QFileInfoList fileInfoList = dir.entryInfoList();

    for(int j=0 ; j<fileInfoList.size() ; ++j)
    {
        QFileInfo fileInfo = fileInfoList.at(j);
        dir.remove( fileInfo.fileName());
    }


    QProcess process2;
    QString str;

    str = "cp " + getOpenVPNPath() + "/ca.crt  "+ getVpnTreePath() +"/vpn-tree/etc/openvpn/keys";
    process2.start(str);

    if (!process2.waitForFinished())
        qDebug() << "failed:cpCA" << process2.errorString();
    else
        qDebug() << "output:cp" << process2.readAll();

    str = "cp " + getOpenVPNPath() + "/" + user_name + ".crt  "+ getVpnTreePath() +"/vpn-tree/etc/openvpn/keys";
    process2.start(str);

    if (!process2.waitForFinished())
        qDebug() << "failed:cpclientCRT" << process2.errorString();
    else
        qDebug() << "output:cp" << process2.readAll();

    str = "cp " + getOpenVPNPath() + "/" + user_name + ".key  "+ getVpnTreePath() +"/vpn-tree/etc/openvpn/keys";
    process2.start(str);

    if (!process2.waitForFinished())
        qDebug() << "failed:cpclientKEY" << process2.errorString();
    else
        qDebug() << "output:cp" << process2.readAll();

}

void client::orderClientCnf()
{
    QString inside = "client \ndev tun \nproto tcp \nremote "
                     + server_ip + " 1194 \nresolv-retry infinite \nnobind \nuser nobody \ngroup nogroup \npersist-key \npersist-tun \nca /etc/openvpn/keys/ca.crt \ncert /etc/openvpn/keys/"
                     + user_name + ".crt \nkey /etc/openvpn/keys/"
                     + user_name + ".key \nns-cert-type server \ncomp-lzo \nverb 3 \nmute 20 \n#auth-retry interact";

    writeContent( getVpnTreePath() + "/vpn-tree/etc/openvpn/client.cnf",inside);
}

void client::run()
{
    rdesktop();
    buildCilentKey();
    orderClientCnf();
    cpCrtToClient();
}
