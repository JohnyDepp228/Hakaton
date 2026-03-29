#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>
#include <QGridLayout>
#include "fileicon.h"

namespace Ui {
class message;
}

class message : public QWidget
{
    Q_OBJECT

public:
    explicit message(QWidget *parent = nullptr);
    void AddFile(FileIcon *file);
    ~message();
private slots:
    void clearLayout(QGridLayout *layout);

    void on_send_msg_clicked();
signals:
    void mes();
private:
    Ui::message *ui;
    QGridLayout *lay;
};

#endif // MESSAGE_H
