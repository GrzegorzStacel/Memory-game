#include "cards.h"

#include <ctime>
#include <cstdlib>
#include <QDebug>
//#include <QGraphicsItem>

int Cards::tablica[13];

//Cards::Cards(bool isActive){
Cards::Cards(){

    //if( isActive == true )
        //setPixmap(QPixmap(":/others/images/cards/active.png"));
   // else
    setPixmap(QPixmap(":/others/images/cards/back.png"));
}

void Cards::setImage(int number){
    switch (number+1) {
        case 1: setPixmap(QPixmap(":/cards/images/karty/heart/2_serc.png")); break;
        case 2: setPixmap(QPixmap(":/cards/images/karty/heart/3_serc.png")); break;
        case 3: setPixmap(QPixmap(":/cards/images/karty/heart/4_serc.png")); break;
        case 4: setPixmap(QPixmap(":/cards/images/karty/heart/5_serc.png")); break;
        case 5: setPixmap(QPixmap(":/cards/images/karty/heart/6_serc.png")); break;
        case 6: setPixmap(QPixmap(":/cards/images/karty/heart/7_serc.png")); break;
        case 7: setPixmap(QPixmap(":/cards/images/karty/heart/8_serc.png")); break;
        case 8: setPixmap(QPixmap(":/cards/images/karty/heart/9_serc.png")); break;
        case 9: setPixmap(QPixmap(":/cards/images/karty/heart/10_serc.png")); break;
        case 10: setPixmap(QPixmap(":/cards/images/karty/heart/jopek_serc.png")); break;
        case 11: setPixmap(QPixmap(":/cards/images/karty/heart/dama_serc.png")); break;
        case 12: setPixmap(QPixmap(":/cards/images/karty/heart/krol_serc.png")); break;
        case 13: setPixmap(QPixmap(":/cards/images/karty/heart/as_serc.png")); break;
    }
}



void Cards::generatorOfRandomNumbers(){

    srand(time ( 0 ));

    int wylosowanych = 0;
    int number;
    do
       {
           int number = rand() % 13;
           if( czyBylaWylosowana( number, wylosowanych ) == false ){
               tablica[ wylosowanych ] = number;
               wylosowanych++;
           }

       } while( wylosowanych < 13 );

    for(int i = 0; i < 13; i++)
        qDebug() << i << ". Wylosowana: " << tablica[i];


}

bool Cards::czyBylaWylosowana( int iNumber, int ile )
{
    if( ile <= 0 )
         return false;

    for(int i = 0; i < ile; i++){
        if( tablica[i] == iNumber)
            return true;
    }
//    int i = 0;
//    do
//    {
//        if( tablica[ i ] == iNumber )
//             return true;

//        i++;
//    } while( i < ile );

    return false;
}

