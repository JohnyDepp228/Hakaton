#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{

    ui->setupUi(this);
    showFullScreen();
}

login::~login()
{
    delete ui;
}

void login::on_regestaration_clicked()
{
    reg *r = new reg();
    r->showFullScreen();
    r->show();
    hide();
}


void login::on_enter_clicked()
{
    if(ui->login_field->text() == "ar" && ui->password_field_2->text() == "1234"){
        ui->login_field->setStyleSheet("color: rgb(255, 255, 255); border-radius: 24; border: 2px solid rgb(103, 147, 0); padding-left: 17 px; text-align: left;");
        ui->password_field_2->setStyleSheet("color: rgb(255, 255, 255); border-radius: 24; border: 2px solid rgb(103, 147, 0); padding-left: 17 px; text-align: left;");
        MainWindow *m = new MainWindow();
        m->show();
        hide();
    }
    else{
        ui->login_field->setStyleSheet("color: rgb(255, 255, 255); border-radius: 24; border: 2px solid rgb(170, 0, 0); padding-left: 17 px; text-align: left;");
        ui->password_field_2->setStyleSheet("color: rgb(255, 255, 255); border-radius: 24; border: 2px solid rgb(170, 0, 0); padding-left: 17 px; text-align: left;");
    }
}


void login::on_forgot_password_clicked()
{
    QMessageBox::information(this,"","adada");
}

