#include "client.h"

client::client(QString username, QString passwd, QString machineName, QString eposta, QString UnitName, QString CompanyName)
{
     this->userName=username;
     this->passwd=passwd;
     this->machineName=machineName;
     this->eposta=eposta;
     this->UnitName=UnitName;
     this->CompanyName=CompanyName;

};

void client::rdesktop()
{
       QString rdesktop="/usr/bin/rdesktop -u "+userName+"  "+machineName +" " ;
       QString inside=dosya_icerik_al("home/meltem/Olric/.xinitrc");
       int first = inside.indexOf("/usr/bin/rdesktop");
       inside.replace( first , inside.indexOf("&",first)-first ,rdesktop);
       icerik_yaz("home/meltem/Olric/.xinitrc", inside);
};

void client::buildCilentKey()
{
       QString KeyConfig="/home/meltem/openvpn-2.0.9/easy-rsa/openssl.cnf";
       QString KeyDir="/home/meltem/openvpn-2.0.9/easy-rsa/keys";

       QProcess process;
       process.setWorkingDirectory(KeyDir);
       QString str="openssl req -days 3650 -nodes -new -keyout "+userName+".key -out "+userName+".csr -config "+KeyConfig;
       QByteArray bytArr="\n\n\n\n"; bytArr.append(UnitName); bytArr.append("\n");
         bytArr.append(userName); bytArr.append("\n\n");
         bytArr.append(passwd); bytArr.append("\n");
         bytArr.append(CompanyName); bytArr.append("\n");

       process.start(str);
       process.write(bytArr);

       if (!process.waitForFinished())   qDebug() << "Make failed:" << process.errorString();
       else   qDebug() << "Ikısım client" << process.readAll();

       str= "openssl ca -days 3650 -out "+userName+".crt -in "+userName+".csr -config "+KeyConfig;
       process.start(str);
       process.write("y\ny\n");

       if (!process.waitForFinished())   qDebug() << "Make failed:" << process.errorString();
       else   qDebug() << "IIkısım client olusturuldu" << process.readAll();


}

void client::run()
{
         rdesktop();
         buildCilentKey();
}
