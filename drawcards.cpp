#include "drawcards.h"
#include "game.h"
#include "game_over.h"

#include <QBrush>
#include "QDebug"
#include <QPixmap>

#include <QSignalMapper>


#include <QPointer>

extern Game *game;

int DrawCards::counter;
int DrawCards::counterEnd = 0;
int DrawCards::tmp;
int DrawCards::x_posOfCard[];
int DrawCards::y_posOfCard[];
int DrawCards::antiRepetition[];
bool DrawCards::isActive = true;

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
        counter = 13; // TODO cheat variable
        counterEnd = 12;
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
        // remove random image and set "back" image
        game->scene->removeItem(listOfCards[counter-1]);
        listOfCards[counter-1]->setPixmap(cards->setActive(false));
        game->scene->addItem(listOfCards[counter-1]);

        counter++;

        timer time;
        time.set_mRunning(false);
        isActive = false;
        time.stop();

        // create text annoucning winner
        information = new QGraphicsTextItem("The clock has been stopped");
        QFont titleFont("comic sans", 35, 3);
        information->setFont(titleFont);
        information->setPos(game->scene->width()/4, 15);

        game->scene->addItem(information);

        connectCardWithMap();
    }
}

void DrawCards::connectCardWithMap(){
    QSignalMapper* signalMapper = new QSignalMapper(this) ; // TODO find another way to implement the connections of each object separately with the appropriate signal

    for( int i = 0; i < listOfCards.size(); i++){ // TODO (DONE) set the value - difficult
        connect (listOfCards[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper -> setMapping (listOfCards[i], i);
    }

    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(showImageAfterReminding(int))) ;
}


void DrawCards::showImageAfterReminding(int x){

    cards = new Cards();

    game->scene->removeItem(listOfCards[x]);
    listOfCards[x]->setPixmap(cards->setImage(cards->getRandomNubmer(x)));
    game->scene->addItem(listOfCards[x]);


    // disable all cards
    for( int i = 0; i < listOfCards.size() ; i++)
            listOfCards[i]->setEnabled(false);

    // check if the card has been re-selected - if yes set disable this card
    if( isItRepeat( x, tmp ) == false ){
        antiRepetition[ tmp ] = x;
        tmp++;
        counterEnd++;
    }



    // create the correct button under the choosen card
    MainButtons * correct = new MainButtons(QString("Correct"), 50, 25);
    correct->setPos(x_posOfCard[x] + 10, y_posOfCard[x] + 215);
    buttons.append(correct);
    connect(correct, SIGNAL(clicked()), this, SLOT(remember()));
    game->scene->addItem(correct);

    // create the wrong button under the choosen card
    MainButtons *wrong = new MainButtons(QString("Wrong"), 50, 25);
    wrong->setPos(x_posOfCard[x] + 70, y_posOfCard[x] + 215);
    buttons.append(wrong);
    connect(wrong, SIGNAL(clicked()), this, SLOT(wrong()));
    game->scene->addItem(wrong);

}

bool DrawCards::isItRepeat(int xNumber, int selected){

    if( selected <= 0 )
        return false;

    for(int i = 0; i < selected; i++){
        if( antiRepetition[i] == xNumber)
            return true;
    }

    return false;
}

void DrawCards::remember(){

    // add value to statistic ( correct answer )
    stat->setCorrect(1);

    manageAnswers();
}

void DrawCards::wrong(){

    // add value to statistic ( wrong answer )
    stat->setWrong(1);

    manageAnswers();
}


void DrawCards::manageAnswers(){

    // removing the text informing about stopping the clock
    if( counterEnd == 1 )
        game->scene->removeItem(information);

    // remove buttons (correct and wrong) under selected card
    for(int i = 0; i < buttons.size(); i++){
        game->scene->removeItem(buttons[i]);
    }

    // buble sort the table with selected cards ( I know, this is very slow algorithm but it is very small table )
    int x;

    for(int j = 0; j < tmp - 1; j++)
        for(int i = 0; i < tmp - 1; i++)
          if(antiRepetition[i] > antiRepetition[i + 1]) {

            x = antiRepetition[i];
            antiRepetition[i] = antiRepetition[i + 1];
            antiRepetition[i + 1] = x;
    }

    // disable all "visible" (selected) cards and else set enabled
    int i = 0;
    int n = 0;

    do{
        if( i == antiRepetition[n] && n <= tmp ){


            listOfCards[ antiRepetition[n] ]->setEnabled(false);
            n++;
            i++;
        } else{

            listOfCards[i]->setEnabled(true);
            i++;
        }
    }while( i < listOfCards.size() && n <= tmp );

    buttons.clear();

    // display the final menu
    if( counterEnd == listOfCards.size() ){

        game_over *gameOver = new game_over();
        gameOver->drawButtons();
        gameOver->manageStatistic();
    }
}


void DrawCards::setResetAllInOne(){

    // reset all the important integers, if a player wants to play again
    counter = 0;
    counterEnd = 0;
    tmp = 0;

    for( int i = 0; i < 13; i++)// TODO change value for difficult
        antiRepetition[i] = 0;


    listOfCards.clear();
}

