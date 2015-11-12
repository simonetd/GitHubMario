#ifndef CHARACTER_H
#define CHARACTER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsItem>


class character:public QObject, public QGraphicsPixmapItem
{
     Q_OBJECT
public:
    character(QGraphicsItem * parent=0);
    void gravity();
    int getgravitys(){return gravitys;}
    void setgravitys(int a);
    bool getgrounded(){return grounded;}
    void setgrounded(bool b);


signals:

public slots:


private:
    QMediaPlayer * stovesound;
    bool grounded;
    int gravitys;
};

#endif // CHARACTER_H
