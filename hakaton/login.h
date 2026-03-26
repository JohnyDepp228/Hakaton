#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include "reg.h"
namespace Ui {
class login;
}
class reg;
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

private:
    Ui::login *ui;
    reg *re;
};

#endif // LOGIN_H
