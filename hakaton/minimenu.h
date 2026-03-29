#ifndef MINIMENU_H
#define MINIMENU_H

#include <QWidget>
#include <QFrame>
#include <QPainter>
#include <QStyleOption>
#include "menu.h"

namespace Ui {
class minimenu;
}
class minimenu : public QWidget
{
    Q_OBJECT

public:
    explicit minimenu(QWidget *parent = nullptr);
    ~minimenu();

private slots:
    void on_settings_clicked();

    void on_close_clicked();

protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Ui::minimenu *ui;
    Menu *m;
};

#endif // MINIMENU_H
