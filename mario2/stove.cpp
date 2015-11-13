#include "stove.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <ennemy.h>
#include <typeinfo>
#include "game.h"
#include <QDebug>

extern game * Game;

stove::stove(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/turtle.png"));
    //100,50,10,10)
    range=0;
    rangemax=400;
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);


}

void stove::move()
{
   QList<QGraphicsItem *> colliding_items = collidingItems();
   for (int i=0, n = colliding_items.size(); i < n;i++){
       if(typeid(*(colliding_items[i])) == typeid(ennemy)){
           Game->Score->increase();
           scene()->removeItem(colliding_items[i]);
           scene()->removeItem(this);

           delete colliding_items[i];
           delete this;
           return;
            }
       }

   if(this->range<this->rangemax){
     setPos(x()+10,y());
     range=range+10;
               }
   else delete this;
}

