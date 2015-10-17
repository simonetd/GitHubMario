#ifndef BRIQUE_H
#define BRIQUE_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class brique: public QObject, public QGraphicsPixmapItem
{

   Q_OBJECT
public:
    brique(QGraphicsItem * parent=0);

signals:

public slots:
};

#endif // BRIQUE_H
