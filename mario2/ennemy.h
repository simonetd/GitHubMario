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
    bool getdirection(){return direction;}
private:
    bool direction;
signals:
public slots:
};

#endif // ENNEMY_H
