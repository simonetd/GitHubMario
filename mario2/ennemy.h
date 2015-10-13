#ifndef ENNEMY_H
#define ENNEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <stdlib.h>
#include <QGraphicsItem>
#include <ctime>

class ennemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ennemy(QGraphicsItem * parent=0);

private:
    bool direction=rand()%true;
signals:
public slots:
        void move();
};

#endif // ENNEMY_H
        void move();
