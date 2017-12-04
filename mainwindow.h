#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mainscene.h"
#include "info.h"
#include <QApplication>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    class MainScene myscene;
    void connect_signal();
    void set_UI();

public slots:
    void addPoint(int x,int y);
    void resizeShape(qreal w,qreal h);
    void clearScene();
    void finish();
    void start(int,int);

private slots:

    void on_pushButton_2_clicked();
    void on_radioButton_7_clicked();
    void on_radioButton_8_clicked();
    void on_radioButton_9_clicked();
    void on_radioButton_10_clicked();
    void on_radioButton_11_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_radioButton_2_clicked();
    void on_radioButton_3_clicked();
    void on_radioButton_clicked();
    void on_checkBox_clicked(bool checked);
};

#endif // MAINWINDOW_H
