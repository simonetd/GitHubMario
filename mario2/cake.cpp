#include "cake.h"

cake::cake(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/cake.png").scaled(20,20));
}

