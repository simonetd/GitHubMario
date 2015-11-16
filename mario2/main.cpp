#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QApplication>
#include "model.h"
#include "controller.h"
#include "view.h"


int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    model m;
    view v;
    controller c(&m,&v);


    return a.exec();
}
