#include "view.h"
#include "controller.h"
#include "model.h"



view::view()
{



}

void view::map()
{
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,300);
    setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(600,300);
    for (int i=0; i<control->getmodel()->getFlors()->size();i++){
         scene->addItem(control->getmodel()->getFlors()->at(i));
     }
    view->show();
}

