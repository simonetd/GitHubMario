#include "controller.h"
#include "QObject"


controller::controller(model *m, view *v) : QObject()
{
    this->Model = m;
    this->View = v;
    this->View->setControl(this);
    v->map();
}

controller::~controller()
{

}
