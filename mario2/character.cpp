#include "character.h"
#include "ennemy.h"
#include <QKeyEvent>
#include <stove.h>
#include <QGraphicsScene>
#include <floor.h>
#include <QTimer>
#include <game.h>
#include <typeinfo>
#include <QList>
#include <block.h>
#include "menu.h"

extern game * Game ;
extern menu * Menu;

character::character(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/peach right.png"));
    grounded = 0;
    gravitys=0;
    once=0;
    QTimer * test = new QTimer();
    connect(test,SIGNAL(timeout()),this,SLOT(down()));
    test->start(50);

}

void character::keyPressEvent(QKeyEvent *event)
{
     if (event->key() == Qt::Key_Escape){
         //game::game->hide();
         Menu->show();
         Game->close();
     }
     if (event->key() == Qt::Key_Q || event->key() == Qt::Key_Left){
             setPos(x()-8,y());

     }
      if (event->key() == Qt::Key_D && droite==0 || event->key() == Qt::Key_Right && droite==0){

         if (pos().x()+100<1200)
         setPos(x()+5,y());
         once=0;
     }
     if (event->key() == Qt::Key_Space){
         // create a stove
         stove * Stove = new stove();
         Stove->setPos(x()+51,y()+80);
         stovesound= new QMediaPlayer();
         stovesound->setMedia(QUrl("qrc:/sounds/sm64_impact.wav"));
         scene()->addItem(Stove);
         if (stovesound->state() == QMediaPlayer::PlayingState){
             stovesound->setPosition(0);
         }
         else if (stovesound->state() == QMediaPlayer::StoppedState){
         stovesound->play();
         }

    }
      if (event->key()== Qt::Key_A){
         ennemy * Wario = new ennemy();
         scene()->addItem(Wario);
     }
     if (event->key() == Qt::Key_Z || event->key() == Qt::Key_Up){
         if (grounded==1){
             gravitys=-15;
            qDebug() << "Jump";
            grounded=0;
            gravity();

         }
     }
}




void character::down()
    {
    grounded = 0;
    haut=0;
    droite=0;
    gauche=0;
    QList<QGraphicsItem *> test3 = collidingItems();
    for (int i=0;i<test3.size();i++){
        if ( test3[i]->y() > this->y()+this->boundingRect().y()){
            grounded=1;
            gravitys=0;
            if(once==0 && (test3[i]->y()-this->boundingRect().height()-this->y()<5)){
                qDebug() << "Repositionnement";
            this->setPos(x(),test3[i]->y()-this->boundingRect().height());
            once=1;}
        }
       if (test3[i]->y()<this->y()+this->boundingRect().height()-10){
         if (test3[i]->x()>this->x()){
              droite=1;
            }
            else gauche=1;
        }
       }
      gravity();
    }


void character::gravity()
{
    if (grounded==0 && gravitys<gravityspeedmax){
    gravitys=gravitys+2;
    this->setPos(x(),y()+gravitys);
    }

}


