#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>


class Bullet: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Bullet();
    void keyPressEvent(QKeyEvent * event);
    void seti();
    int i;
public slots:
    void move();

};

#endif // BULLET_H
