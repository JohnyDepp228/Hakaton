#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QString str,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    ui->email_text->setText(str);
    setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
}

Menu::~Menu()
{
    delete ui;
}



void Menu::on_close_clicked()
{
    hide();
}


void Menu::on_quit_acc_clicked()
{
    hide();
}




