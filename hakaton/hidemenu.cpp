#include "hidemenu.h"
#include "ui_hidemenu.h"

hidemenu::hidemenu( QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::hidemenu)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Tool |Qt::FramelessWindowHint);
}

hidemenu::~hidemenu()
{
    delete ui;
}

void hidemenu::on_union_2_clicked()
{
    emit UnionClicked();
}

