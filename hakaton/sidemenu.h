#ifndef SIDEMENU_H
#define SIDEMENU_H

#include <QWidget>
#include <QFontDatabase>
#include "minimenu.h"


namespace Ui {
class sidemenu;
}

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
signals:
    void UnionClicked();

private:
    Ui::sidemenu *ui;
    minimenu *min;
};

#endif // SIDEMENU_H
