// 这个是弦
#ifndef LINE_H
#define LINE_H
#include "info.h"
#include "myqgraphicsellipseitem.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QGraphicsItemGroup>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QTime>
#include <QDebug>
#include <QPixmap>

class Line
{
    friend class MainScene;
    int point1[2];
    int point2[2];//这两个分别是两个端点的xy值
    int count;
    int index;
    QPen pen_point;
    QPen pen_line;
    QColor color1;
    QColor color2;
    QColor color3;

    QMediaPlayer player[5];//每个弦可以发出5个音
    QMediaPlayer effect[2];
    myQGraphicsEllipseItem *pointObj1;
    myQGraphicsEllipseItem *pointObj2;
    QGraphicsLineItem *LineObj;
    QGraphicsScene *scene;


    void setObj();

public:
    //calculate
    void setpos(int index,int x,int y);//index 0/1
    int getcollection(int x,int y);
    void reset();
    void clear();
    void play(class Info info1, Info info2, int effect);
    Line(int x1, int y1, int x2, int y2, int path, QGraphicsScene* scene,int width);
    ~Line();

};

#endif // LINE_H
