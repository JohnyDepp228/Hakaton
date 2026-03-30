#ifndef HIDEMENU_H
#define HIDEMENU_H

#include <QWidget>

namespace Ui {
class hidemenu;
}

class hidemenu : public QWidget
{
    Q_OBJECT

public:
    explicit hidemenu(QWidget *parent = nullptr);
    ~hidemenu();
signals:
    void UnionClicked();
    void ResetScreen();
private slots:
    void on_union_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::hidemenu *ui;
};

#endif // HIDEMENU_H
