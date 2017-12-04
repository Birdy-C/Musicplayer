//Birdy 17.10.27

#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QPixmap>
#include <QMovie>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this); // 设置ui
    ui->graphicsView->setScene(&myscene.Scene);

    set_UI();
    connect_signal();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::connect_signal()
{
    connect(ui->graphicsView,SIGNAL(addPoint(int,int)),this,SLOT(addPoint(int,int)));
    connect(ui->graphicsView,SIGNAL(resizeShape(qreal,qreal)),this,SLOT(resizeShape(qreal,qreal)));
    connect(ui->graphicsView,SIGNAL(finishtemp()),this,SLOT(finish()));
    connect(ui->graphicsView,SIGNAL(starttemp(int,int)),this,SLOT(start(int,int)));


}


void MainWindow::set_UI()
{

    QMovie *movie = new QMovie("E:/Code/musicplayer/pic/3.gif");
    ui->label_6->setMovie(movie);
    movie->start();
}


//======================================这里是一堆的槽==============

void MainWindow::addPoint(int x,int y)
{
    myscene.addPoint(x,y);
}



void MainWindow::resizeShape(qreal w,qreal h)
{
    myscene.Scene.setSceneRect(0, 0, w, h);
    myscene.backpicture->setPos(w-450,h-450);
}


void MainWindow::clearScene()
{
    myscene.clearScene();
}


void MainWindow::finish()
{
    myscene.finish();
}

void MainWindow::start(int x, int y)
{
    myscene.start(x,y);
}


void MainWindow::on_pushButton_2_clicked()
{
    clearScene();
}

void MainWindow::on_radioButton_7_clicked()
{
    myscene.pointMode = 0;
}

void MainWindow::on_radioButton_8_clicked()
{
    myscene.pointMode = 1;
}

void MainWindow::on_radioButton_9_clicked()
{
    myscene.pointMode = 2;
}

void MainWindow::on_radioButton_10_clicked()
{
    myscene.pointMode = 3;
}

void MainWindow::on_radioButton_11_clicked()
{
    myscene.pointMode = 4;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    myscene.timer.start(value);
}

void MainWindow::on_radioButton_2_clicked()
{
    myscene.effect_index = 0;
}

void MainWindow::on_radioButton_3_clicked()
{
     myscene.effect_index = 1;
}

void MainWindow::on_radioButton_clicked()
{
     myscene.effect_index = -1;
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    myscene.checkMode = checked;
}
