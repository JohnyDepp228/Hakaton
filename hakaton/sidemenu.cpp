#include "sidemenu.h"
#include "ui_sidemenu.h"

sidemenu::sidemenu(QString str, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sidemenu)
{
    ui->setupUi(this);
    SetInterFont();
    QString path = QCoreApplication::applicationDirPath() + "/Users.db";
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(path);
    }
    email = str;
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    SetHistoryImg(email);
    SetHistoryText(email);
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

void sidemenu::SetHistoryImg(QString email){
    db.open();
    QPixmap pix;
    {
        QSqlQuery SetImag(db);
        SetImag.prepare("SELECT image FROM UsersHistory WHERE login = :user");
        SetImag.bindValue(":user",email);
        if(SetImag.exec()){
            SetImag.next();
            QByteArray bytes = SetImag.value("image").toByteArray();
            pix.loadFromData(bytes);
            QPixmap scaledPix = pix.scaled(ui->img->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->img->setPixmap(scaledPix);
        }
    }
    db.close();
}

void sidemenu::SetHistoryText(QString email){
    db.open();
    {
        QSqlQuery SetText(db);
        SetText.prepare("SELECT answer FROM UsersHistory WHERE login = :user");
        SetText.bindValue(":user",email);
        if(SetText.exec()){
            if(SetText.next()){
            QString answer= SetText.value("answer").toString();
                ui->text_3->setText(answer);}
            else
            {
                 ui->text_3->setText("No answer");
            }
        }
        else
        {
            ui->text_3->setText("No answer");
        }
    }
    db.close();
}
