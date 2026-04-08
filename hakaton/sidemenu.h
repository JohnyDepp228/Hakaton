#ifndef SIDEMENU_H
#define SIDEMENU_H

#include <QWidget>
#include <QFontDatabase>
#include "minimenu.h"
#include "historyicon.h"
#include "message.h"
#include <QVBoxLayout>
#include <QPropertyAnimation>

namespace Ui {
class sidemenu;
}
class MainWindow;
class sidemenu : public QWidget
{
    Q_OBJECT

public:
    explicit sidemenu(QString str, QString name, QWidget *parent = nullptr);
    ~sidemenu();
public slots:
    void AddHistory(QString img_path, QString answer);

private slots:
    void on_union_2_clicked();
    void SetInterFont();
    void on_profile_info_clicked();
    void on_newchat_clicked();
    void ShowAllHistory();
    void AddHistoryP(int place);
    void ShowMenuAnimation(QWidget *min, int finish_x, int finish_y);

signals:
    void UnionClicked();
    void ResetScreen();
    void HistorySide(const QPixmap &img,QString text);

private:
    Ui::sidemenu *ui;
    minimenu *min;
    QString email;
    QString nameDB;
    QWidget *HistoryPlace;
    QVBoxLayout *Vlay;
    message *ms;
    int histCount = 0;
};

#endif // SIDEMENU_H
