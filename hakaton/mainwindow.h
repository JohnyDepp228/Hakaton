#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontDatabase>
#include <QFont>
#include <QFileDialog>
#include <QDir>
#include <QGridLayout>
#include "login.h"
#include "minimenu.h"
#include "fileicon.h"
#include "hidemenu.h"
#include "sidemenu.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class hidemenu;
class sidemenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_load_media_clicked();

    void on_send_msg_clicked();

    void SetMsgIcon(QString path);

    void clearLayout(QGridLayout *layout);

private:
    Ui::MainWindow *ui;
    login *ui2;
    QGridLayout *fplace;
    QString full_file_name;
    FileIcon *fname;
    int heightBonusM;
    int file_count;
    hidemenu *hm;
    sidemenu *s;
};
#endif // MAINWINDOW_H
