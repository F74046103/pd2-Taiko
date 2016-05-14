#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include<QPushButton>
#include<QGraphicsPixmapItem>
#include<QGraphicsProxyWidget>
#include"Bullet.h"
#include"time.h"
#include"score.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);
    QPushButton *push[2];
    QGraphicsProxyWidget *proxy[2];
    QGraphicsScene * scene;
    QGraphicsPixmapItem *item;
    QGraphicsPixmapItem *item2;
    Bullet *b[60];
    time *clk;
    score *point;
    QGraphicsRectItem *rect;

public slots:
    void set();
    void made();
    void checkt();
};

#endif // GAME_H
