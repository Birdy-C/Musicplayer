//这个主要的画的
#ifndef POINTS_H
#define POINTS_H

#include "info.h"
#include <QMessageBox>
#include <QDebug>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QGraphicsItemGroup>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QTime>
#include <QDebug>
#include <QPixmap>

class Points
{
    friend class MainScene;
private:
    int pointX[5000];
    int pointY[5000];
    int count;//the number of points on the scene
    int index;//小球位置
    int pointMode;//0-4 标记音色
    QColor color[5];
    QColor color2[5];
    QPen pen;
    QPen pen2;
    QGraphicsEllipseItem *group_line;
    QGraphicsEllipseItem *group_line2;
    QGraphicsEllipseItem ball;
    QGraphicsScene *scene;

public:   
    Points(QGraphicsScene *scene);
    ~Points();
    bool addPoint(const int x, const int y);
    class Info nextpos();
    void clear(QGraphicsScene &Scene);
    void setInit(int temp);
    bool finish();
    void nextStep(class Info &info1,class Info &info2);
    void getStep(class Info &info1,class Info &info2);//获取最后两个点

};


#endif // POINTS_H
