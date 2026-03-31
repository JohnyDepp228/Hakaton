#ifndef SIDEMENU_H
#define SIDEMENU_H

#include <QWidget>
#include <QFontDatabase>
#include "minimenu.h"
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>

namespace Ui {
class sidemenu;
}

class sidemenu : public QWidget
{
    Q_OBJECT

public:
    explicit sidemenu(QString str,QWidget *parent = nullptr);
    ~sidemenu();

private slots:
    void on_union_2_clicked();
    void SetInterFont();
    void on_profile_info_clicked();
    void on_newchat_clicked();
    void SetHistoryImg(QString email);
    void SetHistoryText(QString email);
signals:
    void UnionClicked();
    void ResetScreen();

private:
    Ui::sidemenu *ui;
    minimenu *min;
    QString email;
    QSqlDatabase db;
};

#endif // SIDEMENU_H
