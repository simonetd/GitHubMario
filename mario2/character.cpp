#include "character.h"
#include "ennemy.h"
#include <stove.h>
#include <QGraphicsScene>
#include <floor.h>
#include <QTimer>
#include "game.h"
#include "controller.h"
#include <block.h>
#include "menu.h"

extern game * Game ;
extern menu * Menu;

character::character(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/peach right.png").scaled(25,25));
    grounded = 0;
    gravitys=0;

}

void character::setgravitys(int a)
{
    this->gravitys = a;
}

void character::setgrounded(bool b)
{
    this->grounded = b;
}


