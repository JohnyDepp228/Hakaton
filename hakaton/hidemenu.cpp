#include "hidemenu.h"
#include "ui_hidemenu.h"

hidemenu::hidemenu( QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::hidemenu)
{
    ui->setupUi(this);
    setWindowFlags(Qt::SubWindow |Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

hidemenu::~hidemenu()
{
    delete ui;
}

void hidemenu::on_pushButton_2_clicked()
{
    hide();
    si = new sidemenu();
    si->show();
}

