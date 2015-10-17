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
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void ennemy::move()
{
    down();
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0, n = colliding_items.size(); i < n;i++){
        if(typeid(*(colliding_items[i])) == typeid(character)){
            Game->Health->decrease();
            scene()->removeItem(this);
            delete this;
            return;}
        }
    if(pos().x()<=0 || pos().x()+100>=1200 || collisiondroite == 1 || collisiongauche==1){
        direction=!direction;

    }
    if(this->direction==1){
        setPos(x()+3,y());

    }
    if(this->direction==0) {
        setPos(x()-3,y());
    }
}

