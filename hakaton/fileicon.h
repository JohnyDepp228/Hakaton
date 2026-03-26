#ifndef FILEICON_H
#define FILEICON_H

#include <QWidget>
#include <QFrame>

namespace Ui {
class FileIcon;
}

class FileIcon : public QFrame
{
    Q_OBJECT

public:
    explicit FileIcon(QFrame *parent = nullptr);
    ~FileIcon();
    void SetFileName(QString file_name);
    void SetFileIcon(QString file_name);

private:
    Ui::FileIcon *ui;
};

#endif // FILEICON_H
