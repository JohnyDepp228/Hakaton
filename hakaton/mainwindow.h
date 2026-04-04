#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFontDatabase>
#include <QFont>
#include <QFileDialog>
#include <QDir>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QBuffer>
#include "message.h"
#include "sidemenu.h"
#include "hidemenu.h"
#include <windows.h>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QString str, QString name, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_load_media_clicked();
    void HideSide();
    void ShowSide();
    void ShowMsg();
    void SetMsgIcon(QString path);
    void ShowAnswer();
    void Reset();
    void Createfile();
    void SaveImage(QString image_path);
    void SaveText(QString answer);
    void History();
private:
    Ui::MainWindow *ui;
    QString full_file_name;
    FileIcon *fname;
    message *m;
    hidemenu *hm;
    sidemenu *men;
    QString full_path;
    QSqlDatabase db;
    QString user_name;
    QString user_email;
    HistoryIcon *HistoryCout;
};
#endif // MAINWINDOW_H
