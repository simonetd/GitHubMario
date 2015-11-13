#ifndef MODEL_H
#define MODEL_H
#include <QList>
#include <floor.h>
#include <block.h>
#include <bonus.h>
#include <brique.h>
#include <ennemy.h>
#include <piece.h>

class floor;

class model
{
public:
   model();
   inline QList<floor *> *getFlors(){return flors;}
   inline QList<block *> *getBlocks(){return blocks;}
   inline QList<bonus *> *getBonuss(){return bonuss;}
   inline QList<brique *> *getBriques(){return briques;}
   inline QList<ennemy *> *getEnnemys(){return ennemys;}
   inline QList<piece *> *getPieces(){return pieces;}
   inline character *getPeach(){return peach;}
signals:

public slots:
private:
    character *peach;
    QList<floor*> *flors;
    //QList<QList *> *allitems;
    QList<block*> *blocks;
    QList<bonus*> *bonuss;
    QList<brique*> *briques;
    QList<ennemy*> *ennemys;
    QList<piece*> *pieces;
};
#endif // MODEL_H
