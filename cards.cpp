#include "cards.h"

#include <ctime>
#include <cstdlib>
#include <QDebug>

int Cards::RandomNumbers[13];

Cards::Cards(){

}

Cards::Cards(bool isActive){

    if( isActive == true )
        setPixmap(QPixmap(":/others/heart/wrong/images/cards/active.png"));
    else
        setPixmap(QPixmap(":/others/heart/wrong/images/cards/back.png"));
}

QString Cards::setImage(int number){

    switch (number+1) {

        case 1: return ":/others/heart/wrong/images/cards/heart/neutral/2_serc.png";
        case 2: return ":/others/heart/wrong/images/cards/heart/neutral/3_serc.png";
        case 3: return ":/others/heart/wrong/images/cards/heart/neutral/4_serc.png";
        case 4: return ":/others/heart/wrong/images/cards/heart/neutral/5_serc.png";
        case 5: return ":/others/heart/wrong/images/cards/heart/neutral/6_serc.png";
        case 6: return ":/others/heart/wrong/images/cards/heart/neutral/7_serc.png";
        case 7: return ":/others/heart/wrong/images/cards/heart/neutral/8_serc.png";
        case 8: return ":/others/heart/wrong/images/cards/heart/neutral/9_serc.png";
        case 9: return ":/others/heart/wrong/images/cards/heart/neutral/10_serc.png";
        case 10: return ":/others/heart/wrong/images/cards/heart/neutral/jopek_serc.png";
        case 11: return ":/others/heart/wrong/images/cards/heart/neutral/dama_serc.png";
        case 12: return ":/others/heart/wrong/images/cards/heart/neutral/krol_serc.png";
        case 13: return ":/others/heart/wrong/images/cards/heart/neutral/as_serc.png";

        case 100: return ":/others/heart/wrong/images/others/statisticsIconS.png";
        case 101: return ":/others/heart/wrong/images/others/informationFrame.png";

        default: qDebug() << "We have a problem in method Cards::setImage";
                 return ":/others/images/cards/back.png";
    }
}

QString Cards::setImageWrong(int number){

      switch (number+1) {
          case 1: return ":/others/heart/wrong/images/cards/heart/wrong/2_serc_W.png";
          case 2: return ":/others/heart/wrong/images/cards/heart/wrong/3_serc_W.png";
          case 3: return ":/others/heart/wrong/images/cards/heart/wrong/4_serc_W.png";
          case 4: return ":/others/heart/wrong/images/cards/heart/wrong/5_serc_W.png";
          case 5: return ":/others/heart/wrong/images/cards/heart/wrong/6_serc_W.png";
          case 6: return ":/others/heart/wrong/images/cards/heart/wrong/7_serc_W.png";
          case 7: return ":/others/heart/wrong/images/cards/heart/wrong/8_serc_W.png";
          case 8: return ":/others/heart/wrong/images/cards/heart/wrong/9_serc_W.png";
          case 9: return ":/others/heart/wrong/images/cards/heart/wrong/10_serc_W.png";
          case 10: return ":/others/heart/wrong/images/cards/heart/wrong/jopek_serc_W.png";
          case 11: return ":/others/heart/wrong/images/cards/heart/wrong/dama_serc_W.png";
          case 12: return ":/others/heart/wrong/images/cards/heart/wrong/krol_serc_W.png";
          case 13: return ":/others/heart/wrong/images/cards/heart/wrong/as_serc_W.png";

          default: qDebug() << "We have a problem in method Cards::setImageWrong";
                   return nullptr;
      }
}

QString Cards::setImageCorrect(int number){

    switch (number+1) {
        case 1: return ":/others/heart/wrong/images/cards/heart/correct/2_serc_C.png";
        case 2: return ":/others/heart/wrong/images/cards/heart/correct/3_serc_C.png";
        case 3: return ":/others/heart/wrong/images/cards/heart/correct/4_serc_C.png";
        case 4: return ":/others/heart/wrong/images/cards/heart/correct/5_serc_C.png";
        case 5: return ":/others/heart/wrong/images/cards/heart/correct/6_serc_C.png";
        case 6: return ":/others/heart/wrong/images/cards/heart/correct/7_serc_C.png";
        case 7: return ":/others/heart/wrong/images/cards/heart/correct/8_serc_C.png";
        case 8: return ":/others/heart/wrong/images/cards/heart/correct/9_serc_C.png";
        case 9: return ":/others/heart/wrong/images/cards/heart/correct/10_serc_C.png";
        case 10: return ":/others/heart/wrong/images/cards/heart/correct/jopek_serc_C.png";
        case 11: return ":/others/heart/wrong/images/cards/heart/correct/dama_serc_C.png";
        case 12: return ":/others/heart/wrong/images/cards/heart/correct/krol_serc_C.png";
        case 13: return ":/others/heart/wrong/images/cards/heart/correct/as_serc_C.png";

        default: qDebug() << "We have a problem in method Cards::setImageCorrect";
                return nullptr;

    }
}

QString Cards::setActive(bool foo){

    if( foo == true )
        return  ":/others/heart/wrong/images/cards/active.png";
    else
        return ":/others/heart/wrong/images/cards/back.png";

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




bool Cards::IfItWasDrawn( int iNumber, int selectedAtRandom ){

    if( selectedAtRandom <= 0 )
         return false;

    for(int i = 0; i < selectedAtRandom; i++){
        if( RandomNumbers[i] == iNumber)
            return true;
    }

    return false;
}

