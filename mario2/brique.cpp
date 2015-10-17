#include "brique.h"

brique::brique(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/brique.png").scaled(25,25));
}
