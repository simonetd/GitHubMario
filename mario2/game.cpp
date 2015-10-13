#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QFont>
#include "ennemy.h"
#include <character.h>
#include <QMediaPlayer>
#include <QImage>
#include <QBrush>
#include <QTextStream>
#include <QList>
#include <QString>
#include <QFile>
#include <floor.h>
#include <block.h>
#include <bonus.h>
#include <QDebug>
#include <typeinfo>

game::game(QWidget *parent){


    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,600);
    setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
    //view = new QGraphicsView;


    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,600);

    QFile fichier(":/map/map1.txt");
    if(fichier.open(QFile::ReadOnly)){
        QTextStream in (&fichier);
        QString lineread;
        int x=0;
        int y=575;
        while(!in.atEnd())
        {
            lineread=in.readLine();
            qDebug() << lineread;
            for (int i=0;i<lineread.size();i++){
                if(lineread.at(i)=='0'){
                    x=x+25;
                }
                if(lineread.at(i)=='1'){
                    floor * flor = new floor();
                    flor->setPos(x,y);
                    x=x+25;
                    scene->addItem(flor);
            }
                if(lineread.at(i)=='2'){
                    block * blockk = new block();
                    blockk->setPos(x,y);
                    x=x+25;
                    scene->addItem(blockk);
            }
                if(lineread.at(i)=='3'){
                    bonus * bon = new bonus();
                    bon->setPos(x,y);
                    x=x+25;
                    scene->addItem(bon);
            }
        }x=0;y=y-25;
    }
        ;

}


    character * peach = new character();
   // peach->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
    peach->setPos(0,450);
    peach->setFlag(QGraphicsItem::ItemIsFocusable);
    peach->setFocus();
    scene->addItem(peach);


    // create the score/healthb
    Score = new score();
    scene->addItem(Score);
    Health = new health();
    Health->setPos(Health->x(),Health->y()+25);
    scene->addItem(Health);

//    QMediaPlayer * music = new QMediaPlayer();
//    music->setMedia(QUrl("qrc:/sounds/music.mp3"));
//    music->play();





    show();
}


