#include "drawcards.h"
#include "game.h"
#include "game_over.h"
#include "statisticbesttime.h"
#include "timer.h"
#include "generator_of_random_numbers.h"

#include <QBrush>
#include "QDebug"
#include <QPixmap>

#include <QSignalMapper>
#include <QDateTime>

#include <QPointer>

extern Game *game;

int DrawCards::counter = 0;
int DrawCards::counterEnd = 0;
int DrawCards::tmp;
int DrawCards::x_posOfCard[];
int DrawCards::y_posOfCard[];
int DrawCards::antiRepetition[];
bool DrawCards::isActive = true;
int DrawCards::variableForChooseImage;
int DrawCards::difficultLvl;

DrawCards::DrawCards(){

}
void DrawCards::drawcardsManager(int level){

    difficultLvl = level;

    if( difficultLvl == 13 )
        placeCardsEasy(475, 650, level);
    if( difficultLvl == 26 )
        placeCardsMedium(120, 720, level);
    if( difficultLvl == 39 )
        placeCardsHard(5, 740, level);
    if( difficultLvl == 52 )
        placeCardsHardcore(70, 790, level);
}
void DrawCards::placeCardsEasy(int x, int y, int cards){

    int X_SHIFT = 0;
    int Y_SHIFT = 0;
    bool isActive = false; // this variable is used by the constructor as the card argument in (this->) createBoard method

    for( int i = 0, n = cards; i < n; i++){

        if( i == 0 )
            isActive = true;
        else
            isActive = false;

        if( i % 3 == 0 && i != 6 ) // distance from triples
            X_SHIFT += 100;

        else if( i % 6 == 0 || i % 12 == 0 ){ // new row
            X_SHIFT = 0;
            Y_SHIFT -= 250;
        }

        if( i == 0 || i == 6) // distance of first cards from the left side
            X_SHIFT = 50;
        else // distance from cards (inside triples)
            X_SHIFT += 150;

        if( i == 12 ){ // distance in third row (last card)
            X_SHIFT = 475;
            Y_SHIFT -= 250;
        }

        createBoard(x + X_SHIFT, y + Y_SHIFT, isActive);

        // coordinates for correct and wrong buttons in DrawCards::showImageAfterReminding(int x) method
        x_posOfCard[i] = x + X_SHIFT;
        y_posOfCard[i] = y + Y_SHIFT;
    }
}

void DrawCards::placeCardsMedium(int x, int y, int cards){

    int X_SHIFT = 0;
    int Y_SHIFT = 0;
    bool isActive = false; // this variable is used by the constructor as the card argument in (this->) createBoard method

    for( int i = 0; i < cards; i++){

        if( i == 0 )
            isActive = true;
        else
            isActive = false;


        if( i % 3 == 0 && i != 9 && i != 18 && i != 24 ) // distance from triples
            X_SHIFT += 100;

        else if( i == 9 || i == 18 || i == 24 ){ // new row
            X_SHIFT = 0;
            Y_SHIFT -= 230;
        }


        if( i == 0 || i == 9  ) // distance of first cards from the left side
            X_SHIFT = 50;
        else // distance from cards (inside triples)
            X_SHIFT += 150;


        if( i == 18 ) // distance in third row
            X_SHIFT = 325;

        else if( i == 24 ) // distance in fourth row
            X_SHIFT = 670;


        createBoard(x + X_SHIFT, y + Y_SHIFT, isActive);

        // coordinates for correct and wrong buttons in DrawCards::showImageAfterReminding(int x) method
        x_posOfCard[i] = x + X_SHIFT;
        y_posOfCard[i] = y + Y_SHIFT;
    }
}

void DrawCards::placeCardsHard(int x, int y, int cards){

    int X_SHIFT = 0;
    int Y_SHIFT = 0;
    bool isActive = false; // this variable is used by the constructor as the card argument in (this->) createBoard method

    for( int i = 0; i < cards; i++){

        if( i == 0 )
            isActive = true;
        else
            isActive = false;


        if( i % 3 == 0 && i != 12 && i != 24 && i != 36) // distance from triples
            X_SHIFT += 40;

        else if( i == 12 || i == 24 || i == 36 ){ // new row
            X_SHIFT = 0;
            Y_SHIFT -= 230;
        }


        if( i == 0 || i == 12 || i == 24 ) // distance of first cards from the left side
            X_SHIFT = 30;
        else // distance from cards (inside triples)
            X_SHIFT += 145;


        if( i == 36 ) // distance in fourth row
            X_SHIFT = 730;


        createBoard(x + X_SHIFT, y + Y_SHIFT, isActive);

        // coordinates for correct and wrong buttons in DrawCards::showImageAfterReminding(int x) method
        x_posOfCard[i] = x + X_SHIFT;
        y_posOfCard[i] = y + Y_SHIFT;
    }
}

void DrawCards::placeCardsHardcore(int x, int y, int cards){

    int X_SHIFT = 0;
    int Y_SHIFT = 0;
    bool isActive = false; // this variable is used by the constructor as the card argument in (this->) createBoard method

    for( int i = 0; i < cards; i++){

        if( i == 0 )
            isActive = true;
        else
            isActive = false;


        if( i % 3 == 0 && i != 12 && i != 24 && i != 36 && i != 48) // distance from triples
            X_SHIFT += 40;

        else if( i == 12 || i == 24 || i == 36 || i == 48){ // new row
            X_SHIFT = 0;
            Y_SHIFT -= 190;
        }


        if( i == 0 || i == 12 || i == 24 || i == 36) // distance of first cards from the left side
            X_SHIFT = 30;
        else // distance from cards (inside triples)
            X_SHIFT += 135;


        if( i == 48 ) // distance in fourth row
            X_SHIFT = 630;


        createBoard(x + X_SHIFT, y + Y_SHIFT, isActive);

        // coordinates for correct and wrong buttons in method DrawCards::showImageAfterReminding(int x)
        x_posOfCard[i] = x + X_SHIFT;
        y_posOfCard[i] = y + Y_SHIFT;
    }

}


void DrawCards::createBoard(int x, int y, bool iisActive){

    cards = new Cards(iisActive, true, x, y );

    cards->setPos(x, y);
    listOfCards.append(cards);
    connect(cards, SIGNAL(clicked()), this, SLOT(addImageWithRandomNumber()));
    game->scene->addItem(cards);
    //counter = difficultLvl - 1; // TODO cheat variable for tests
    //counterEnd = 11;

}

void DrawCards::addImageWithRandomNumber(){


    Generator_of_random_numbers *generator = new Generator_of_random_numbers();
    int RandomNumber = generator->getRandomNubmer(counter);



    // in method setActive(bool1, bool2);
    //                    1) true = set "active regular" image              false = set "back" image
    //                    2) true = set "active very hard" image            false = set "back very hard" image
    if( difficultLvl == 13 || difficultLvl == 26 || difficultLvl == 39){


                if( counter == 0 ){

                    //remove first image and set random image
                    game->scene->removeItem(listOfCards[counter]);
                    listOfCards[counter]->Picture_Neutral( RandomNumber , true );
                    game->scene->addItem(listOfCards[counter]);

                    // remove "back" image in next object and set "active" image
                    game->scene->removeItem(listOfCards[counter+1]);
                    listOfCards[counter+1]->setActive(true, true);
                    game->scene->addItem(listOfCards[counter+1]);

                    counter++;

                } else if( counter > 0 && counter < difficultLvl - 1 ){

                    // remove previus random image and set "back" image
                    game->scene->removeItem(listOfCards[counter-1]);
                    listOfCards[counter-1]->setActive(false, true);
                    game->scene->addItem(listOfCards[counter-1]);

                    // remove "active" image and set random image
                    game->scene->removeItem(listOfCards[counter]);
                    listOfCards[counter]->Picture_Neutral( RandomNumber, true);
                    game->scene->addItem(listOfCards[counter]);

                    // remove "back" image and set "activ" image
                    game->scene->removeItem(listOfCards[counter+1]);
                    listOfCards[counter+1]->setActive(true, true);
                    game->scene->addItem(listOfCards[counter+1]);

                    counter++;

                } else if( counter == difficultLvl - 1){

                    // remove previus random image and set "back" image
                    game->scene->removeItem(listOfCards[counter-1]);
                    listOfCards[counter-1]->setActive(false, true);
                    game->scene->addItem(listOfCards[counter-1]);

                    // remove "active" image  and set random image
                    game->scene->removeItem(listOfCards[counter]);
                    listOfCards[counter]->Picture_Neutral( RandomNumber, true );
                    game->scene->addItem(listOfCards[counter]);

                    counter++;

                } else if(counter == difficultLvl){
                    // remove random image and set "back" image
                    game->scene->removeItem(listOfCards[counter-1]);
                    listOfCards[counter-1]->setActive(false, true);
                    game->scene->addItem(listOfCards[counter-1]);

                    //counter++;

                    timer time;
                    time.setMRunning(false);
                    isActive = false;
                    time.stop();

                    // create text annoucning winner
                    inf_clock_stop = new Graphic_others();
                    inf_clock_stop->setPos(game->scene->width()/4+70, 15);
                    inf_clock_stop->setPixmap(graphic->setImageOthers(5));
                    game->scene->addItem(inf_clock_stop);

                    connectCardWithMap();
                }

    } else if( difficultLvl == 52 ){

                if( counter == 0 ){

                    //remove first image and set random image
                    game->scene->removeItem(listOfCards[counter]);
                    listOfCards[counter]->Picture_Neutral( RandomNumber, false );
                    game->scene->addItem(listOfCards[counter]);

                    // remove "back" image in next object and set "active" image
                    game->scene->removeItem(listOfCards[counter+1]);
                    listOfCards[counter+1]->setActive(true, false);
                    game->scene->addItem(listOfCards[counter+1]);

                    counter++;

                } else if( counter > 0 && counter < difficultLvl - 1 ){

                    // remove previus random image and set "back" image
                    game->scene->removeItem(listOfCards[counter-1]);
                    listOfCards[counter-1]->setActive(false, false);
                    game->scene->addItem(listOfCards[counter-1]);

                    // remove "active" image and set random image
                    game->scene->removeItem(listOfCards[counter]);
                    listOfCards[counter]->Picture_Neutral( RandomNumber, false );
                    game->scene->addItem(listOfCards[counter]);

                    // remove "back" image and set "activ" image
                    game->scene->removeItem(listOfCards[counter+1]);
                    listOfCards[counter+1]->setActive(true, false);
                    game->scene->addItem(listOfCards[counter+1]);

                    counter++;

                } else if( counter == difficultLvl - 1){

                    // remove previus random image and set "back" image
                    game->scene->removeItem(listOfCards[counter-1]);
                    listOfCards[counter-1]->setActive(false, false);
                    game->scene->addItem(listOfCards[counter-1]);

                    // remove "active" image  and set random image
                    game->scene->removeItem(listOfCards[counter]);
                    listOfCards[counter]->Picture_Neutral( RandomNumber, false );
                    game->scene->addItem(listOfCards[counter]);

                    counter++;

                } else if(counter == difficultLvl){
                    // remove random image and set "back" image
                    game->scene->removeItem(listOfCards[counter-1]);
                    listOfCards[counter-1]->setActive(false, false);
                    game->scene->addItem(listOfCards[counter-1]);

                    counter++;

                    timer time;
                    time.setMRunning(false);
                    isActive = false;
                    time.stop();

                    // create text annoucning winner
                    inf_clock_stop = new Graphic_others();
                    inf_clock_stop->setPos(game->scene->width()/4+70, 15);
                    inf_clock_stop->setPixmap(graphic->setImageOthers(5));
                    game->scene->addItem(inf_clock_stop);

                    connectCardWithMap();
                }
    } else
        qDebug() << "Error in method DrawCards::addImageWithRandomNumber()";

}

void DrawCards::connectCardWithMap(){

    QSignalMapper* signalMapper = new QSignalMapper(this); // TODO find another way to implement the connections of each object separately with the appropriate signal

        for( int i = 0; i < listOfCards.size(); i++){

            connect (listOfCards[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper -> setMapping (listOfCards[i], i);

        }

    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(showImageAfterReminding(int)));

}

void DrawCards::showImageAfterReminding(int x){

    Generator_of_random_numbers *generator = new Generator_of_random_numbers();
    int RandomNumber = generator->getRandomNubmer(x);

    if( difficultLvl == 13 || difficultLvl == 26 || difficultLvl == 39){

        game->scene->removeItem(listOfCards[x]);
        listOfCards[x]->Picture_Neutral( RandomNumber, true );
        game->scene->addItem(listOfCards[x]);

    } else if( difficultLvl == 52 ){

        game->scene->removeItem(listOfCards[x]);
        listOfCards[x]->Picture_Neutral( RandomNumber, false );
        game->scene->addItem(listOfCards[x]);

    } else
        qDebug() << "Error in method DrawCards::showImageAfterReminding()";


    // disable all cards
    for( int i = 0; i < listOfCards.size() ; i++)
            listOfCards[i]->setEnabled(false);

    // check if the card has been re-selected - if yes set disable this card
    if( isItRepeat( x, tmp ) == false ){
        antiRepetition[ tmp ] = x;
        tmp++;
        counterEnd++;

        // Send this value to methods Correct and Wrong by the signal slot
        setVariableForChooseImage(x);
    }


    Graphic_others *corr = new Graphic_others();
    Graphic_others *wron = new Graphic_others();

    // Add the buttons correct and wrong

    if( difficultLvl == 13 || difficultLvl == 26 || difficultLvl == 39){

        corr->setPixmap(corr->setImageOthers(7));
        corr->setPos(x_posOfCard[x] + 20, y_posOfCard[x] + 20);

        wron->setPixmap(wron->setImageOthers(8));
        wron->setPos(x_posOfCard[x] + 35, y_posOfCard[x] + 105);

    } else if( difficultLvl == 52 ){

        corr->setPixmap(corr->setImageOthers(9));
        corr->setPos(x_posOfCard[x] + 15, y_posOfCard[x] + 15);

        wron->setPixmap(wron->setImageOthers(10));
        wron->setPos(x_posOfCard[x] + 25, y_posOfCard[x] + 100);

    } else
        qDebug() << "Error in method DrawCards::showImageAfterReminding(); - if( difficultLvl == 13 ||...";


    buttons.append(corr);
    connect(corr, SIGNAL(clicked()), corr, SLOT(handleClickCorrect()));
    connect(corr, SIGNAL(buttonClickedCorrect(int)), this, SLOT(remember(int)));
    game->scene->addItem(corr);

    buttons.append(wron);
    connect(wron, SIGNAL(clicked()), wron, SLOT(handleClickWrong()));
    connect(wron, SIGNAL(buttonClickedWrong(int)), this, SLOT(wrong(int)));
    game->scene->addItem(wron);

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

void DrawCards::remember(int x){

    Generator_of_random_numbers *generator = new Generator_of_random_numbers();
    int RandomNumber = generator->getRandomNubmer(x);


    // add value to statistic ( correct answer )
    stat->setCorrect(1);

    if( difficultLvl == 13 || difficultLvl == 26 || difficultLvl == 39){

        game->scene->removeItem(listOfCards[x]);
        listOfCards[x]->Picture_Correct( RandomNumber, true );
        game->scene->addItem(listOfCards[x]);

    } else if( difficultLvl == 52 ){

        game->scene->removeItem(listOfCards[x]);
        listOfCards[x]->Picture_Correct( RandomNumber, false );
        game->scene->addItem(listOfCards[x]);

    } else
        qDebug() << "Error in method DrawCards::remember()";


    manageAnswers();

}

void DrawCards::wrong(int x){

    Generator_of_random_numbers *generator = new Generator_of_random_numbers();
    int RandomNumber = generator->getRandomNubmer(x);


    // add value to statistic ( wrong answer )
    stat->setWrong(1);

    if( difficultLvl == 13 || difficultLvl == 26 || difficultLvl == 39){

        game->scene->removeItem(listOfCards[x]);
        listOfCards[x]->Picture_Wrong( RandomNumber, true );
        game->scene->addItem(listOfCards[x]);

    } else if( difficultLvl == 52 ){

        game->scene->removeItem(listOfCards[x]);
        listOfCards[x]->Picture_Wrong( RandomNumber, false );
        game->scene->addItem(listOfCards[x]);

    } else
        qDebug() << "Error in method DrawCards::wrong()";


    manageAnswers();

}


void DrawCards::manageAnswers(){

    // removing the text informing about stopping the clock
    if( counterEnd == 1 ){

        game->scene->removeItem(inf_clock_stop);

        //counterEnd = 12; // TODO delete counterend = 12
    }


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

        stat->manageStatistic();

        game_over *gameOver = new game_over();
        gameOver->drawButtons();

    }
}


void DrawCards::setResetDrawCards(){

    // reset all the important integers, if a player wants to play again
    counter = 0;
    counterEnd = 0;
    tmp = 0;

    for( int i = 0; i < difficultLvl; i++)
        antiRepetition[i] = 0;

    isActive = true;
    listOfCards.clear();
}

