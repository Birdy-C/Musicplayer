//Birdy 2017.10.8

#ifndef MAINSCENE_H
#define MAINSCENE_H
#include "info.h"

#include <QList>
#include <QMainWindow>
#include <QtMath>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QTime>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QDebug>
#include <QPixmap>
#include <QTimer>
#include <QSoundEffect>
#include "points.h"
#include "line.h"
#include "info.h"

class MainScene:public QMainWindow
{
    Q_OBJECT

private:
    QGraphicsItem *backpicture;//后面那张小埋 不用管
    QGraphicsScene Scene;

    class Line *line[10];//十条弦
    //这里画的线是用一串的points连接形成的，line特指弦
    class Points *points[50];//我这里设置画的线条最多50条（然而没有溢出报错）
    int point_count;//记录已经画了几条线
    int pointMode;//0-4

    int active_num;//widget 是-1 这个是用来判断点击事件 点到了什么东西 点到画布开始画图，点到弦的一端可以移动
    int effect_index;//这个是ui界面中play下面的选项
    QTimer timer;//计时器，速度快慢靠这个条件
    bool checkMode;//这个是为了展示加的一个按钮


public:
    MainScene();
    ~MainScene();
    friend class MainWindow;
    //清屏
    void clearScene();

    //下面三个都是与鼠标有关的事件
    void addPoint(int x,int y);
    void finish();
    void start(int x ,int y);

public slots:
    void updateMusic();



};


#endif // MAINSCENE_H


