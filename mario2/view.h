#ifndef VIEW_H
#define VIEW_H
#include "QGraphicsView"
#include "QGraphicsScene"
#include "controller.h"
#include "QObject"
#include "character.h"
#include "health.h"
#include "score.h"


class controller;

class view : public QGraphicsView
{
    Q_OBJECT
public:
    view();
    void setControl(controller *control){this->control = control;}
    void map();
    void menu();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
    void deleteItem(QGraphicsItem* item);
    health* getHealth(){return this->Life;}
    score* getScore(){return this->Jackpot;}
    void pieceSound();
    void jumpSound();
<<<<<<< HEAD
    QGraphicsScene* getscene(){return scene;}
=======
public slots:
    void jouer();
signals:
    void clicked();
>>>>>>> origin/master
private:
    controller *control;
    QGraphicsScene * scene;
    score * Jackpot;
    health * Life;
    QGraphicsScene * menuFont;

};

#endif // VIEW_H
