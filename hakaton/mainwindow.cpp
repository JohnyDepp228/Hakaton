#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mes->hide();
    ui->answer->hide();
    ui->answer->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    men = new sidemenu(this);
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
    ui->load_folder->move(1118,996);
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
    ShowAnswer();
}

void MainWindow::SetMsgIcon(QString path){
    QPixmap pix(path);
    ui->mes->setPixmap(pix.scaled(ui->mes->height(),ui->mes->width(),Qt::KeepAspectRatio));
}

void MainWindow::ShowAnswer(){
    QFile f("C:/Users/Boss/Desktop/Hakaton/hakaton/Answer/answer.txt");
    bool open = f.open(QIODevice::ReadOnly | QIODevice::Text);
    if(open) {
    QTextStream in(&f);
    QString answer = in.readAll();
    ui->answer->setText(answer);
    ui->answer->show();
    }
    f.close();
}


void MainWindow::Reset(){
    ShowSide();
    ui->mes->hide();
    ui->answer->hide();
    ui->how_can_help->show();
    ui->load_media->move(801,515);
    ui->load_folder->move(1132,515);
}

