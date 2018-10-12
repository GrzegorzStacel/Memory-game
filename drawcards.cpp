#include "drawcards.h"
#include "game.h"

#include "QDebug"

extern Game *game;


DrawCards::DrawCards(){







    // allow responding to hover events
    //setAcceptHoverEvents(true);
}



//public
void DrawCards::placeCards(int x, int y, int cards){

    int X_SHIFT = 0;
    int Y_SHIFT = 0;

    for( int i = 0, n = cards; i < n; i++){

        if( i % 3 == 0 && i != 6 )
            X_SHIFT += 100;

        else if( i % 6 == 0 || i % 12 == 0 ){
            X_SHIFT = 0;
            Y_SHIFT -= 250;
        }

        if( i == 0 || i == 6)
            X_SHIFT = 50;
        else
            X_SHIFT += 150;

        if( i == 12 ){
            X_SHIFT = 475;
            Y_SHIFT -= 250;
        }

        createBoard(x + X_SHIFT, y + Y_SHIFT, i);
    }
}


// private
void DrawCards::createBoard(int x, int y, int cards){


    //for( int i = 0, n = cards; i < n; i++ ){
        Cards *card = new Cards();
        card->setPos(x, y);
        listOfCards.append(card);
        game->scene->addItem(card);

        listOfImage.append(cards);
        //foreach( int z, listOfImage )//{
           // qDebug() << listOfImage;// << " , z: " << z <<  "Imageset z: " << z;
            //card->setImage(z);}

       //qDebug() << "Loop nr: " << listOfImage;



    //}
    //foreach( int z, listOfImage )
       // qDebug() << z;
}

void DrawCards::cardSupport(){
    getCards();
}
