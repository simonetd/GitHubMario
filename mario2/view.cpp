#include "view.h"
#include "controller.h"
#include "model.h"
#include <QKeyEvent>
#include <QDebug>
#include <QMediaPlayer>
#include "health.h"
#include "score.h"


view::view()
{
    this->grabKeyboard();


}

void view::map()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,300);
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(600,300);
    scene->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
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
    view->centerOn(control->getmodel()->getPeach());
    view->show();
    view->centerOn(control->getmodel()->getPeach());
    scene->setFocusItem(control->getmodel()->getPeach());
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
