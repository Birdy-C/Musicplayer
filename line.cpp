//Birdy 17.10.27

#include "line.h"
#include <QSoundEffect>
Line::Line(int x1, int y1, int x2, int y2, int path, QGraphicsScene *myscene,int indext):
    color1(255,249,110,200),color2(255,255,255,200),color3(255,255,0,150)
{
    index = indext;
    scene = myscene;
    point1[0] = x1;
    point1[1] = y1;
    point2[0] = x2;
    point2[1] = y2;

    for(int i = 0; i < 5;i++)
    {
        QString path_temp = "E:/Code/musicplayer/music/";
        path_temp +=('0'+i);
        path_temp +=('0'+indext);
        path_temp += ".mp3";
        player[i].setMedia(QUrl::fromLocalFile(path_temp));
    }
    effect[0].setMedia(QUrl::fromLocalFile(("E:/Code/musicplayer/backmusic/room1.wav")));
    effect[0].setVolume(50);
    effect[1].setMedia(QUrl::fromLocalFile(("E:/Code/musicplayer/backmusic/room2.wav")));
    effect[1].setVolume(50);
    pen_line.setColor(color1);
    pen_line.setWidth(10);
    pen_line.setCapStyle((Qt::RoundCap));
    pen_point.setColor(color1);
    pen_point.setWidth(index+10);
    setObj();

    scene->addItem(LineObj);
    scene->addItem(pointObj1);
    scene->addItem(pointObj2);

    pointObj1->setPen(pen_point);
    pointObj2->setPen(pen_point);
    LineObj->setPen(pen_line);




}

Line::~Line()
{
    delete pointObj1;
    delete pointObj2;
    delete LineObj;
}


void Line::clear()
{
    count = 0;
}


void Line::setObj()
{
    pointObj1 = new myQGraphicsEllipseItem(point1[0]-20+index,point1[1]-20+index,40-2*index,40-2*index);
    pointObj2 = new myQGraphicsEllipseItem(point2[0]-20+index,point2[1]-20+index,40-2*index,40-2*index);
    LineObj = new QGraphicsLineItem(point1[0],point1[1],point2[0],point2[1]);
    QGraphicsLineItem *Line_temp=new QGraphicsLineItem(point1[0],point1[1],point2[0],point2[1],LineObj);
    QPen pen_temp;
    pen_temp.setColor(QColor(255,255,255,50));
    pen_temp.setWidth(40);
    pen_temp.setCapStyle((Qt::RoundCap));
    Line_temp->setPen(pen_temp);

    QGraphicsEllipseItem *Elli_temp1=new QGraphicsEllipseItem
            (point1[0]-20+index/2,point1[1]-20+index/2,40-index,40-index,pointObj1);

    QPen pen_temp1;
    pen_temp1.setColor(QColor(255,253,207,200));
    pen_temp1.setWidth(3);
    pen_temp1.setCapStyle((Qt::RoundCap));
    Elli_temp1->setPen(pen_temp1);
    //Elli_temp1->setZValue(5);
    QGraphicsEllipseItem *Elli_temp2=new QGraphicsEllipseItem
            (point2[0]-20+index/2,point2[1]-20+index/2,40-index,40-index,pointObj2);

    Elli_temp2->setPen(pen_temp1);
   // Elli_temp1->setZValue(5);
}

void Line::reset()
{
    pen_line.setColor(color1);
    LineObj->setPen(pen_line);
}

void Line::play(class Info info1,class Info info2,int effect_temp)
{

    if( info1.pointMode >= 0 && info1.pointMode < 5)
    {

        int x1=point1[0],y1=point1[1],x2=point2[0],y2=point2[1];
        int x3=info1.x,y3=info1.y,x4=info2.x,y4=info2.y;
        int temp11 = ((y2-y1)*(x3-x1)-(x2-x1)*(y3-y1));
        int temp12 = ((y2-y1)*(x4-x1)-(x2-x1)*(y4-y1));
        int temp21 = ((y4-y3)*(x1-x3)-(x4-x3)*(y1-y3));
        int temp22 = ((y4-y3)*(x2-x3)-(x4-x3)*(y2-y3));
        if(temp11>0&&temp12>0||temp11<0&&temp12<0||
                temp21>0&&temp22>0||temp21<0&&temp22<0)
        {
            return;
        }
        player[info1.pointMode].play();
        player[info1.pointMode].setPosition(0);
        pen_line.setColor(color2);
        LineObj->setPen(pen_line);
        if(effect_temp==0){
            effect[0].play();
            effect[0].setPosition(0);
        }
        if(effect_temp==1){
            effect[1].play();
            effect[1].setPosition(0);
        }
    }

}

void Line::setpos(int index,int x,int y)//index 0/1
{

    if(index == 0)
    {
        point1[0] = x,point1[1] = y;
    }
    if(index == 16)
    {
        point2[0] = x,point2[1] = y;
    }
    delete pointObj1;
    delete pointObj2;
    delete LineObj;
    this->setObj();
    pointObj1->setPen(pen_point);
    pointObj2->setPen(pen_point);
    LineObj->setPen(pen_line);
    pointObj1->setZValue(-1);
    pointObj2->setZValue(-1);
    LineObj->setZValue(-1);
    scene->addItem(LineObj);
    scene->addItem(pointObj1);
    scene->addItem(pointObj2);
}

int Line::getcollection(int x,int y)
{
    if(x>point1[0]-20&&x<point1[0]+20&&y>point1[1]-20&&y<point1[1]+20)
        return 0;
    if(x>point2[0]-20&&x<point2[0]+20&&y>point2[1]-20&&y<point2[1]+20)
        return 1;
    return -1;
}

