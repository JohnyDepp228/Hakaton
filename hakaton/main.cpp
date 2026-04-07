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
    QSettings settings("PLANTGUARD","AIHELPER");
    bool reg = false;
    reg = settings.value("Reg").toBool();
    QWidget *window = nullptr;
    if(!reg){
        window = new login;
        window->show();
    }
    else   {
        QString user_login = settings.value("Login").toString();
        QString user_name = settings.value("Name").toString();
        window = new MainWindow(user_login,user_name);
        window->show();
    }
    return a.exec();
}
