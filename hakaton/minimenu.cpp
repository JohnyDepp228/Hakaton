#include "minimenu.h"
#include "ui_minimenu.h"

minimenu::minimenu(QString nameDB, QString emailDB, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::minimenu)
{
    ui->setupUi(this);
    email = emailDB;
    name = nameDB;
    setFocusPolicy(Qt::StrongFocus);
    setWindowFlags(Qt::Popup);
}

minimenu::~minimenu()
{
    delete ui;
}

void minimenu::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void minimenu::on_settings_clicked()
{
    m = new Menu(email,name,this);
    m->move(804,300);
    m->show();
}

void minimenu::on_close_clicked()
{
    QString appPath = QCoreApplication::applicationDirPath();
    QString dirPath = appPath + "/Answer";
    QDir dir;
    if (!dir.exists(dirPath)) {
        dir.mkpath(dirPath);
    }
    full_path = dirPath + "/answer.txt";
    if (!full_path.isEmpty()) {
        QFile file(full_path);
        if (file.remove()) {
            std::cout << "File deleted!" << std::endl;
        }
    }
    QApplication::quit();
}
