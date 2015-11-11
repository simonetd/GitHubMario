#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QApplication>
#include "menu.h"
#include "game.h"
#include "model.h"
#include "controller.h"
#include "view.h"

//game * Game;
menu * Menu;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    model m;
    view v;
//    controller c;

//    v.setController(&c);

//    c.setView(&v);
//   c.setModel(&m);

    controller c(&m,&v);




//    Game = new game();
//    Game->show();

//    Menu = new menu();
//    Menu->show();

    return a.exec();
}
