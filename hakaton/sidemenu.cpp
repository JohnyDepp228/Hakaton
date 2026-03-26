#include "sidemenu.h"
#include "ui_sidemenu.h"

sidemenu::sidemenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sidemenu)
{
    ui->setupUi(this);
    SetInterFont();
    setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

sidemenu::~sidemenu()
{
    delete ui;
}

void sidemenu::on_union_2_clicked()
{
    h = new hidemenu();
    hide();
    h->move(0,0);
    h->show();
}

void sidemenu::SetInterFont()
{
    int id = QFontDatabase::addApplicationFont(":/font/fonts/Inter-VariableFont_opsz,wght.ttf");
    QString inter = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont InterFont(inter,12);
    InterFont.setBold(true);
    ui->newchat->setFont(InterFont);
}


void sidemenu::on_profile_info_clicked()
{
    ui3 = new minimenu();
    ui3->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    ui3->setAttribute(Qt::WA_TranslucentBackground);
    ui3->move(110,860);
    ui3->show();
}

