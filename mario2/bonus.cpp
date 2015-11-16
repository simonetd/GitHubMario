#include "bonus.h"


bonus::bonus(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/bonus.png").scaled(25,25));
    empty=0;
}

void bonus::emptybonus()
{
    setPixmap(QPixmap(":/images/brique.png").scaled(25,25));
    empty=1;

}

