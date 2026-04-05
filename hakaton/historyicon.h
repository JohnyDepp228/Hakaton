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

    void SetHistoryImg(QString login,int place);

    void SetHistoryText(QString login, int place);

    void SetHistoryImg(QString login);

    void SetHistoryText(QString login);

    int HistoryCount(QString login);

 signals:

    void ShowHistory(const QPixmap &img,QString text);

 private slots:

     void on_History_clicked();

 private:

    Ui::HistoryIcon *ui;
    QSqlDatabase db;
};

#endif // HISTORYICON_H
