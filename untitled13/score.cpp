#include "score.h"
#include<QFont>
#include<QTimer>
#include<QGraphicsScene>
score::score()
{
    s=0;
    setPlainText(QString("Score: ") + QString::number(s));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
    setPos(0,50);
}

int score::gets()
{
    return s;
}

void score::increase()
{
    s++;
    setPlainText(QString("Score: ") + QString::number(s));
}
