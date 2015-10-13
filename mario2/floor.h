#ifndef FLOOR_H
#define FLOOR_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class floor: public QObject, public QGraphicsPixmapItem
{

   Q_OBJECT
public:
    floor(QGraphicsItem * parent=0);

signals:
private:


public slots:
};

#endif // FLOOR_H
