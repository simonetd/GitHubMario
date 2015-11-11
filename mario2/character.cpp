#include "character.h"
#include "ennemy.h"
#include <QKeyEvent>
#include <stove.h>
#include <QGraphicsScene>
#include <floor.h>
#include <QTimer>
#include "game.h"
#include <typeinfo>
#include <QList>
#include <block.h>
#include "menu.h"

extern game * Game ;
extern menu * Menu;

character::character(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/peach right.png").scaled(25,25));
    grounded = 0;
    gravitys=0;
    once=0;
    QTimer * test = new QTimer();
    connect(test,SIGNAL(timeout()),this,SLOT(down()));
    test->start(50);

}

void character::keyPressEvent(QKeyEvent *event)
{
   if (event->key() == Qt::Key_U){
      qDebug() << this->boundingRect().width();
    qDebug() << this->boundingRect().height();
    qDebug() << this->boundingRect().x();
  qDebug() << this->boundingRect().y();
   }
    if (event->key() == Qt::Key_Escape){
        //game::game->hide();
        Menu->show();
        Game->close();
    }
    if (event->key() == Qt::Key_Q || event->key() == Qt::Key_Left){

        gauche=1;
        droite=0;

    }
    if (event->key() == Qt::Key_D && collisiondroite==0 || event->key() == Qt::Key_Right && collisiondroite==0){

        if (pos().x()+100<1200){
            gauche=0;
            droite=1;
            //game::view->centerOn(game::peach);
        }

    }
    if (event->key() == Qt::Key_Z || event->key() == Qt::Key_Up){
        if (grounded==1){
            gravitys=-15;
            grounded=0;
            gravity();

        }
    }
}




void character::down()
{
    grounded = 0;
    collisionhaut=0;
    collisiondroite=0;
    collisiongauche=0;

    QList<QGraphicsItem *> test3 = collidingItems();
    for (int i=0;i<test3.size();i++){
        if ( test3[i]->y() > this->y()+this->boundingRect().y()){
            grounded=1;
            gravitys=0;

          //  if(test3[i]->y()- this->boundingRect().height()-this->y() <2 ){
            //this->setPos(x(),test3[i]->y()-this->boundingRect().height());
          //     once=1;
          // }
        }
        if (test3[i]->y()+test3[i]->boundingRect().y()-this->y()<3){
            gravitys=0;
        }
        if (test3[i]->y()<this->y()+this->boundingRect().height()-10){
            if (test3[i]->x()>this->x()){
                collisiondroite=1;
            }
            else collisiongauche=1;
        }

    }
    gravity();


    if (droite==1 && collisiondroite==0){
        setPos(x()+4,y());
        once=0;
    }
    if (gauche==1 && collisiongauche==0){
        setPos(x()-4,y());
        once=0;
    }


}

void character::gravity()
{
    if (grounded==0 && gravitys<gravityspeedmax){
        gravitys=gravitys+2;
        this->setPos(x(),y()+gravitys);
    }

}


void character::keyReleaseEvent(QKeyEvent *event)
{
    if(!(event ->isAutoRepeat()))
    {
        if((event->key()==Qt::Key_Right || (event->key()== Qt::Key_Left) || event->key() == Qt::Key_Q || event->key() == Qt::Key_D))
        {
            droite=0;
            gauche=0;
        }
    }
}



