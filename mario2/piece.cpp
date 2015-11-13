#include "piece.h"

piece::piece(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/piece.png").scaled(20,20));

}
