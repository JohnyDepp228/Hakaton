#ifndef REG_H
#define REG_H


#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QMainWindow>
#include <QProcess>
#include <QFile>
#include <QDir>
#include <iostream>
#include <QMessageBox>

namespace Ui {
class reg;
}


class reg : public QMainWindow
{
    Q_OBJECT

public:
    explicit reg(QWidget *parent = nullptr);
    ~reg();


private slots:
    void on_reg_buttom_clicked();

    void on_send_code_clicked();

    void CreateDB();

    void AddToDB(QString login, QString password, QString name);

    QString Encrypt(QString field, int key);

    QString Decrypt(QString field, int key);

    void on_pushButton_clicked();

private:
    Ui::reg *ui;
    QString code;
    QSqlDatabase db;
    int key;
};

#endif // REG_H
