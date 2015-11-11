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

    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(600,300);
    scene->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
    for (int i=0; i<control->getmodel()->getFlors()->size();i++){
         scene->addItem(control->getmodel()->getFlors()->at(i));
     }
    view->show();
}

