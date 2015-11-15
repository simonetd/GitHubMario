#include "ennemy.h"
#include "game.h"
#include "character.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <character.h>
#include <typeinfo>
#include <QString>
#include <floor.h>


ennemy::ennemy()
{
    setPixmap(QPixmap(":/images/ennemy.png").scaled(25,25));
    direction=rand()%true;
    setgravitys(0);
}

void ennemy::changedirection()
{
    this->direction = !direction;
}
