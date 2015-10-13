#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QApplication>
#include "menu.h"
#include "game.h"

//game * Game;
menu * Menu;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

//    Game = new game();
//    Game->show();

    Menu = new menu();
    Menu->show();

    return a.exec();
}
