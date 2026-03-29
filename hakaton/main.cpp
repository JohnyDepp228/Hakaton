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
    // login l;
    // l.show();
    // FileIcon f;
    // f.show();
    // hidemenu h;
    // h.show();
    // Menu m;
    // m.show();
    // minimenu mm;
    // mm.show();
    // reg r;   //цвет не задний не тот
    // r.show();
    // sidemenu s;
    // s.show();
    MainWindow w;
    w.show();
    return a.exec();
}
