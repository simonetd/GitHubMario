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
#include <brique.h>
#include <QDebug>
#include <typeinfo>

game::game(QWidget *parent){


    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,300);
    setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(600,300);

    QFile fichier(":/map/map1.txt");
    if(fichier.open(QFile::ReadOnly)){
        QTextStream in (&fichier);
        QString lineread;
        int x=0;
        int y=275;
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
                    bonus * bon = new bonus ();
                    bon->setPos(x,y);
                    x=x+25;
                    scene->addItem(bon);
            }
                if(lineread.at(i)=='4'){
                    brique * bri = new brique();
                    bri->setPos(x,y);
                    x=x+25;
                    scene->addItem(bri);
            }
                if(lineread.at(i)=='9'){
                    ennemy * Wario = new ennemy();
                    Wario->setPos(x,y);
                    x=x+25;
                    scene->addItem(Wario);
            }
        }x=0;y=y-25;
    }
        ;

}


    character * peach = new character();
    peach->setPos(0,225);
    peach->setFlag(QGraphicsItem::ItemIsFocusable);
    peach->setFocus();
    scene->addItem(peach);


    Score = new score();
    scene->addItem(Score);
    Health = new health();
    Health->setPos(Health->x(),Health->y()+25);
    scene->addItem(Health);
    view->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
    view->centerOn(peach);







    view->show();
}


