//这个写崩了orz别管了没啥用
#ifndef MYQGRAPHICSELLIPSEITEM_H
#define MYQGRAPHICSELLIPSEITEM_H
#include <QList>
#include <QMainWindow>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>

class myQGraphicsEllipseItem : public QGraphicsEllipseItem
{


    void dropEvent(QGraphicsSceneDragDropEvent *event);
    void mouseMoveEvent(QGraphicsSceneDragDropEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent * event);
    bool pressed;
    int x;
    int y;

public:
    myQGraphicsEllipseItem(qreal x, qreal y, qreal width, qreal height);


};

#endif // MYQGRAPHICSELLIPSEITEM_H
