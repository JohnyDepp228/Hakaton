#include "minimenu.h"
#include "ui_minimenu.h"

minimenu::minimenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::minimenu)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
}

minimenu::~minimenu()
{
    delete ui;
}

void minimenu::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}


void minimenu::on_settings_clicked()
{
    ui2 = new Menu();
    ui2->move(800,300);
    ui2->show();
}


void minimenu::on_close_clicked()
{
     QApplication::quit();
}

