#include "sidemenu.h"
#include "ui_sidemenu.h"


sidemenu::sidemenu(QString str,QString name, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sidemenu)
{
    ui->setupUi(this);
    SetInterFont();
    email = str;
    nameDB = name;
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->user_name->setText(name);
    ms = new message(this);
    ms->hide();
    ui->HistoryScroll->setWidgetResizable(true);
    HistoryPlace = new QWidget;
    Vlay = new QVBoxLayout(HistoryPlace);
    HistoryPlace->setLayout(Vlay);
    Vlay->setContentsMargins(0, 0, 0, 0);
    Vlay->setSpacing(12);
    Vlay->setAlignment(Qt::AlignTop);
    ui->HistoryScroll->setWidget(HistoryPlace);
    ShowAllHistory();
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
    min = new minimenu(email,nameDB,this);
    min->move(55,860);
    min->show();
}


void sidemenu::on_newchat_clicked()
{
    emit ResetScreen();
}


void sidemenu::AddHistory() {
    HistoryIcon *hs = new HistoryIcon;
    qDebug() << "Name sent" << email;
    hs->SetHistoryText(nameDB);
    hs->SetHistoryImg(nameDB);
    Vlay->addWidget(hs);
}

void sidemenu::AddHistoryP(int place) {
    HistoryIcon *hs = new HistoryIcon;
    hs->SetHistoryText(nameDB,place);
    hs->SetHistoryImg(nameDB,place);
    Vlay->addWidget(hs);
}

void sidemenu::ShowAllHistory() {
    HistoryIcon *hs = new HistoryIcon;
    histCount = hs->HistoryCount(nameDB);
    if(histCount > 0){
    for(int i = 0;i < histCount;++i)
        {
            AddHistoryP(i);
        }
    }
    delete hs;
}
