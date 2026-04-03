#include "historyicon.h"
#include "ui_historyicon.h"
#include <iostream>

HistoryIcon::HistoryIcon(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HistoryIcon)
{
    ui->setupUi(this);
    QString path = QCoreApplication::applicationDirPath() + "/Users.db";
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(path);
    }
}

HistoryIcon::~HistoryIcon()
{
    delete ui;
}


void HistoryIcon::SetHistoryImg(QString email,int place){
    db.open();
    QPixmap pix;
    {
        QSqlQuery SetImag(db);
        SetImag.prepare("SELECT image FROM UsersHistory WHERE login = :user LIMIT 1 OFFSET :offset");
        SetImag.bindValue(":user",email);
        SetImag.bindValue(":offset",place);
        if(SetImag.exec() && SetImag.next()){
            QByteArray bytes = SetImag.value("image").toByteArray();
            pix.loadFromData(bytes);
            QPixmap scaledPix = pix.scaled(ui->img->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->img->setPixmap(scaledPix);
        }
    }
    db.close();
}

void HistoryIcon::SetHistoryText(QString email,int place){
    db.open();
    {
        QSqlQuery SetText(db);
        SetText.prepare("SELECT answer FROM UsersHistory WHERE login = :user LIMIT 1 OFFSET :offset");
        SetText.bindValue(":user",email);
        SetText.bindValue(":offset",place);
        if(SetText.exec() && SetText.next()){
                QString answer= SetText.value("answer").toString();
                ui->text_3->setText(answer);
        }
        else
        {
            ui->text_3->setText("No answer");
        }
    }
    db.close();
}

void HistoryIcon::SetHistoryImg(QString email){
    db.open();
    QPixmap pix;
    {
        QSqlQuery SetImag(db);
        SetImag.prepare("SELECT image FROM UsersHistory WHERE login = :user");
        SetImag.bindValue(":user",email);
        if(SetImag.exec() && SetImag.next()){
            QByteArray bytes = SetImag.value("image").toByteArray();
            pix.loadFromData(bytes);
            QPixmap scaledPix = pix.scaled(ui->img->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->img->setPixmap(scaledPix);
        }
    }
    db.close();
}

void HistoryIcon::SetHistoryText(QString email){
    db.open();
    {
        QSqlQuery SetText(db);
        SetText.prepare("SELECT answer FROM UsersHistory WHERE login = :user");
        SetText.bindValue(":user",email);
        if(SetText.exec() && SetText.next()){
            QString answer= SetText.value("answer").toString();
            ui->text_3->setText(answer);
        }
        else
        {
            ui->text_3->setText("No answer");
        }
    }
    db.close();
}

int HistoryIcon::HistoryCount(QString email){
    db.open();
    int count = 0;
    {
        QSqlQuery SetImag(db);
        SetImag.prepare("SELECT * FROM UsersHistory WHERE login = :user");
        SetImag.bindValue(":user",email);
        if(SetImag.exec()){
            while(SetImag.next()){
                count++;
            }
        }
    }
    db.close();
    return count;
}

void HistoryIcon::on_History_clicked()
{
    std::cout << "Clicked" << std::endl;
    emit ShowHistory();
}

