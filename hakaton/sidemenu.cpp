#include "sidemenu.h"
#include "ui_sidemenu.h"

sidemenu::sidemenu(QString str, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sidemenu)
{
    ui->setupUi(this);
    SetInterFont();
    email = str;
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

sidemenu::~sidemenu()
{
    delete ui;
}

void sidemenu::on_union_2_clicked()
{
    emit UnionClicked();
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
    min = new minimenu(email,this);
    min->move(55,860);
    min->show();
}


void sidemenu::on_newchat_clicked()
{
    emit ResetScreen();
}

