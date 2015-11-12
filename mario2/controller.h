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
    void gravity();

public slots:
    void down();
private:
    model *Model;
    view *View;
    int stand;
    int droite;
    int gauche;
    int gravityspeedmax=15;
    int once;
    int collisionhaut=0;
    int collisiondroite=0;
    int collisiongauche=0;

};

#endif // CONTROLLER_H
