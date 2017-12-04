//Birdy 17.10.10
#include "points.h"

Points::Points(QGraphicsScene *mscene):count(0),index(0),ball(0,0,10,10)
{
    scene = mscene;
    group_line = new QGraphicsEllipseItem;
    group_line2 = new QGraphicsEllipseItem;
    QPen pen_temp;
    pen_temp.setColor(QColor(220,220,255,200));
    pen_temp.setWidth(4);
    ball.setPen(pen_temp);
    scene->addItem(group_line2);
    scene->addItem(group_line);
    scene->addItem(&ball);

    for(int i = 0;i<5;i++)
    {
        color[i] = QColor(100+15*i,100+15*i,255);
        color2[i] = QColor(150+15*i,150+15*i,255,100);
    }
    color[0] = QColor(250,100,100);
    color2[0] = QColor(250,100,100,100);

    color[3] = QColor(100,100,100);
    color2[3] = QColor(100,100,100,100);

    ball.setVisible(0);
    pen.setWidth(5);
    pen.setCapStyle(Qt::RoundCap);
    pen2.setWidth(10);
    pen2.setCapStyle(Qt::FlatCap);
}

Points::~Points()
{
    delete group_line;
}


bool Points::addPoint(const int t_x,const int t_y)
{
    if(5000 == count)
    {
        QMessageBox::warning(0,QObject::tr("Sorry"),"Can't put in more than 100 points");
        return false;
    }

    if(count > 0)
    {
       QGraphicsLineItem *temp =  new QGraphicsLineItem(t_x,t_y,pointX[count-1],pointY[count-1],group_line);
       temp->setPen(pen);
       QGraphicsLineItem *temp2 =  new QGraphicsLineItem(t_x,t_y,pointX[count-1],pointY[count-1],group_line2);
       temp2->setPen(pen2);
    }
    pointX[count] = t_x;
    pointY[count] = t_y;
    count++;
    return true;

}


void Points::clear(QGraphicsScene &mScene)
{
    count = 0;
    index = 0;
    ball.setVisible(0);

    QList<QGraphicsItem *> list_line = group_line2->childItems();
    for ( int i=0; i!=list_line.size(); i++ )
    {
        mScene.removeItem(list_line.at(i));
    }
}


void Points::setInit(int temp)
{
    pointMode = temp;
    pen.setColor(color[temp]);
    pen2.setColor(color2[temp]);


}

bool Points::finish()
{
    if(count == 1 )
    {
        count = 0;
        return false;
    }

     ball.setX(pointX[0]-5);
     ball.setY(pointY[0]-5);
     ball.setVisible(1);
     ball.setPen(pen);

     QList<QGraphicsItem *>list_line = group_line->childItems();
     for ( int i=0; i!=list_line.size(); i++ )
     {
         scene->removeItem(list_line.at(i));
     }
     return true;
}

void Points::nextStep(class Info &info1,class Info &info2)
{
    info1.pointMode = info2.pointMode = pointMode;
    if(index == count-1)
    {
        index = 0;
        info1.x=info2.x=pointX[0];
        info1.y=info2.y=pointY[0];
    }
    else
    {
        info1.x=pointX[index];
        info1.y=pointY[index];
        index++;
        info2.x=pointX[index];
        info2.y=pointY[index];
        ball.setX(pointX[index]-5);
        ball.setY(pointY[index]-5);
    }
}



void Points::getStep(class Info &info1,class Info &info2)
{
    info1.pointMode = info2.pointMode = pointMode;
    if(0 == count-1)
    {
        index = 0;
        info1.x=info2.x=pointX[0];
        info1.y=info2.y=pointY[0];

    }
    else
    {
        info1.x=pointX[count-2];
        info1.y=pointY[count-2];
        index++;
        info2.x=pointX[count-1];
        info2.y=pointY[count-1];
    }
}

