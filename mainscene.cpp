//Birdy 17.10.27
#include "mainscene.h"


MainScene::MainScene()
    :point_count(0),pointMode(0),effect_index(-1),checkMode(false)

{

    QPixmap pixmap1("E:/Code/musicplayer/pic/10.png");
    backpicture = new QGraphicsPixmapItem(pixmap1);

    Scene.addItem(backpicture);

    for(int i=0;i<10;i++)
     {
        line[i]= new class Line(100*i+100,50,100*i+100,500,i,&Scene,i);
    }
    for(int i=0;i<50;i++)
     {
        points[i]= new class Points(&Scene);

    }


    connect(&timer, SIGNAL(timeout()), this, SLOT(updateMusic()));
    timer.start(50);
}


MainScene::~MainScene()
{
    delete backpicture;
    for(int i=0;i<10;i++)
     {
        delete line[i];
    }
    for(int i=0;i<50;i++)
     {
        delete points[i];
    }

}



void MainScene::addPoint(int x,int y)
{
    if(active_num == -1)
    {
        points[point_count]->addPoint(x,y);

        class Info info1,info2;
        points[point_count]->getStep(info1,info2);
        for(int j=0;j<10;j++)
        {
            line[j]->play(info1,info2,effect_index);
        }
    }
    else
        line[active_num&15]->setpos(active_num&16,x,y);
}


void MainScene::finish()
{
    if(active_num == -1){
        if(points[point_count]->finish())
        {
            point_count++;
        }
        if(true==checkMode)
        {
            clearScene();
        }
    }
}


void MainScene::start(int x,int y)
{
    for(int i=0;i<10;i++)
     {
        int temp = line[i]->getcollection(x,y);
        if(temp == 0)
        {
            active_num = i;
            return;
        }
        else if(temp == 1)
        {
            active_num = i | 16;
            return;
        }

    }
    active_num = -1;
    points[point_count]->setInit(pointMode);
}

void MainScene::clearScene()
{

    for(int i=0;i<point_count;i++)
    {
        points[i]->clear(Scene);
    }
    point_count = 0;

}


void MainScene::updateMusic()
{
    //timer.singleShot(200, this, SLOT(updateMusic()));
    for(int j=0;j<10;j++)
    {
        line[j]->reset();
    }

    for(int i=0;i<point_count;i++)
    {
        class Info info1,info2;
        points[i]->nextStep(info1,info2);
        for(int j=0;j<10;j++)
        {
            line[j]->play(info1,info2,effect_index);
        }
    }

}

