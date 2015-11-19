#include "health.h"
#include <QFont>
#include <QDebug>
#include <QMessageBox>
#include <view.h>

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
   // En attente
    }
}
