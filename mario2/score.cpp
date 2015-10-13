#include "score.h"
#include <QFont>

score::score(QGraphicsItem *parent):QGraphicsTextItem(parent){

    Score=0;
    setPlainText("Score: "+ QString ::number(Score));
    setDefaultTextColor(Qt::gray);
    setFont(QFont("times",16));
}

void score::increase()
{
    Score=Score+100;
    setPlainText("Score: "+ QString ::number(Score));
}

int score::getscore()
{
    return Score;
}
