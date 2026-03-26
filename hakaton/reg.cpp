#include "reg.h"
#include "ui_reg.h"

reg::reg(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::reg)
{
    ui->setupUi(this);
    showFullScreen();
}

reg::~reg()
{
    delete ui;
}


void reg::on_reg_buttom_clicked()
{
    if(ui->password_field_2->text().isEmpty() || ui->password_confirm->text().isEmpty()){
        ui->password_confirm->setStyleSheet("color: rgb(255, 255, 255);border-radius: 24;border: 2px solid rgb(170, 0, 0);padding-left: 17 px; text-align: left; ");
        ui->password_field_2->setStyleSheet("color: rgb(255, 255, 255);border-radius: 24;border: 2px solid rgb(170, 0, 0);padding-left: 17 px; text-align: left; ");
    }
    else{
        if(ui->password_field_2->text() == ui->password_confirm->text())
        {
        ui->password_confirm->setStyleSheet("color: rgb(255, 255, 255);border-radius: 24;border: 2px solid rgb(103, 147, 0);padding-left: 17 px; text-align: left; ");
            if(!ui->code->text().isEmpty()){
                if(ui->code->text() == code){
                ui->code->setStyleSheet("color: rgb(255, 255, 255);border-radius: 24;border: 2px solid rgb(103, 147, 0); padding-left: 17 px; text-align: left;");
                hide();
                }
                else{
                ui->code->setStyleSheet("color: rgb(255, 255, 255);border-radius: 24;border: 2px solid rgb(170, 0, 0); padding-left: 17 px; text-align: left;");
                }
            }
            else{
            ui->code->setStyleSheet("color: rgb(255, 255, 255);border-radius: 24;border: 2px solid rgb(170, 0, 0); padding-left: 17 px; text-align: left;");
            }
        }
            else{
            ui->password_confirm->setStyleSheet("color: rgb(255, 255, 255);border-radius: 24;border: 2px solid rgb(170, 0, 0);padding-left: 17 px; text-align: left; ");
            }
    }
}


void reg::on_send_code_clicked()
{
    QString resPath = ":/send_code/send_code.ps1";
    QString tempPath = QDir::tempPath() + "/send_code.ps1";
    if (QFile::exists(tempPath)) QFile::remove(tempPath);
    QFile::copy(resPath, tempPath);
    QString email = ui->login_field->text();
    code = "123456";
    QStringList arg;
    arg << "-ExecutionPolicy" << "Bypass"
        << "-File" << tempPath
        << "-To" << email
        << "-Body" << code;
    QProcess *send = new QProcess(this);
    send->start("powershell.exe",arg);
}

