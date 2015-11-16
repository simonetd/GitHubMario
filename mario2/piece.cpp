#include "piece.h"

piece::piece(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/Star_coin.png").scaled(20,20));

}
