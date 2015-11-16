#ifndef BONUS_H
#define BONUS_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class bonus: public QObject, public QGraphicsPixmapItem
{

   Q_OBJECT
public:
    bonus(QGraphicsItem * parent=0);
    void emptybonus();
    bool getemptybonus(){return empty;}

signals:

public slots:

private:
    bool empty;
};

#endif // BONUS_H
