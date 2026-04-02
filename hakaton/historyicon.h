#ifndef HISTORYICON_H
#define HISTORYICON_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>

namespace Ui {
class HistoryIcon;
}

class HistoryIcon : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryIcon(QWidget *parent = nullptr);
    ~HistoryIcon();

    void SetHistoryImg(QString email,int place);

    void SetHistoryText(QString email, int place);

    void SetHistoryImg(QString email);

     void SetHistoryText(QString email);

    int HistoryCount(QString email);

private:
    Ui::HistoryIcon *ui;
    QSqlDatabase db;
};

#endif // HISTORYICON_H
