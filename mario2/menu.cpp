#include <QTimer>
#include <QFont>
#include <QMediaPlayer>
#include <QImage>
#include <QBrush>
#include <QTextStream>
#include <QList>
#include <QString>
#include <QFile>
#include <QDebug>
#include <typeinfo>
#include <QKeyEvent>
#include <QApplication>
#include <QCoreApplication>
#include <QVector>
#include <QList>
#include "menu.h"
#include "game.h"
#include "ennemy.h"
#include <floor.h>
#include <block.h>
#include <bonus.h>
#include <character.h>

game * Game;


menu::menu(QWidget *parent)
{
    int i=1;

    menuFont = new QGraphicsScene();
    menuFont->setSceneRect(0,0,1200,600);
    QImage imageFontTemp("://images/menuBgw.jpg");
    QImage imageFont = imageFontTemp.scaled(1200, 600);
    setBackgroundBrush(QBrush(imageFont));
    setScene(menuFont);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,600);

    QPushButton *boutonJouer = new QPushButton("Jouer");
    boutonJouer->setStyleSheet("border: none;"
                               "color: blue;"
                               "font: bold 20px;"
                               "background-color: pink");
    boutonJouer->setGeometry(QRect(500, 300, 200, 30));

    QPushButton *boutonNiveaux = new QPushButton("Choix du niveau");
    boutonNiveaux->setStyleSheet("border: none;"
                               "color: blue;"
                               "font: bold 20px;"
                               "background-color: pink");
    boutonNiveaux->setGeometry(QRect(500, 350, 200, 30));

    QPushButton *boutonQuitter = new QPushButton("Quitter");
    boutonQuitter->setStyleSheet("border: none;"
                                 "color: red;"
                                 "font: bold 20px;"
                                 "background-color: blue");
    boutonQuitter->setGeometry(QRect(500, 400, 200, 30));

    QObject::connect(boutonJouer, SIGNAL(clicked()), this, SLOT(jouer()));
    QObject::connect(boutonNiveaux, SIGNAL(clicked()), this, SLOT(niveauxSelect()));
    QObject::connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    menuFont->addWidget(boutonJouer);
    menuFont->addWidget(boutonNiveaux);
    menuFont->addWidget(boutonQuitter);


    //Score = new score();
    //scene->addItem(Score);

    show();
}

void menu::jouer()
{
    this->hide();
    Game = new game();
   // Game->show();
}

void menu::jouer(int i)
{
    this->hide();
    //Game = new game(i);
    //Game->show();
}

void menu::niveauxSelect(){

    this->hide();

    int niveauxNombre=3;

    QGraphicsScene * menuNiveaux = new QGraphicsScene();
    menuNiveaux->setSceneRect(0,0,1200,600);
    QImage imageFontTemp("://images/menuBgw.jpg");
    QImage imageFont = imageFontTemp.scaled(1200, 600);
    setBackgroundBrush(QBrush(imageFont));
    setScene(menuNiveaux);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,600);

    QPushButton *boutonNv1 = new QPushButton("Niveau 1");
    boutonNv1->setStyleSheet("border: none;"
                               "color: blue;"
                               "font: bold 20px;"
                               "background-color: pink");
    boutonNv1->setGeometry(QRect(200, 100, 200, 30));

    QPushButton *boutonNv2 = new QPushButton("Niveau 2");
    boutonNv2->setStyleSheet("border: none;"
                               "color: blue;"
                               "font: bold 20px;"
                               "background-color: pink");
    boutonNv2->setGeometry(QRect(500, 100, 200, 30));

    QPushButton *boutonNv3 = new QPushButton("Niveau 3");
    boutonNv3->setStyleSheet("border: none;"
                               "color: blue;"
                               "font: bold 20px;"
                               "background-color: pink");
    boutonNv3->setGeometry(QRect(800, 100, 200, 30));

    menuNiveaux->addWidget(boutonNv1);
    menuNiveaux->addWidget(boutonNv2);
    menuNiveaux->addWidget(boutonNv3);

    QPushButton *boutonRetour = new QPushButton("Retour au menu principal");
    boutonRetour->setStyleSheet("border: none;"
                                 "color: blue;"
                                 "font: bold 20px;"
                                 "background-color: red");
            boutonRetour->setGeometry(QRect(450, 500, 300, 30));

    menuNiveaux->addWidget(boutonRetour);
    QObject::connect(boutonRetour, SIGNAL(clicked()), this, SLOT(retourMenu()));



    show();

}

void menu::retourMenu(){

    this->hide();
    menu();
}




