#include "model.h"
#include "QFile"
#include "floor.h"
#include "character.h"
#include "QTextStream"

model::model()
{
    this->flors = new QList<floor *>;
    this->blocks = new QList<block *>;
    this->briques = new QList<brique *>;
    this->bonuss = new QList<bonus *>;
    this->ennemys = new QList<ennemy *>;

    peach = new character();
    peach->setPos(0,225);

    QFile fichier(":/map/map1.txt");
    if(fichier.open(QFile::ReadOnly)){
        QTextStream in (&fichier);
        QString lineread;
        int x=0;
        int y=275;

        while(!in.atEnd())
        {
            lineread=in.readLine();
            for (int i=0;i<lineread.size();i++){
                if(lineread.at(i)=='0'){
                    x=x+25;
                }
                if(lineread.at(i)=='1'){
                    floor * flor = new floor();
                    flor->setPos(x,y);
                    flors->append(flor);
                    x=x+25;
            }
                if(lineread.at(i)=='2'){
                    block * blockk = new block();
                    blockk->setPos(x,y);
                    blocks->append(blockk);
                    x=x+25;
            }
                if(lineread.at(i)=='3'){
                    bonus * bon = new bonus ();
                    bon->setPos(x,y);
                    bonuss->append(bon);
                    x=x+25;
            }
                if(lineread.at(i)=='4'){
                    brique * bri = new brique();
                    bri->setPos(x,y);
                    briques->append(bri);
                    x=x+25;
            }
                if(lineread.at(i)=='9'){
                    ennemy * Wario = new ennemy();
                    Wario->setPos(x,y);
                    ennemys->append(Wario);
                    x=x+25;
            }
        }x=0;y=y-25;
    }
        ;

}
fichier.close();


}


