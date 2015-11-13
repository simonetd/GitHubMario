#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class piece:public QObject, public QGraphicsPixmapItem
{
     Q_OBJECT
public:
    piece(QGraphicsItem * parent=0);

signals:

public slots:
};

#endif // PIECE_H
