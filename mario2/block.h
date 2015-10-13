#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class block:public QObject, public QGraphicsPixmapItem
{
     Q_OBJECT
public:
    block(QGraphicsItem * parent=0);

signals:

public slots:
};

#endif // BLOCK_H
