#include "view.h"
#include "controller.h"
#include "model.h"
#include <QKeyEvent>
#include <QDebug>



view::view()
{
    this->grabKeyboard();


}

void view::map()
{
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,300);
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(600,300);
    scene->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
    for (int i=0; i<control->getmodel()->getFlors()->size();i++){
         scene->addItem(control->getmodel()->getFlors()->at(i));
    }
    for (int i=0; i<control->getmodel()->getBlocks()->size();i++){
         scene->addItem(control->getmodel()->getBlocks()->at(i));
    }
    for (int i=0; i<control->getmodel()->getBonuss()->size();i++){
         scene->addItem(control->getmodel()->getBonuss()->at(i));
    }
    for (int i=0; i<control->getmodel()->getBriques()->size();i++){
         scene->addItem(control->getmodel()->getBriques()->at(i));
    }
    for (int i=0; i<control->getmodel()->getEnnemys()->size();i++){
         scene->addItem(control->getmodel()->getEnnemys()->at(i));
    }
    scene->addItem(control->getmodel()->getPeach());
    centerOn(control->getmodel()->getPeach());
    view->show();
}

void view::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Q:
    case Qt::Key_Left:
        control->moveMarioLeft();
        break;
    case Qt::Key_D:
    case Qt::Key_Right:
        control->moveMarioRight();
        qDebug()<<"droite pressee";
        break;
    case Qt::Key_Z:
    case Qt::Key_Up:
    case Qt::Key_Space:
        control->moveMarioJump();
        qDebug()<<"saut presse";
        break;
 //   this->update();
    }

//    if (event->key() == Qt::Key_Q || event->key() == Qt::Key_Left){
//        control->moveMarioLeft();
//    }
//    if (event->key() == Qt::Key_D|| event->key() == Qt::Key_Right){
//        control->moveMarioRight();
//    }
//    if (event->key() == Qt::Key_Z || event->key() == Qt::Key_Up){
//        control->moveMarioJump();
//    }
}

void view::keyReleaseEvent(QKeyEvent *event)
{
    if(!(event ->isAutoRepeat()))
    {
        if((event->key()==Qt::Key_Right || (event->key()== Qt::Key_Left) || event->key() == Qt::Key_Q || event->key() == Qt::Key_D))
        {
           control->MarioStand();
        }
        control->MarioStand();
    }
}
