#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imageitem.h"
#include <QPixmap>
#include <QFileDialog>
#include <QFileInfo>
#include "math.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    setFixedSize(1500, 1000);
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


void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("Button is pressed!");
}


void MainWindow::on_action_1_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Выбрать изображение", "",
                                                    "Изображения (*.bmp  *.jpg *.png)");
    QPixmap pix(fileName);
    imageLabel->setPixmap(pix);
    imageLabel->setFixedSize(pix.width(),pix.height());
    setImagesList(fileName);
    //setOrigin(fileName);
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
        Imageitem *imgitem = new Imageitem;
        imgitem->setData(pix.scaledToWidth(90,Qt::SmoothTransformation),f.fileName(),Info, f.filePath());
        item->setSizeHint(imgitem->sizeHint());
        ui->listWidget->setItemWidget(item,imgitem);
    }
}

void MainWindow::on_label_linkActivated(const QString &link)
{

}

