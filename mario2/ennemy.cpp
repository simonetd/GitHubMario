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

ennemy::ennemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //qsrand(timer(NULL));
    int random_numberx=rand() %1200;
//    while (random_numberx>((Game->peach->x())+200)){
//        random_numberx=rand() %1200;
//    }
//    qDebug() << "Ok" << Game->peach->x();
    setPos(random_numberx,500);
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":/images/ennemy.png"));
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void ennemy::move()
{
   QList<QGraphicsItem *> colliding_items = collidingItems();
   for (int i=0, n = colliding_items.size(); i < n;i++){
        if(typeid(*(colliding_items[i])) == typeid(character)){
            Game->Health->decrease();
            scene()->removeItem(this);
            delete this;
        return;}
            if(typeid(*(colliding_items[i])) != typeid(floor)){
                this->setPos(x(),y()+2);
            }
            if (Game->Health->gethealth()==0){
// Besoin d'aide pour Stoper le jeu avec une nouvelle fenetre
 //           scene()->removeItem(Game->peach);
            }

             }


   if(pos().x()<=0 || pos().x()+100>=1200){
     direction=!direction;

   }
   if(this->direction==1){
       setPos(x()+3,y());

   }
   if(this->direction==0) {
       setPos(x()-3,y());
   }
}

