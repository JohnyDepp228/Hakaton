#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>

namespace Ui {
class Menu;
}
class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QString email, QString str, QWidget *parent = nullptr);
    ~Menu();

signals:
    void CloseMain();

private slots:
    void on_close_clicked();

    void on_quit_acc_clicked();

    void on_quit_acc_2_clicked();

    QString Encrypt(QString field,int key);

    void SignalToClose();

private:
    Ui::Menu *ui;
    QString email;
    QString name;
};

#endif // MENU_H
