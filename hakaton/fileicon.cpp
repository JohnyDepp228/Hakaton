#include "fileicon.h"
#include "ui_fileicon.h"

FileIcon::FileIcon(QFrame *parent)
    : QFrame(parent)
    , ui(new Ui::FileIcon)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
}

FileIcon::~FileIcon()
{
    delete ui;
}


void FileIcon::SetFileName(QString file_name){
    ui->file_name->setText(file_name);
}
void FileIcon::SetFileIcon(QString file_path){
    QPixmap pix(file_path);
    ui->file_img->setPixmap(pix.scaled(ui->file_img->height(),ui->file_img->width(),Qt::KeepAspectRatio));
}
