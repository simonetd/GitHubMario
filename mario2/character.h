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
    void setcollisiondroite(int c);
    void setcollisiongauche(int d);
    int getcollisiondroite(){return collisiondroite;}
    int getcollisiongauche(){return collisiongauche;}
    void peachleft();
    void peachright();


signals:

public slots:


private:
    QMediaPlayer * stovesound;
    bool grounded;
    int gravitys;
    int collisiondroite;
    int collisiongauche;
};

#endif // CHARACTER_H
