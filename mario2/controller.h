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
    void moveMarioLeft();
    void moveMarioRight();
    void moveMarioJump();
    void MarioStand();
    void gravity(character* item);
public slots:
    void down();
    void move();
private:
    model *Model;
    view *View;
    int stand;
    int droite;
    int gauche;
    int direction;
    int gravityspeedmax;
    int once;
    int collisionhaut;


};

#endif // CONTROLLER_H
