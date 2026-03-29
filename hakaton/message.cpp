#include "message.h"
#include "ui_message.h"


message::message(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::message)
{
    ui->setupUi(this);
    lay = new QGridLayout();
    ui->iconplace->setLayout(lay);
}

message::~message()
{
    delete ui;
}

void message::clearLayout(QGridLayout *layout) {
    if (!layout) return;
    while (auto item = layout->takeAt(0)) {
        if (auto widget = item->widget()) {
            widget->deleteLater();
        }
    }
}


void message::AddFile(FileIcon *file){
    static int col = 0;
    static int row = 3;
    lay->addWidget(file,row,col,Qt::AlignLeft | Qt::AlignCenter);
    col++;
}

void message::on_send_msg_clicked()
{
    hide();
    clearLayout(lay);
}

