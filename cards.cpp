#include "cards.h"

#include <ctime>
#include <cstdlib>
#include <QDebug>

int Cards::RandomNumbers[13];

Cards::Cards(){

}

Cards::Cards(bool isActive){

    if( isActive == true )
        setPixmap(QPixmap(":/others/images/cards/active.png"));
    else
        setPixmap(QPixmap(":/others/images/cards/back.png"));
}

QString Cards::setImage(int number){

    switch (number+1) {
        case 1: return ":/background/images/cards/heart/2_serc.png";
        case 2: return ":/background/images/cards/heart/3_serc.png";
        case 3: return ":/background/images/cards/heart/4_serc.png";
        case 4: return ":/background/images/cards/heart/5_serc.png";
        case 5: return ":/background/images/cards/heart/6_serc.png";
        case 6: return ":/background/images/cards/heart/7_serc.png";
        case 7: return ":/background/images/cards/heart/8_serc.png";
        case 8: return ":/background/images/cards/heart/9_serc.png";
        case 9: return ":/background/images/cards/heart/10_serc.png";
        case 10: return ":/background/images/cards/heart/jopek_serc.png";
        case 11: return ":/background/images/cards/heart/dama_serc.png";
        case 12: return ":/background/images/cards/heart/krol_serc.png";
        case 13: return ":/background/images/cards/heart/as_serc.png";

        default: qDebug() << "We have a problem in method Cards::setImage";
                 return ":/others/images/cards/back.png";
    }
}

QString Cards::setActive(bool foo){

    if( foo == true )
        return  ":/others/images/cards/active.png";
    else
        return ":/others/images/cards/back.png";

}



void Cards::generatorOfRandomNumbers(){

    srand(time ( nullptr ));

    int selectedAtRandom = 0;
    int number;

    do
       {
           number = rand() % 13;
           if( IfItWasDrawn( number, selectedAtRandom ) == false ){
               RandomNumbers[ selectedAtRandom ] = number;
               selectedAtRandom++;
           }

    } while( selectedAtRandom < 13 );
}

void Cards::createPauseButton(){
    setPixmap(QString(":/others/images/others/pauseButtonS.png"));
    setPos(1150,15);
}


bool Cards::IfItWasDrawn( int iNumber, int selectedAtRandom ){

    if( selectedAtRandom <= 0 )
         return false;

    for(int i = 0; i < selectedAtRandom; i++){
        if( RandomNumbers[i] == iNumber)
            return true;
    }

    return false;
}

