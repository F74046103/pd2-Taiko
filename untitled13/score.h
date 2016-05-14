#ifndef SCORE_H
#define SCORE_H
#include<QGraphicsTextItem>
#include<QObject>
#include<QTimer>
class score:public QGraphicsTextItem
{
    Q_OBJECT
public:
    score();
    int s;
    int gets();
    void increase();
};
#endif // SCORE_H
