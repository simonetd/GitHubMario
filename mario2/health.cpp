#include "health.h"
#include <QFont>
#include <QDebug>
#include <QMessageBox>

health::health(QGraphicsItem *parent):QGraphicsTextItem(parent){

    Health=3;
    setPlainText("Health: "+ QString ::number(Health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void health::increase()
{
    Health=Health+1;
    setPlainText("Health: "+ QString ::number(Health));
}

void health::decrease()
{
    Health--;
    setPlainText("Health: "+ QString ::number(Health));
    if (Health==0){
      // QMessageBox::GameOver(this, "Game Over", "Il n'est pas difficile de jouer, mais de s'arrêter de jouer.?", QMessageBox ::Recommencer | QMessageBox::Recommencer);
    }
}
