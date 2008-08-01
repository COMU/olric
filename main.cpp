#include <QApplication>
#include <QMessageBox>

#include "AnaPencere.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AnaPencere p;
     p.show();
     return a.exec();
}   	