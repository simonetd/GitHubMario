#ifndef VIEW_H
#define VIEW_H
#include "QGraphicsView"
#include "QGraphicsScene"
#include "controller.h"
#include "QObject"
#include "character.h"


class controller;

class view : public QGraphicsView
{
public:
    view();
    void setControl(controller *control){this->control = control;}
    void map();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
    void deleteItem(ennemy* item);
private:
    controller *control;
};

#endif // VIEW_H
