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

extern game * Game;

ennemy::ennemy()
{
    setPixmap(QPixmap(":/images/ennemy.png").scaled(25,25));
    direction=rand()%true;
}



