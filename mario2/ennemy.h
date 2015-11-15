#ifndef ENNEMY_H
#define ENNEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <stdlib.h>
#include <QGraphicsItem>
#include <ctime>
#include <character.h>

class ennemy: public character
{
    Q_OBJECT
public:
    ennemy();
    bool getdirection(){return direction;}
<<<<<<< Updated upstream
    void changedirection();
=======
    void setDirection(bool);
    void setgrounded(bool b);
    bool getgrounded(){return grounded;}
    void setgravitys(int a);
    int getgravitys(){return gravitys;}
>>>>>>> Stashed changes
private:
    bool direction;
    bool grounded;
    int gravitys;
};

#endif // ENNEMY_H
