#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QListWidgetItem>
#include <QImage>
#include <QColor>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_triggered();

    void on_action_3_triggered();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);


    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

    void on_action_10_triggered();

    void on_action_11_triggered();

    void on_action_2_triggered();

private:
    Ui::MainWindow *ui;
    QLabel * imageLabel;
    void setImagesList(QString FileName);
    QImage origin;
    QImage view;
    qreal saturation = 0;

    void setOrigin(QString path);
    void updateImg();

};

#endif // MAINWINDOW_H
