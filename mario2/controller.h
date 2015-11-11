#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "model.h"
#include "view.h"

class view;

class controller : QObject
{
    Q_OBJECT
public:
    controller(model *m,view *v);
    ~controller();
    inline model *getmodel(){return this->Model;}

private:
    model *Model;
    view *View;

};

#endif // CONTROLLER_H
