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
    ShowMenuAnimation(m,804,300);
}

void minimenu::ShowMenuAnimation(QWidget *min,int finish_x,int finish_y){
    QPropertyAnimation *animation = new QPropertyAnimation(min,"geometry");
    animation->setDuration(500);
    animation->setStartValue(QRect(85,850,1,1));
    animation->setEasingCurve(QEasingCurve::OutQuad);
    animation->setEndValue(QRect(finish_x,finish_y,568,310));
    min->show();
    animation->start(QAbstractAnimation::DeleteWhenStopped);
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
