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
int DrawCards::variableForChooseImage;
int DrawCards::tmp;
bool DrawCards::isActive = true;


DrawCards::DrawCards(){

}
void DrawCards::drawcardsManager(int level){

    difficultLvl = level;

    {
        Cards_Position position;
        position.select_lvl(level);

        createCards(position);
    }

}

void DrawCards::createCards(Cards_Position & position){

    int x = 0, y = 0;
    bool activ, which;

    for(int i = 0; i < difficultLvl; ++i ){

        x = position.getX_POS(i);
        y = position.getY_POS(i);
        activ = position.getActive(i);
        which = position.getWhich_Card();

        cards = new Cards(activ, which, x, y );

        cards->setPos(x, y);
        listOfCards.append(cards);
        connect(cards, SIGNAL(clicked()), this, SLOT(addImageWithRandomNumber()));
        game->scene->addItem(cards);
    }

    finish = true;

    // Cheating variable that speeds up tests
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

                    counter++;

                    timer time;
                    time.setMRunning(false);
                    isActive = false;
                    time.stop();


                    if( finish ){

                        // create text annoucning winner
                        inf_clock_stop->setPos(game->scene->width()/4+70, 15);
                        inf_clock_stop->setPixmap(inf_clock_stop->setImageOthers(5));
                        game->scene->addItem(inf_clock_stop);

                        finish = false;

                    }

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

                    if( finish ){

                        // create text annoucning winner
                        inf_clock_stop->setPos(game->scene->width()/4+70, 15);
                        inf_clock_stop->setPixmap(inf_clock_stop->setImageOthers(5));
                        game->scene->addItem(inf_clock_stop);

                        finish = false;

                    }

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

        antiRepetition.insert( tmp, x );
        tmp++;
        counterEnd++;

        // Send this value to methods Correct and Wrong by the signal slot
        setVariableForChooseImage(x);
    }


    Graphic_others *corr = new Graphic_others();
    Graphic_others *wron = new Graphic_others();

    int x_pos = listOfCards[x]->getX_POS();
    int y_pos = listOfCards[x]->getY_POS();

    // Add the buttons correct and wrong

    if( difficultLvl == 13 || difficultLvl == 26 || difficultLvl == 39){

        corr->setPixmap(corr->setImageOthers(7));
        corr->setPos(x_pos + 20, y_pos + 20);

        wron->setPixmap(wron->setImageOthers(8));
        wron->setPos(x_pos + 35, y_pos + 105);

    } else if( difficultLvl == 52 ){

        corr->setPixmap(corr->setImageOthers(9));
        corr->setPos(x_pos + 15, y_pos + 15);

        wron->setPixmap(wron->setImageOthers(10));
        wron->setPos(x_pos + 25, y_pos + 100);

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


for(int i =0; i<selected; i++){
    qDebug() << i << "A. isrepeat: " << antiRepetition.value(i);
    qDebug() << i << "B. xNumber: " << xNumber << endl;
}
qDebug() << "==================================";


    for(int i = 0; i < selected; i++){
    qDebug() << "sprawdzam antirepetition( " << i << " ): " << antiRepetition.value(i) << " i xnumber : " << xNumber;
        if( antiRepetition.value( i ) == xNumber){
            qDebug() << "antirepetition( " << i << " ) " << antiRepetition.value(i) << " == xnumber czyli nr karty ( " << xNumber << " )";
            return true;
        }
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
          if(antiRepetition.value( i )  > antiRepetition.value( i + 1 )) {

            x = antiRepetition.value( i );
            antiRepetition.replace( i, antiRepetition.value( i + 1 ) );
            antiRepetition.replace( i + 1, x );
    }


    // disable all "visible" (selected) cards and else set enabled
    int i = 0;
    int n = 0;

    do{
        qDebug() << "i = " << i << " ,antirepetition ( " << n << " ) : " << antiRepetition.value(n) << " , tmp : " << tmp;
        if( i == antiRepetition.value( n ) && n <= tmp ){

            listOfCards[ antiRepetition.value( n ) ]->setEnabled(false);
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

    antiRepetition.clear();

    isActive = true;
    listOfCards.clear();
}

