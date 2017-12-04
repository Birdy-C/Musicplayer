#include "myqgraphicsellipseitem.h"

myQGraphicsEllipseItem::myQGraphicsEllipseItem(qreal x, qreal y, qreal width, qreal height)
    : QGraphicsEllipseItem(x,y,width,height),pressed(false)
{
    this->setAcceptDrops(true);
    this->setFlag(QGraphicsItem::ItemIsMovable);
    this->setAcceptHoverEvents(true);
    this->setAcceptedMouseButtons(Qt::LeftButton);

}

void myQGraphicsEllipseItem::mouseMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    event->accept();
    if(pressed == true)
    {
        QPointF point = event->pos();
        this->setX(this->x+point.x()-x);
        this->setY(this->y+point.y()-y);
        x = point.x();
        y = point.y();
    }
}

void myQGraphicsEllipseItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    event->accept();
    pressed = true;
    QPointF point = event->pos();
    x = point.x();
    y = point.y();
}

void myQGraphicsEllipseItem::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    pressed = false;

}

void myQGraphicsEllipseItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = false;

}
void myQGraphicsEllipseItem::hoverMoveEvent(QGraphicsSceneHoverEvent * event)
{
    event->accept();
    if(pressed == true)
    {
        QPointF point = event->pos();
        this->setX(this->x+point.x()-x);
        this->setY(this->y+point.y()-y);
        x = point.x();
        y = point.y();
    }

}
