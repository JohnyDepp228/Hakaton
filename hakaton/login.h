#ifndef LOGIN_H
#define LOGIN_H


#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QMainWindow>
#include <QMessageBox>
#include <iostream>
#include <QSettings>
#include "reg.h"
#include "mainwindow.h"

namespace Ui {
class login;
}
class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_regestaration_clicked();

    void on_enter_clicked();

    void on_forgot_password_clicked();

    bool OpenDB(QString login,QString password);

    QString Encrypt(QString field,int key);

    QString GetName(QString login,QString password);
private:
    Ui::login *ui;
    QSqlDatabase db;
    QString name;
    int key;
};

#endif // LOGIN_H
