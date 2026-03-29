#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    men = new sidemenu(this);
    hm = new hidemenu(this);
    hm->hide();
    men->move(0,0);
    men->show();
    m = new message(this);
    m->hide();
    showFullScreen();
    connect(men, &sidemenu::UnionClicked, this, &MainWindow::HideSide);
    connect(hm, &hidemenu::UnionClicked, this, &MainWindow::ShowSide);
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

