#ifndef MENU_H
#define MENU_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QObject>
#include <QPushButton>


class menu: public QGraphicsView{
    Q_OBJECT
public:
    menu(QWidget * parent=0);

    QGraphicsScene * menuFont;

public slots:
    void jouer();
    void jouer(int i);
    void niveauxSelect();
    void retourMenu();

signals:
    void clicked();




};

#endif // MENU_H
