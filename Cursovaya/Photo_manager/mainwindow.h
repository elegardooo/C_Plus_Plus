#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QListWidgetItem>
#include <QImage>
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_label_linkActivated(const QString &link);

    void on_action_1_triggered();

private:
    Ui::MainWindow *ui;
    QLabel * imageLabel;
    void setImagesList(QString FileName);
    QImage origin;
    QImage view;
    qreal saturation = 0;

    void setOrigin(QString path);
};
#endif // MAINWINDOW_H
