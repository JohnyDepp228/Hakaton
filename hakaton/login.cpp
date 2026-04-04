#include "login.h"
#include "ui_login.h"
#include "menu.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    QString path = QCoreApplication::applicationDirPath() + "/Users.db";
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(path);
    }
    showFullScreen();
    key = 13;
}

login::~login()
{
    delete ui;
}

void login::on_regestaration_clicked()
{
    reg *r = new reg(this);
    r->showFullScreen();
}

void login::on_forgot_password_clicked()
{
    QMessageBox::information(this,"","adada");
}

void login::on_enter_clicked()
{
    QString login = ui->login_field->text();
    QString password = ui->password_field_2->text();
    QString tempLog = Encrypt(login,key);
    QString tempPas = Encrypt(password,key);
    QString tempName;
        if(OpenDB(tempLog,tempPas)){
            GetName(tempLog,tempPas);
            tempName = Encrypt(name,key);
            ui->login_field->setStyleSheet("color: rgb(255, 255, 255); border-radius: 24; border: 2px solid rgb(103, 147, 0); padding-left: 17 px; text-align: left;");
            ui->password_field_2->setStyleSheet("color: rgb(255, 255, 255); border-radius: 24; border: 2px solid rgb(103, 147, 0); padding-left: 17 px; text-align: left;");
            MainWindow *m = new MainWindow(login,tempName);
            m->show();
            hide();
        }
        else{
            ui->login_field->setStyleSheet("color: rgb(255, 255, 255); border-radius: 24; border: 2px solid rgb(170, 0, 0); padding-left: 17 px; text-align: left;");
            ui->password_field_2->setStyleSheet("color: rgb(255, 255, 255); border-radius: 24; border: 2px solid rgb(170, 0, 0); padding-left: 17 px; text-align: left;");
        }
}




bool login::OpenDB(QString login,QString password){
    db.open();
    bool access = false;
    {
        QSqlQuery show(db);
        show.prepare("SELECT * FROM Users WHERE login = :val1 AND password = :val2");
        show.bindValue(":val1",login);
        show.bindValue(":val2",password);
        if(show.exec() && show.next())
        {
            access = true;
        }
    }
    db.close();
    return access;
}

QString login::GetName(QString login,QString password){
    db.open();
    {
        QSqlQuery show(db);
        show.prepare("SELECT * FROM Users WHERE login = :val1 AND password = :val2");
        show.bindValue(":val1",login);
        show.bindValue(":val2",password);
        if(show.exec() && show.next())
        {
            name = show.value("name").toString();
        }
    }
    db.close();
    return name;
}


QString login::Encrypt(QString field,int key){
    QByteArray bytes;
    bytes = field.toUtf8();
    for(auto &n: bytes){
        n = n ^ key;
    }

    return QString::fromUtf8(bytes);
}
