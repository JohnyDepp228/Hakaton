#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showFullScreen();
    ui2 = new login(this);
    ui2->show();
    fplace = new QGridLayout();
    ui->filenameplace->setLayout(fplace);
    ui->msgicon->hide();
    file_count = 0;
    s = new sidemenu(this);
    s->move(0,0);
    s->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_load_media_clicked()
{
    static int col = 0;
    static int row = 3;
    QString filter = "All file(*.png)";
    full_file_name = QFileDialog::getOpenFileName(this,"Выберите медиа",QDir::homePath(),filter);
    int heightBonus = 0;
    if(!full_file_name.isEmpty())
    {
    ui->how_can_help->hide();
    fname = new FileIcon();
    QFileInfo fileInfo(full_file_name);
    QString file_name = fileInfo.fileName();
    fname->SetFileName(file_name);
    fname->SetFileIcon(full_file_name);
    if(col == 0){
       heightBonusM = heightBonus = fname->height() + 2;
    }
    if(col > 2){
        file_count++;
        QString str = "И еще " + QString::number(file_count);
        ui->text_hint->setText(str);
    }
    else{
        fplace->addWidget(fname,row,col,Qt::AlignLeft | Qt::AlignBottom);
        ui->filenameplace->show();
        QRect rect = ui->interact_frame->geometry();
        QRect addBut = ui->load_media->geometry();
        QRect hintText = ui->text_hint->geometry();
        QRect folder = ui->load_folder->geometry();
        ui->interact_frame->setGeometry(
            rect.x(),
            rect.y() - heightBonus,
            rect.width(),
            rect.height() + heightBonus
            );
        ui->load_media->setGeometry(addBut.x(),addBut.y() + heightBonus,addBut.width(),addBut.height());
        ui->text_hint->setGeometry(hintText.x(),hintText.y()+ heightBonus,hintText.width(),hintText.height());
        ui->load_folder->setGeometry(folder.x(),folder.y()+ heightBonus,folder.width(),folder.height());
        ui->text_hint->setText("Загруженно успешно");
    }
        col++;
    }
}

void MainWindow::SetMsgIcon(QString path){
    QPixmap pix(path);
    ui->msgicon->setPixmap(pix.scaled(ui->msgicon->height(),ui->msgicon->width(),Qt::KeepAspectRatio));
}
void MainWindow::on_send_msg_clicked()
{
    static bool changed = false;
    if(!full_file_name.isEmpty()){
        SetMsgIcon(full_file_name);
    }
    clearLayout(fplace);
    file_count  = 0;
    if(!changed){
    QRect rect = ui->interact_frame->geometry();
    QRect addBut = ui->load_media->geometry();
    QRect hintText = ui->text_hint->geometry();
    QRect folder = ui->load_folder->geometry();
    QRect filesname = ui->filenameplace->geometry();
    ui->interact_frame->setGeometry(rect.x(),rect.y() + 400,rect.width(),rect.height() - heightBonusM);
    ui->load_media->setGeometry(addBut.x(),addBut.y() - heightBonusM,addBut.width(),addBut.height());
    ui->text_hint->setGeometry(hintText.x(),hintText.y() - heightBonusM,hintText.width(),hintText.height());
    ui->load_folder->setGeometry(folder.x(),folder.y() - heightBonusM,folder.width(),folder.height());
    ui->filenameplace->setGeometry(filesname.x(),filesname.y() + 400,filesname.width(),filesname.height());
    changed = true;
    }
    ui->text_hint->setText("Загрузите медиа");
    ui->how_can_help->hide();
    ui->msgicon->show();
}

void MainWindow::clearLayout(QGridLayout *layout) {
    if (!layout) return;
    while (auto item = layout->takeAt(0)) {
        if (auto widget = item->widget()) {
            widget->deleteLater();
        }
    }
}
