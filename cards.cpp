#include "cards.h"
//#include "drawcards.h"

#include <QDebug>




Cards::Cards(){

}

Cards::Cards(bool activ, bool lvl, int x_car, int y_car)  :  x_pos_card(x_car), y_pos_card(y_car)      {

    setActive(activ, lvl);
}

void Cards::setActive(bool isActive, bool lvl){

    if( lvl == true ){

        if( isActive == true )
            setPixmap(QPixmap(":/others/images/cards/active.png"));
        else
            setPixmap(QPixmap(":/others/images/cards/back.png"));

    } else if( lvl == false ){

        if( isActive == true )
            setPixmap(QPixmap(":/others/images/cards/activeVeryHard.png"));
        else
            setPixmap(QPixmap(":/others/images/cards/backVeryHard.png"));

    } else
        qDebug() << "Error in method Cards::setActive()";

}

