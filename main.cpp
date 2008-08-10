#include <QApplication>


#include "AnaPencere.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AnaPencere *p=new AnaPencere;
    p->show();
    return a.exec();
}   	