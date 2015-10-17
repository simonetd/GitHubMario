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
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
    void gravity();
signals:

public slots:
   void down();
private:
    QMediaPlayer * stovesound;
    bool grounded;
    int stand;
    int droite;
    int gauche;
    int gravitys;
    int gravityspeedmax=15;
    int once;
protected:
    int collisionbas;
    int collisionhaut;
    int collisiongauche;
    int collisiondroite;


};

#endif // CHARACTER_H
