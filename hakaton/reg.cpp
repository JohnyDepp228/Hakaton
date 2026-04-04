#include "reg.h"
#include "ui_reg.h"

reg::reg(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::reg)
{
    ui->setupUi(this);
    showFullScreen();
    CreateDB();
    key = 13;
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
                AddToDB(ui->login_field->text(),ui->password_field_2->text(),ui->name_field->text());
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

void reg::CreateDB(){
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(QCoreApplication::applicationDirPath() + "/Users.db");
    }
    if (db.open()) {
        QSqlQuery query(db);
        QString str = "CREATE TABLE IF NOT EXISTS Users ("
                      "login TEXT NOT NULL, "
                      "password TEXT NOT NULL,"
                      "name TEXT NOT NULL);";
        query.exec(str);

        QString str1 = "CREATE TABLE IF NOT EXISTS UsersHistory ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "login TEXT NOT NULL, "
                      "image BLOB,"
                      "answer TEXT);";
        query.exec(str1);


        db.close();
    }

}


void reg::AddToDB(QString login,QString password,QString name){
    QString tempLog = Encrypt(login,key);
    QString tempPas = Encrypt(password,key);
    QString tempName = Encrypt(name,key);
    db.open();
    db.transaction();
    {
    QSqlQuery AddData(db);
    AddData.prepare("INSERT INTO Users(login, password, name) VALUES (:log,:pas,:nam)");
    AddData.bindValue(":log",tempLog);
    AddData.bindValue(":pas",tempPas);
    AddData.bindValue(":nam",tempName);
        if(AddData.exec()){
            db.commit();
        }
        else{
            db.rollback();
        }
    }
    db.close();
}

QString reg::Encrypt(QString field,int key){
    QByteArray bytes;
    bytes = field.toUtf8();
    for(auto &n: bytes){
        n = n ^ key;
    }

    return QString::fromUtf8(bytes);
}

QString reg::Decrypt(QString field,int key){
    QByteArray bytes;
    bytes = field.toUtf8();
    for(auto &n: bytes){
        n = n ^ key;
    }
    return QString::fromUtf8(bytes);
}

void reg::on_pushButton_clicked()
{
    hide();
}

