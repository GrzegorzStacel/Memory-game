#include "drawcards.h"
#include "game.h"

#include <QBrush>
#include "QDebug"
#include <QPixmap>
extern Game *game;

int DrawCards::counter; // TODO set the vale - difficult


DrawCards::DrawCards(){
    setPixmap(QPixmap(":/others/images/cards/back.png"));
}


void DrawCards::placeCards(int x, int y, int cards){

    int X_SHIFT = 0;
    int Y_SHIFT = 0;
    bool isActive = false;

    for( int i = 0, n = cards; i < n; i++){

        if( i == 0 )
            isActive = true;
        else
            isActive = false;

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

        createBoard(x + X_SHIFT, y + Y_SHIFT, isActive);
    }
}

void DrawCards::createBoard(int x, int y, bool iisActive){

        Cards *card = new Cards(iisActive);
        card->setPos(x, y);
        listOfCards.append(card);
        connect(card, SIGNAL(clicked()), this, SLOT(addImageWithRandomNumber()));
        game->scene->addItem(card);
}


void DrawCards::addImageWithRandomNumber(){ // TODO add addImageWithRandomNumber(int difficult)

    cards = new Cards();

    // in method setActive();    true = set Activ image and vice versa,     false = set non Activ (back) image

    if( counter == 0 ){

        game->scene->removeItem(listOfCards[counter]);
        listOfCards[counter]->setPixmap(cards->setImage(cards->getRandomNubmer(counter)));
        game->scene->addItem(listOfCards[counter]);

        game->scene->removeItem(listOfCards[counter+1]);
        listOfCards[counter+1]->setPixmap(cards->setActive(true));
        game->scene->addItem(listOfCards[counter+1]);

        counter++;

    } else if( counter > 0 && counter < 12 ){ // TODO counter < 13 change to counter < difficult

        game->scene->removeItem(listOfCards[counter-1]);
        listOfCards[counter-1]->setPixmap(cards->setActive(false));
        game->scene->addItem(listOfCards[counter-1]);

        game->scene->removeItem(listOfCards[counter]);
        listOfCards[counter]->setPixmap(cards->setImage(cards->getRandomNubmer(counter)));
        game->scene->addItem(listOfCards[counter]);

        game->scene->removeItem(listOfCards[counter+1]);
        listOfCards[counter+1]->setPixmap(cards->setActive(true));
        game->scene->addItem(listOfCards[counter+1]);

        counter++;

    } else{

        game->scene->removeItem(listOfCards[counter-1]);
        listOfCards[counter-1]->setPixmap(cards->setActive(false));
        game->scene->addItem(listOfCards[counter-1]);

        game->scene->removeItem(listOfCards[counter]);
        listOfCards[counter]->setPixmap(cards->setImage(cards->getRandomNubmer(counter)));
        game->scene->addItem(listOfCards[counter]);

        counter=0;

    }


}


