#include "character.h"
#include "ennemy.h"
#include <QGraphicsScene>
#include <floor.h>
#include <QTimer>
#include "controller.h"
#include <block.h>


character::character(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/Peach/Peach2.png"));
    grounded = false;
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

void character::setcollisiondroite(int c)
{
    this->collisiondroite = c;
}

void character::setcollisiongauche(int d)
{
    this->collisiongauche = d;
}

void character::peachleft()
{
   setPixmap(QPixmap(":/images/Peach/Peach1.png"));
}

void character::peachright()
{
    setPixmap(QPixmap(":/images/Peach/Peach2.png"));
}


