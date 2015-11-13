#ifndef STOVE_H
#define STOVE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class stove: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    stove(QGraphicsItem * parent=0);

signals:

private:
    unsigned short int range;
    unsigned short int rangemax;
public slots:
    void move();
};

#endif // STOVE_H
