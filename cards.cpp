#include "cards.h"

#include <QDebug>




Cards::Cards(QObject *parent) : QObject (parent) {

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

void Cards::Picture_Neutral(int value, bool lvl){

    if( lvl == true )
        setPixmap(picture.setImageRegularNeutral(value));

    else if( lvl == false )
        setPixmap(picture.setImageVeryHardNeutral(value));

}

void Cards::Picture_Correct(int value, bool lvl){

    if( lvl == true)
        setPixmap(picture.setImageRegularCorrect(value));

    else if( lvl == false  )
        setPixmap(picture.setImageVeryHardCorrect(value));
}

void Cards::Picture_Wrong(int value, bool lvl){

    if( lvl == true )
        setPixmap(picture.setImageRegularWrong(value));

    else if( lvl == false )
        setPixmap(picture.setImageVeryHardWrong(value));
}

