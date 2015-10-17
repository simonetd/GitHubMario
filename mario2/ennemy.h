#ifndef ENNEMY_H
#define ENNEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <stdlib.h>
#include <QGraphicsItem>
#include <ctime>
#include <character.h>

class ennemy: public character
{
    Q_OBJECT
public:
    ennemy();

private:
    bool direction=rand()%true;
signals:
public slots:
        void move();
};

#endif // ENNEMY_H
        void move();
