#ifndef SIDEMENU_H
#define SIDEMENU_H

#include <QWidget>
#include "hidemenu.h"
#include "minimenu.h"

namespace Ui {
class sidemenu;
}
class hidemenu;
class sidemenu : public QWidget
{
    Q_OBJECT

public:
    explicit sidemenu(QWidget *parent = nullptr);
    ~sidemenu();

private slots:
    void on_union_2_clicked();
    void SetInterFont();

    void on_profile_info_clicked();

private:
    Ui::sidemenu *ui;
    hidemenu *h;
    minimenu *ui3;
};

#endif // SIDEMENU_H
