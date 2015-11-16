#include "controller.h"
#include "QObject"
#include <typeinfo>
#include <QList>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include "health.h"
#include "score.h"
#include "bonus.h"
#include "cake.h"


controller::controller(model *m, view *v) : QObject()
{
    this->Model = m;
    this->View = v;
    this->View->setControl(this);
    v->map();
    gravityspeedmax=15;

    QTimer * TimerPeach = new QTimer();
    QObject::connect(TimerPeach,SIGNAL(timeout()),this,SLOT(down()));
    TimerPeach->start(50);

    QTimer * TimerEnnemys = new QTimer();
    QObject::connect(TimerEnnemys,SIGNAL(timeout()),this,SLOT(move()));
    TimerEnnemys->start(50);
}

controller::~controller()
{

}

void controller::moveMarioLeft(){
    gauche=1;
    droite=0;
    Model->getPeach()->peachleft();
}

void controller::moveMarioRight(){
    gauche=0;
    droite=1;
    Model->getPeach()->peachright();
}

void controller::moveMarioJump()
{
    if (Model->getPeach()->getgrounded()== true){
        Model->getPeach()->setgravitys(-15);
        Model->getPeach()->setgrounded(false);
        View->jumpSound();
        gravity(Model->getPeach());
    }
}

void controller::MarioStand()
{
    droite=0;
    gauche=0;
}

void controller::gravity(character* item)
{
    if (item->getgrounded()== false && item->getgravitys()<gravityspeedmax){
        item->setgravitys(item->getgravitys()+2);
        item->setY(item->y() + item->getgravitys());
    }
}

void controller::down()
{
    Model->getPeach()->setgrounded(false);
    Model->getPeach()->setcollisiondroite(0);
    Model->getPeach()->setcollisiongauche(0);
    QList<QGraphicsItem *> test3 = Model->getPeach()->collidingItems();
    for (int i=0;i<test3.size();i++){
        if ( test3[i]->y() > Model->getPeach()->y()+Model->getPeach()->boundingRect().y()){
            Model->getPeach()->setgrounded(true);
            Model->getPeach()->setgravitys(0);
        }
        if (test3[i]->y()+test3[i]->boundingRect().y()-Model->getPeach()->y()<3){
            Model->getPeach()->setgravitys(0);
            if(typeid(*(test3[i])) == typeid(bonus)){
                for (int k=0;k<Model->getBonuss()->length();k++){
                    if (Model->getBonuss()->at(i)==(test3[i])){
                        if (Model->getBonuss()->at(i)->getemptybonus()==0){
                            Model->getBonuss()->at(i)->emptybonus();
                            cake * cakke = new cake();
                            cakke->setPos(Model->getBonuss()->at(i)->x()+2.5,Model->getBonuss()->at(i)->y()-25);
                            View->getscene()->addItem(cakke);
                        }
                    }
                }
            }
        }
        if(typeid(*(test3[i])) == typeid(cake)){
           Model->getPeach()->setScale(1.25);
           View->deleteItem(test3[i]);
           delete test3[i];
}
        if (test3[i]->y()<Model->getPeach()->y()+Model->getPeach()->boundingRect().height()-10){
            if (test3[i]->x() > Model->getPeach()->x()){
                Model->getPeach()->setcollisiondroite(1);
            }
            else Model->getPeach()->setcollisiongauche(1);
        }
        if(typeid(*(test3[i])) == typeid(piece)){
            for (int k=0;k<Model->getPieces()->length();k++){
                if (Model->getPieces()->at(i)==(test3[i])){
                    Model->getPieces()->removeAt(i);
                }
            }
            View->deleteItem(test3[i]);
            delete test3[i];
            View->getScore()->increase();
            View->pieceSound();

        }
    }
    gravity(Model->getPeach());
    if (droite==1 && Model->getPeach()->getcollisiondroite()==0){
        Model->getPeach()->setX(Model->getPeach()->x()+4);
    }
    if (gauche==1 && Model->getPeach()->getcollisiongauche()==0){
        Model->getPeach()->setX(Model->getPeach()->x()-4);
    }
}


void controller::move()
{

    for (int i=0; i<Model->getEnnemys()->length();i++){
        Model->getEnnemys()->at(i)->setgrounded(false);
        if(Model->getEnnemys()->at(i)->getdirection()==1){
            Model->getEnnemys()->at(i)->setX(Model->getEnnemys()->at(i)->x()+3);
        }
        if(Model->getEnnemys()->at(i)->getdirection()==0) {
            Model->getEnnemys()->at(i)->setX(Model->getEnnemys()->at(i)->x()-3);
        }

        QList<QGraphicsItem *> colliding_items = Model->getEnnemys()->at(i)->collidingItems();
        for (int k=0, n = colliding_items.size(); k < n;k++){

            if ( colliding_items[k]->y() > Model->getEnnemys()->at(i)->y()+Model->getEnnemys()->at(i)->boundingRect().y()){
                Model->getEnnemys()->at(i)->setgrounded(true);
                Model->getEnnemys()->at(i)->setgravitys(0);
            }
            if(Model->getEnnemys()->at(i)->y() >= colliding_items[k]->y() + colliding_items[k]->boundingRect().y()){
                Model->getEnnemys()->at(i)->changedirection();
            }
            if(typeid(*(colliding_items[k])) == typeid(character) || Model->getEnnemys()->at(i)->y() > 300){
               // Rajouter Collision Haut pr delete l'ennemy et si collision haut ne pas decrease
               View->deleteItem(Model->getEnnemys()->at(i));
                delete Model->getEnnemys()->at(i);
                Model->getEnnemys()->removeAt(i);
                View->getHealth()->decrease();
                return;}
        }
           gravity(Model->getEnnemys()->at(i));
}
}
