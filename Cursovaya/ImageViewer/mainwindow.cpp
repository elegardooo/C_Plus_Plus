#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include "imageitem.h"
#include "math.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageLabel = new QLabel(this);
    imageLabel->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
    ui->scrollArea->setWidget(imageLabel);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                       "Выбрать изображение", "",
                        "Изображения (*.bmp  *.jpg *.png)");
    QPixmap pix(fileName);
    imageLabel->setPixmap(pix);
    imageLabel->setFixedSize(pix.width(),pix.height());
    setImagesList(fileName);
    setOrigin(fileName);
}

void MainWindow::on_action_3_triggered()
{
    this->close();
}

void MainWindow::setImagesList(QString FileName)
{
    ui->listWidget->clear();
    QFileInfo info(FileName);
    QDir dir(info.absoluteDir());
    QStringList filtr;
    filtr << "*.jpg" << "*.png" << "*.bmp";
    qDebug() << dir.entryInfoList(filtr);
    QFileInfoList list = dir.entryInfoList(filtr);
    // Добавляем изображения в listWidget
    for (int i = 0;i < list.count();i++) {
        QFileInfo f = list.at(i);
        QPixmap pix(f.filePath());
        int w = pix.width();
        int h = pix.height();
        double fSize =f.size() / 1024.;
        QString Info = QString::number(w) + "x" + QString::number(h) + ", " + QString::number(round(fSize * 10) / 10) + "KB";
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        imageitem *imgitem = new imageitem;
        imgitem->setData(pix.scaledToWidth(90,Qt::SmoothTransformation),f.fileName(),Info, f.filePath());
        item->setSizeHint(imgitem->sizeHint());
        ui->listWidget->setItemWidget(item,imgitem);
}
    /*

        qDebug() << f.fileName();
        QIcon icon(f.filePath());
        QListWidgetItem *item = new QListWidgetItem(icon,FileName);
        ui->listWidget->addItem(item);
        if(f.filePath() == FileName)
           item->setSelected(true);
    */
}

void MainWindow::setOrigin(QString path)
{
    saturation = 0;
    origin = QImage(path);
}

void MainWindow::updateImg()
{
    QColor color;
    view = QImage(origin);
    for (int x=0;x<view.width();x++ ) {
        for (int y=0;y<view.height() ;y++ ) {
            color = view.pixelColor(x, y);
            qreal ns = color.hslSaturationF() +saturation;
            if(ns < 0) ns = 0;
            else if(ns > 1) ns = 1;
            color.setHslF(color.hslHueF(),ns,color.lightnessF());
            view.setPixelColor(x, y, color);
        }
    }
    imageLabel->setPixmap(QPixmap::fromImage(view));
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    imageitem *imgitem = qobject_cast <imageitem *>(ui->listWidget->itemWidget(item));
    QPixmap pix(imgitem->getPath());
    imageLabel->setPixmap(pix);
    imageLabel->setFixedSize(pix.width(),pix.height());
    setOrigin(imgitem->getPath());
}




void MainWindow::on_action_4_triggered()
{
    int newWidth = int(imageLabel->width()*1.25);
    int newHeight = int(imageLabel->height()*1.25);
    imageLabel->setFixedSize(newWidth,newHeight);
}

void MainWindow::on_action_5_triggered()
{
    int newWidth = int(imageLabel->width()*0.75);
    int newHeight = int(imageLabel->height()*0.75);
    imageLabel->setFixedSize(newWidth,newHeight);
}

void MainWindow::on_action_6_triggered()
{
   imageLabel->setFixedSize(imageLabel->pixmap(Qt::ReturnByValue).size());

}

void MainWindow::on_action_7_triggered()
{
   double hFactor =  double(ui->scrollArea->width())/imageLabel->width();
   imageLabel->setFixedSize(int(imageLabel->width()*hFactor)-2,
                            int(imageLabel->height()*hFactor)-2);
}

void MainWindow::on_action_10_triggered()
{
   if(saturation < 1){
       saturation += 0.1;
   }
   updateImg();
}

void MainWindow::on_action_11_triggered()
{
    if(saturation > -1){
        saturation -= 0.1;
    }
    updateImg();
}

void MainWindow::on_action_2_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                       "Выбрать изображение", "",
                        "Изображения (*.bmp  *.jpg *.png)");
    //imageLabel->pixmap()->save(fileName);
    imageLabel->pixmap(Qt::ReturnByValue).save(fileName);

}
