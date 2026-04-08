#include "mainwindow.h"
#include "login.h"
#include "fileicon.h"
#include "hidemenu.h"
#include "menu.h"
#include "minimenu.h"
#include "reg.h"
#include "sidemenu.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login l;
    l.show();
    return a.exec();
}
