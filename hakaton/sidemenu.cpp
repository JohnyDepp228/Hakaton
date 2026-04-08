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
    connect(parent,SIGNAL(CanAddHistory(QString,QString)),this,SLOT(AddHistory(QString,QString)));


    min = new minimenu(str,name,this);
    connect(min,&minimenu::CloseMain,this,&sidemenu::SignalToClose);
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
    ShowMenuAnimation(min,55,860);
}

void sidemenu::ShowMenuAnimation(QWidget *min,int finish_x,int finish_y){
    int start_x = 55;
    int start_y = 902;
    QPropertyAnimation *animation = new QPropertyAnimation(min,"geometry");
    animation->setDuration(500);
    animation->setStartValue(QRect(start_x,start_y,1,1));
    animation->setEasingCurve(QEasingCurve::OutQuad);
    animation->setEndValue(QRect(finish_x,finish_y,282,114));
    min->show();
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
void sidemenu::on_newchat_clicked()
{
    emit ResetScreen();
}

void sidemenu::SignalToClose(){
    emit CloseMain();
}
void sidemenu::AddHistory(QString img_path,QString answer) {
    HistoryIcon *hs = new HistoryIcon;
    hs->SetHistoryTextAndImg(img_path,answer);
   connect(hs, &HistoryIcon::ShowHistory, this, &sidemenu::HistorySide);
    Vlay->addWidget(hs);
}

void sidemenu::AddHistoryP(int place) {
    HistoryIcon *hs = new HistoryIcon;
    hs->SetHistoryText(nameDB,place);
    hs->SetHistoryImg(nameDB,place);
    connect(hs, &HistoryIcon::ShowHistory, this, &sidemenu::HistorySide);
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

