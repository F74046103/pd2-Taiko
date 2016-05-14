#ifndef TIME_H
#define TIME_H
#include<QGraphicsTextItem>
#include<QObject>
#include<QTimer>
class time:public QGraphicsTextItem
{
    Q_OBJECT
public:
    time();
    int t;
    int gett();
    QTimer * timer;
public slots:
    void decrease();
};

#endif // TIME_H
