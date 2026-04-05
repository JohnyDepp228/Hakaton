#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QString str,QString name, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    user_name = name;
    user_email = str;
    ui->setupUi(this);
    QString path = QCoreApplication::applicationDirPath() + "/UsersHistory.db";
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(path);
    }
    ui->mes->hide();
    ui->answer->hide();
    ui->answer->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    men = new sidemenu(user_email,user_name,this);
    hm = new hidemenu(this);
    hm->hide();
    men->move(0,0);
    men->show();
    m = new message(this);
    m->hide();
    showFullScreen();
    connect(men, &sidemenu::UnionClicked, this, &MainWindow::HideSide);
    connect(men, &sidemenu::ResetScreen, this, &MainWindow::Reset);
    connect(hm, &hidemenu::UnionClicked, this, &MainWindow::ShowSide);
    connect(hm, &hidemenu::ResetScreen, this, &MainWindow::Reset);
    connect(m, &message::mes, this, &MainWindow::ShowMsg);

    connect(m, &message::mes, men, &sidemenu::AddHistory);
    bool con = connect(men,&sidemenu::HistorySide,this,&MainWindow::ShowTextAndImage);
    qDebug() << "Connection status:" << con;
    Createfile();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_load_media_clicked()
{
    QString filter = "All file(*.png)";
    full_file_name = QFileDialog::getOpenFileName(this,"Выберите медиа",QDir::homePath(),filter);
    if(!full_file_name.isEmpty())
    {
    ui->how_can_help->hide();
    fname = new FileIcon();
    QFileInfo fileInfo(full_file_name);
    QString file_name = fileInfo.fileName();
    fname->SetFileName(file_name);
    fname->SetFileIcon(full_file_name);
    m->AddFile(fname);
    m->move(792,953);
    m->show();
    ui->load_media->move(813,996);
    }
}

void MainWindow::HideSide(){
    men->hide();
    hm->move(0,0);
    hm->show();
}

void MainWindow::ShowSide(){
    hm->hide();
    men->move(0,0);
    men->show();
}

void MainWindow::ShowMsg(){
    SetMsgIcon(full_file_name);
    ui->mes->show();
    SaveImage(full_file_name);
    ShowAnswer();
}

void MainWindow::ShowHistory(){
    ui->how_can_help->hide();
    ui->load_media->hide();
    SetMsgIcon(full_file_name);
    ui->mes->show();
    SaveImage(full_file_name);
    ShowAnswer();
}

void MainWindow::SetMsgIcon(QString path){
    QPixmap pix(path);
    ui->mes->setPixmap(pix.scaled(ui->mes->height(),ui->mes->width(),Qt::KeepAspectRatio));
}

void MainWindow::ShowAnswer(){
    QFile f(full_path);
    QString answer;
    if(f.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&f);
    answer = in.readAll();
    ui->answer->setText(answer);
    ui->answer->show();
    SaveText(answer);
    }
    else{
        answer = "Error";
        SaveText(answer);
    }
    f.close();
}


void MainWindow::Createfile(){
    QString appPath = QCoreApplication::applicationDirPath();
    QString dirPath = appPath + "/Answer";
    QDir dir;
    if (!dir.exists(dirPath)) {
        dir.mkpath(dirPath);
    }
    full_path = dirPath + "/answer.txt";
    QFile f(full_path);
    if(f.open(QIODevice::WriteOnly  | QIODevice::Text)){
    f.write("Не чет не хочу");
    f.close();
    }
}

void MainWindow::Reset(){
    ShowSide();
    ui->mes->hide();
    ui->answer->hide();
    ui->how_can_help->show();
    ui->load_media->move(801,515);
    ui->load_media->show();
    if (!full_path.isEmpty()) {
        QFile file(full_path);
        if (!file.remove()) {
            std::cout << "Can't delete file" << std::endl;
        }
    }
    Createfile();
}


void MainWindow::SaveImage(QString image_path){
    db.open();
    QPixmap pix(image_path);
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    pix.save(&buffer,"PNG");
    {
    QSqlQuery AddImag(db);
    AddImag.prepare("INSERT INTO UsersHistory (login,image) VALUES (:user,:img) ");
    AddImag.bindValue(":user",user_name);
    AddImag.bindValue(":img",bytes);
    AddImag.exec();
    }
    db.close();
}

void MainWindow::SaveText(QString answer){
    db.open();
    {
        QSqlQuery AddMsg(db);
        AddMsg.prepare("UPDATE UsersHistory SET answer = :msg WHERE login = :img");
        AddMsg.bindValue(":msg",answer);
        AddMsg.bindValue(":img",user_name);
        AddMsg.exec();
    }
    db.close();
}

void MainWindow::ShowTextAndImage(const QPixmap &img,QString answer){
    ui->answer->setText(answer);
    ui->mes->setPixmap(img);
    ui->how_can_help->hide();
    ui->load_media->hide();
    ui->answer->show();
    ui->mes->show();
}


