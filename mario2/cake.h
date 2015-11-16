#ifndef CAKE_H
#define CAKE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class cake: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    cake(QGraphicsItem * parent=0);

signals:

public slots:
};

#endif // CAKE_H
