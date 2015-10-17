#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "character.h"
#include "score.h"
#include "health.h"

class game: public QGraphicsView{
public slots:
    void focuspeach2(QGraphicsView*);
public:
    game(QWidget * parent=0);

    QGraphicsScene * scene;
    character * peach;
    score * Score;
    health * Health;
};

#endif // GAME_H
