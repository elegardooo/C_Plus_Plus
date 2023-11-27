#include <QMainWindow>
#include "imageitem.h"

Imageitem::Imageitem(QWidget *parent) : QWidget(parent)
{

}

void Imageitem::setData(QPixmap Image, QString TitleText, QString InfoText, QString Path)
{
    this->img->setPixmap(Image);
    this->title->setText(TitleText);
    this->info->setText(InfoText);
    path = Path;
}

