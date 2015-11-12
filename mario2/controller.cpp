#include "controller.h"
#include "QObject"
#include <typeinfo>
#include <QList>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>


controller::controller(model *m, view *v) : QObject()
{
    this->Model = m;
    this->View = v;
    this->View->setControl(this);
    v->map();

    QTimer * testDown = new QTimer();
    QObject::connect(testDown,SIGNAL(timeout()),this,SLOT(down()));
    testDown->start(50);
}

controller::~controller()
{

}

void controller::moveMarioLeft(){
    gauche=1;
    droite=0;
}

void controller::moveMarioRight(){
    gauche=0;
    droite=1;
    Model->getPeach()->setPos(Model->getPeach()->x()+5,Model->getPeach()->y());
//    View->update();
    qDebug()<<"moveRight";
}

void controller::moveMarioJump()
{
    if (Model->getPeach()->getgrounded()== true){
        Model->getPeach()->setgravitys(-15);
        Model->getPeach()->setgrounded(false);
        gravity();
    }
}

void controller::MarioStand()
{
    droite=0;
    gauche=0;
}

void controller::gravity()
{
    if (Model->getPeach()->getgrounded()== false && Model->getPeach()->getgravitys()<gravityspeedmax){
        Model->getPeach()->setgravitys(2);
        Model->getPeach()->setY(Model->getPeach()->y() + Model->getPeach()->getgravitys());
    }
}

void controller::down()
{
    Model->getPeach()->setgrounded(false);
    collisionhaut=0;
    collisiondroite=0;
    collisiongauche=0;
    QList<QGraphicsItem *> test3 = Model->getPeach()->collidingItems();
    for (int i=0;i<test3.size();i++){
        if ( test3[i]->y() > Model->getPeach()->y()+Model->getPeach()->boundingRect().y()){
            Model->getPeach()->setgrounded(true);
            Model->getPeach()->setgravitys(0);
        }
        if (test3[i]->y()+test3[i]->boundingRect().y()-Model->getPeach()->y()<3){
            Model->getPeach()->setgravitys(0);
        }
        if (test3[i]->y()<Model->getPeach()->y()+Model->getPeach()->boundingRect().height()-10){
            if (test3[i]->x() > Model->getPeach()->x()){
                collisiondroite=1;
            }
            else collisiongauche=1;
        }
    }
    gravity();
    if (droite==1 && collisiondroite==0){
        Model->getPeach()->setX(Model->getPeach()->x()+4);
    }
    if (gauche==1 && collisiongauche==0){
        Model->getPeach()->setX(Model->getPeach()->x()-4);
    }
}

