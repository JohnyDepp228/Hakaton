#ifndef REG_H
#define REG_H

#include <QMainWindow>
#include "login.h"
#include <QProcess>
#include <QFile>
#include <QDir>

namespace Ui {
class reg;
}

class login;

class reg : public QMainWindow
{
    Q_OBJECT

public:
    explicit reg(QWidget *parent = nullptr);
    ~reg();


private slots:
    void on_reg_buttom_clicked();

    void on_send_code_clicked();

private:
    Ui::reg *ui;
    login *log;
    QString code;
};

#endif // REG_H
