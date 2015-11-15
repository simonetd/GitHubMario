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
<<<<<<< Updated upstream
    setgravitys(0);
}

void ennemy::changedirection()
{
    this->direction = !direction;
=======
    grounded = 1;
    gravitys = 0;
>>>>>>> Stashed changes
}

void ennemy::setDirection(bool newDirection)
{
    this->direction=newDirection;
}

void ennemy::setgravitys(int a)
{
this->gravitys = a;
}

void ennemy::setgrounded(bool b)
{
this->grounded = b;
}

