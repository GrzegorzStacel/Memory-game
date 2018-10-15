#include "drawcards.h"
#include "game.h"

#include <QBrush>
#include "QDebug"
#include <QPixmap>

#include <QSignalMapper>


extern Game *game;

int DrawCards::counter;
int DrawCards::x_posOfCard[];
int DrawCards::y_posOfCard[];


DrawCards::DrawCards(){
    setPixmap(QPixmap(":/others/images/cards/back.png"));
}


void DrawCards::placeCards(int x, int y, int cards){

    int X_SHIFT = 0;
    int Y_SHIFT = 0;
    bool isActive = false; // this variable is used by the constructor as the card argument in (this->) createBoard method

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

        // coordinates for correct and wrong buttons in DrawCards::showImageAfterReminding(int x) method
        x_posOfCard[i] = x + X_SHIFT;
        y_posOfCard[i] = y + Y_SHIFT;
    }
}

void DrawCards::createBoard(int x, int y, bool iisActive){

        cards = new Cards(iisActive);
        cards->setPos(x, y);
        listOfCards.append(cards);
        connect(cards, SIGNAL(clicked()), this, SLOT(addImageWithRandomNumber()));
        game->scene->addItem(cards);
}

void DrawCards::connectCardWithMap(){
    QSignalMapper* signalMapper = new QSignalMapper(this) ; // TODO find another way to implement the connections of each object separately with the appropriate signal

    for( int i = 0; i < 13; i++){ // TODO set the value - difficult
        connect (listOfCards[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper -> setMapping (listOfCards[i], i);
    }

    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(showImageAfterReminding(int))) ;
}


void DrawCards::addImageWithRandomNumber(){ // TODO add addImageWithRandomNumber(int difficult)

    cards = new Cards();

    // in method setActive();    true = set "active" image and vice versa,     false = set "back" image

    if( counter == 0 ){

        //remove first image and set random image
        game->scene->removeItem(listOfCards[counter]);
        listOfCards[counter]->setPixmap(cards->setImage(cards->getRandomNubmer(counter)));
        game->scene->addItem(listOfCards[counter]);

        // remove "back" image in next object and set "active" image
        game->scene->removeItem(listOfCards[counter+1]);
        listOfCards[counter+1]->setPixmap(cards->setActive(true));
        game->scene->addItem(listOfCards[counter+1]);

        counter++;

    } else if( counter > 0 && counter < 12 ){ // TODO counter < 13 change to counter < difficult

        // remove previus random image and set "back" image
        game->scene->removeItem(listOfCards[counter-1]);
        listOfCards[counter-1]->setPixmap(cards->setActive(false));
        game->scene->addItem(listOfCards[counter-1]);

        // remove "active" image and set random image
        game->scene->removeItem(listOfCards[counter]);
        listOfCards[counter]->setPixmap(cards->setImage(cards->getRandomNubmer(counter)));
        game->scene->addItem(listOfCards[counter]);

        // remove "back" image and set "activ" image
        game->scene->removeItem(listOfCards[counter+1]);
        listOfCards[counter+1]->setPixmap(cards->setActive(true));
        game->scene->addItem(listOfCards[counter+1]);

        counter++;

    } else if( counter == 12){ // TODO counter == 13 change to counter == difficult

        // remove previus random image and set "back" image
        game->scene->removeItem(listOfCards[counter-1]);
        listOfCards[counter-1]->setPixmap(cards->setActive(false));
        game->scene->addItem(listOfCards[counter-1]);

        // remove "active" image  and set random image
        game->scene->removeItem(listOfCards[counter]);
        listOfCards[counter]->setPixmap(cards->setImage(cards->getRandomNubmer(counter)));
        game->scene->addItem(listOfCards[counter]);

        counter++;

    } else if(counter == 13){
        qDebug() << "Counter: " << counter;
        // remove random image and set "back" image
        game->scene->removeItem(listOfCards[counter-1]);
        listOfCards[counter-1]->setPixmap(cards->setActive(false));
        game->scene->addItem(listOfCards[counter-1]);


        // create the reminding button // TODO I don't now if this buttoin is necessary
        MainButtons *reminding = new MainButtons(QString("Stop timer"), 200, 100);
        reminding->setPos(200,100);
        //connect(reminding, SIGNAL(clicked()), this, SLOT(showImageAfterReminding()));
        game->scene->addItem(reminding);

        counter++;

        connectCardWithMap();
    }
}


void DrawCards::showImageAfterReminding(int x){

    cards = new Cards();

    game->scene->removeItem(listOfCards[x]);
    listOfCards[x]->setPixmap(cards->setImage(cards->getRandomNubmer(x)));
    game->scene->addItem(listOfCards[x]);

    // create the correct button
    MainButtons *correct = new MainButtons(QString("Correct"), 50, 25);
    correct->setPos(x_posOfCard[x] + 10, y_posOfCard[x] + 215);
    //connect(correct, SIGNAL(clicked()), this, SLOT(showImageAfterReminding()));
    game->scene->addItem(correct);

    // create the wrong button
    MainButtons *wrong = new MainButtons(QString("Correct"), 50, 25);
    wrong->setPos(x_posOfCard[x] + 70, y_posOfCard[x] + 215);
    //connect(wrong, SIGNAL(clicked()), this, SLOT(showImageAfterReminding()));
    game->scene->addItem(wrong);
}


