#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include<QGraphicsPixmapItem>
#include"Bullet.h"
#include"bullet2.h"
#include"game.h"
#include<QDebug>
#include<stdlib.h>
#include<QTimer>
#include"time.h"

Game::Game(QWidget *parent){

    scene=new QGraphicsScene;
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    item2=new QGraphicsPixmapItem;
    item2->setPixmap(QPixmap(":/image/1.png"));
    item2->setScale(1.5);
    scene->addItem(item2);
    push[0]=new QPushButton("start");
    push[1]=new QPushButton("exit");
    proxy[0]=scene->addWidget(push[0]);
    proxy[1]=scene->addWidget(push[1]);
    proxy[0]->setPos(200,300);
    proxy[1]->setPos(500,300);
    QObject::connect(push[0],SIGNAL(clicked()),this,SLOT(made()));
    QObject::connect(push[1],SIGNAL(clicked()),this,SLOT(close()));
    show();
}

void Game::set()
{   for(int i=1;i<60;i++){
       if(b[i-1]->pos().x()<0&&b[i]->pos().x()>0){
           b[i]->setFocus();
       }
    }
}

void Game::made()
{   int i,j=0;
    scene->removeItem(proxy[0]);
    scene->removeItem(proxy[1]);
    scene->removeItem(item2);
    item=new QGraphicsPixmapItem;
    item->setPixmap(QPixmap(":/image/bg.png"));
    item->setScale(1.55);
    scene->addItem(item);
    rect=new QGraphicsRectItem;
    rect->setRect(100,180,75,75);
    rect->setBrush(QBrush(Qt::white));
    scene->addItem(rect);
    for(i=0;i<60;i++){
        b[i]=new Bullet;
        b[i]->setPos(800+j,182);
        scene->addItem(b[i]);
        j=j+100*(rand()%3+1);
    }
    for(i=0;i<60;i++){
        b[i]->setFlag(QGraphicsItem::ItemIsFocusable);
    }
    b[0]->setFocus();
    QTimer * t = new QTimer();
    connect(t,SIGNAL(timeout()),this,SLOT(set()));
    t->start(50);
    clk=new time;
    connect(t,SIGNAL(timeout()),this,SLOT(checkt()));
    scene->addItem(clk);
    scene->removeItem(point);
    point=new score;
    scene->addItem(point);
}

void Game::checkt()
{   int i;
    if(clk->gett()==0){
        for(i=0;i<60;i++){
            scene->removeItem(b[i]);
        }
        scene->removeItem(clk);
        scene->removeItem(item);
        scene->removeItem(rect);
        push[0]->setText("restart");
        scene->addItem(proxy[0]);
        scene->addItem(proxy[1]);
        point->setPos(350,200);
    }
}
