#ifndef MODEL_H
#define MODEL_H
#include <QList>
#include <floor.h>
#include <block.h>
#include <bonus.h>
#include <brique.h>
#include <ennemy.h>

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
signals:

public slots:
private:
    QList<floor*> *flors;
    //QList<QList *> *allitems;
    QList<block*> *blocks;
    QList<bonus*> *bonuss;
    QList<brique*> *briques;
    QList<ennemy*> *ennemys;
};
#endif // MODEL_H
