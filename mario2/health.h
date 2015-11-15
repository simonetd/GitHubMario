#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class health:public QGraphicsTextItem
{
public:
    health(QGraphicsItem * parent=0);
    void decrease();
    void increase();
    int gethealth(){return this->Health;}
private:
    int Health;
signals:

public slots:
};

#endif // HEALTH_H
