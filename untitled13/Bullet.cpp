#include "Bullet.h"
#include <QTimer>
#include<QBrush>
#include<QGraphicsScene>
#include<QKeyEvent>
#include<stdlib.h>
#include"game.h"

extern Game *game;

Bullet::Bullet(){
    seti();
    setRect(0,0,70,70);
    if(i==1)
    setBrush(QBrush(Qt::blue));
    if(i==2)
    setBrush(QBrush(Qt::red));
    if(i==3)
    setBrush(QBrush(Qt::green));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_1&&i==1){
            if(pos().x()>0&&pos().x()<175){
               game->point->increase();
            }
            if(pos().x()<800&&pos().x()>0){
                clearFocus();
               setPos(-750,180);
            }
        }
    if (event->key() == Qt::Key_2&&i==2){
            if(pos().x()>100&&pos().x()<175){
               game->point->increase();
            }
            if(pos().x()<800&&pos().x()>0){
               clearFocus();
               setPos(-750,180);
            }
    }
    if (event->key() == Qt::Key_3&&i==3){
            if(pos().x()>100&&pos().x()<175){
               game->point->increase();
            }
            if(pos().x()<800&&pos().x()>0){
               clearFocus();
               setPos(-750,180);
            }
    }
}

void Bullet::seti()
{
    i=rand()%3+1;
}

void Bullet::move(){
    setPos(x()-20,y());

}
