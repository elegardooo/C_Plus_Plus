#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>

class imageitem : public QWidget
{
    Q_OBJECT
public:
    explicit imageitem(QWidget *parent = nullptr);
    void setData(QPixmap Image, QString TitleText, QString InfoText, QString Path);
    QString getPath();
private:
    QLabel *img;
    QLabel *title;
    QLabel *info;
    QString path;

signals:

};

#endif // IMAGEITEM_H
