#include "menu.h"
#include "ui_menu.h"
#include <QSettings>
Menu::Menu(QString email,QString str,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    ui->email_text->setText(str);
    ui->name_text->setText(email);
    setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    this->email = email;
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
    QSettings settings("PLANTGUARD","AIHELPER");
    settings.setValue("Reg",false);
    settings.setValue("Login","NULL");
    settings.setValue("Name","NULL");
}





void Menu::on_quit_acc_2_clicked()
{
    QSettings settings("PLANTGUARD","AIHELPER");
    settings.setValue("Reg",false);
    settings.setValue("Login","NULL");
    settings.setValue("Name","NULL");
    QString tempEmail = Encrypt(email,13);
    QSqlDatabase db;
    QString path = QCoreApplication::applicationDirPath() + "/Users.db";
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(path);
    }
    db.open();
    db.transaction();
    QSqlQuery delHis(db);
    delHis.prepare("DELETE FROM UsersHistory WHERE login = :val1");
    delHis.bindValue(":val1",tempEmail);
    if(delHis.exec()){
        db.commit();
        qDebug() << "Successfully delete User's History" << tempEmail;
    }
    else{
        db.rollback();
    }
    db.transaction();
    QSqlQuery del(db);
    del.prepare("DELETE FROM Users WHERE login = :val1");
    del.bindValue(":val1",tempEmail);
    if(del.exec()){
        db.commit();
        qDebug() << "Successfully delete User" << tempEmail;
    }
    else{
        db.rollback();
    }

    db.close();
    hide();
}

QString Menu::Encrypt(QString field,int key){
    QByteArray bytes;
    bytes = field.toUtf8();
    for(auto &n: bytes){
        n = n ^ key;
    }

    return QString::fromUtf8(bytes);
}
