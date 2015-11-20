#ifndef VIEW_H
#define VIEW_H
#include "QGraphicsView"
#include "QGraphicsScene"
#include "controller.h"
#include "QObject"
#include "character.h"
#include "health.h"
#include "score.h"
#include <QPushButton>


class controller;

class view : public QGraphicsView
{
    Q_OBJECT
public:
    view();
    void setControl(controller *control){this->control = control;}
    void map();
    void createmap();
    void menu();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
    void deleteItem(QGraphicsItem* item);
    health* getHealth(){return this->Life;}
    score* getScore(){return this->Jackpot;}
    void pieceSound();
    void jumpSound();
    bool getready(){return this->ready;}
    QGraphicsScene* getscene(){return scene;}
    void gameOver();
    void youLose();
public slots:
    void jouer();
signals:
    void clicked();
private:
    controller *control;
    QGraphicsView* view2;
    QGraphicsView* window;
    QGraphicsScene * scene;
    score * Jackpot;
    health * Life;
    QGraphicsScene * menuFont;
    QPushButton *boutonQuitter ;
    QPushButton *boutonJouer;
    bool ready;
    QGraphicsScene * endFont;



};

#endif // VIEW_H
