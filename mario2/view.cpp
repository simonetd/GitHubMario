#include "view.h"
#include "controller.h"
#include "model.h"
#include <QKeyEvent>
#include <QObject>
#include <QDebug>
#include <QApplication>
#include <QMediaPlayer>
#include <QPushButton>
#include <QtAlgorithms>
#include "health.h"
#include "score.h"


view::view()
{
    this->grabKeyboard();
}

void view::menu()
{
    ready = 0;

    menuFont = new QGraphicsScene();
    menuFont->setSceneRect(0,0,600,300);
    QImage imageFontTemp("://images/menuBgw.jpg");
    QImage imageFont = imageFontTemp.scaled(600, 300);
    setBackgroundBrush(QBrush(imageFont));
    setScene(menuFont);
    setFixedSize(600, 300);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    boutonJouer = new QPushButton("Jouer");
    boutonJouer->setStyleSheet("border: none;"
                               "color: blue;"
                               "font: bold 20px;"
                               "background-color: pink");
    boutonJouer->setGeometry(QRect(100, 50, 200, 30));

//    QPushButton *boutonNiveaux = new QPushButton("Choix du niveau");
//    boutonNiveaux->setStyleSheet("border: none;"
//                               "color: blue;"
//                               "font: bold 20px;"
//                               "background-color: pink");
//    boutonNiveaux->setGeometry(QRect(500, 350, 200, 30));

    boutonQuitter = new QPushButton("Quitter");
    boutonQuitter->setStyleSheet("border: none;"
                                 "color: red;"
                                 "font: bold 20px;"
                                 "background-color: blue");
    boutonQuitter->setGeometry(QRect(100, 250, 200, 30));

    QObject::connect(boutonJouer, SIGNAL(clicked()), this, SLOT(jouer()));
    //QObject::connect(boutonNiveaux, SIGNAL(clicked()), this, SLOT(niveauxSelect()));
    QObject::connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    menuFont->addWidget(boutonJouer);
//    menuFont->addWidget(boutonNiveaux);
    menuFont->addWidget(boutonQuitter);

    show();
}

void view::jouer()
{
    hide();
    map();
}



void view::map()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,600,300);
    scene->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
    setFixedSize(1200, 300);
    for (int i=0; i<control->getmodel()->getFlors()->size();i++){
         scene->addItem(control->getmodel()->getFlors()->at(i));
    }
    for (int i=0; i<control->getmodel()->getBlocks()->size();i++){
         scene->addItem(control->getmodel()->getBlocks()->at(i));
    }
    for (int i=0; i<control->getmodel()->getBonuss()->size();i++){
         scene->addItem(control->getmodel()->getBonuss()->at(i));
    }
    for (int i=0; i<control->getmodel()->getBriques()->size();i++){
         scene->addItem(control->getmodel()->getBriques()->at(i));
    }
    for (int i=0; i<control->getmodel()->getEnnemys()->size();i++){
         scene->addItem(control->getmodel()->getEnnemys()->at(i));
    }
    for (int i=0; i<control->getmodel()->getPieces()->size();i++){
         scene->addItem(control->getmodel()->getPieces()->at(i));
    }
    Jackpot = new score();
    scene->addItem(Jackpot);
    Life = new health();
    Life->setPos(Life->x(),Life->y()+25);
    scene->addItem(Life);
    scene->addItem(control->getmodel()->getPeach());
    view2 = new QGraphicsView(scene);
    view2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view2->show();

    ready = 1;
       QMediaPlayer * music = new QMediaPlayer();
       music->setMedia(QUrl("qrc:/sounds/music.mp3"));
       music->play();
}

void view::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Q:
    case Qt::Key_Left:
        control->moveMarioLeft();
        break;
    case Qt::Key_D:
    case Qt::Key_Right:
        control->moveMarioRight();
        break;
    case Qt::Key_Z:
    case Qt::Key_Up:
    case Qt::Key_Space:
        control->moveMarioJump();
        break;
    case Qt::Key_Escape:
        hide();
        view2->hide();
        menu();
        break;
    }
}

void view::keyReleaseEvent(QKeyEvent *event)
{
    if(!(event ->isAutoRepeat()))
    {
        if((event->key()==Qt::Key_Right || (event->key()== Qt::Key_Left) || event->key() == Qt::Key_Q || event->key() == Qt::Key_D))
        {
           control->MarioStand();
        }
        control->MarioStand();
    }
}

void view::deleteItem(QGraphicsItem* item)
{
    scene->removeItem(item);
}

void view::pieceSound()
{
    QMediaPlayer * pieceSound = new QMediaPlayer();
    pieceSound->setMedia(QUrl("qrc:/sounds/piece.wav"));
    pieceSound->play();
}

void view::jumpSound()
{
    QMediaPlayer * jumpSound = new QMediaPlayer();
    jumpSound->setMedia(QUrl("qrc:/sounds/jump.wav"));
    jumpSound->play();
}

void view::gameOver()
{
    hide();
    view2->hide();
    youLose();
}

void view::youLose()
{
    ready = 0;

    endFont = new QGraphicsScene();

    QImage imageEndTemp("://images/peachEnd.png");
    QImage imageEnd = imageEndTemp.scaled(600, 300);
    setBackgroundBrush(QBrush(imageEnd));
    setFixedSize(600, 300);
    setScene(endFont);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    endFont->setSceneRect(0,0,600,300);

    show();
}
