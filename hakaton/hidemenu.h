#ifndef HIDEMENU_H
#define HIDEMENU_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class hidemenu;
}

class sidemenu;
class hidemenu : public QWidget
{
    Q_OBJECT

public:
    explicit hidemenu(QWidget *parent = nullptr);
    ~hidemenu();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::hidemenu *ui;
    sidemenu *si;
};

#endif // HIDEMENU_H
