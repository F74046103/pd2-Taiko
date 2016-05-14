#include "time.h"
#include<QFont>
#include<QTimer>
#include<QGraphicsScene>

time::time()
{
    t=30;
    setPlainText(QString("Time: ") + QString::number(t));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(decrease()));
    timer->start(1000);
}

int time::gett()
{
    return t;
}

void time::decrease()
{
    t--;
    setPlainText(QString("Time: ") + QString::number(t));
}
