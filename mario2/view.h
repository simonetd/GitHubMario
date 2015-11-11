#ifndef VIEW_H
#define VIEW_H
#include "QGraphicsView"
#include "QGraphicsScene"
#include "controller.h"
#include "QObject"


class controller;

class view : public QGraphicsView
{
public:
    view();
    void setControl(controller *control){this->control = control;}
    void map();
private:
    controller *control;
};

#endif // VIEW_H
