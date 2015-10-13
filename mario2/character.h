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
    void gravity();
signals:

public slots:
   void down();
private:
    QMediaPlayer * stovesound;
    bool grounded;
    int bas;
    int haut;
    int gauche;
    int droite;
    int gravitys;
    int gravityspeedmax=15;
    int once;

};

#endif // CHARACTER_H
