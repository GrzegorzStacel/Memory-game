#ifndef GAME_H
#define GAME_H

#include "mainbuttons.h"
#include "cards.h"
#include "drawcards.h"

#include "game_over.h"
#include "timer.h"
#include "options_difficulty_level.h"

#include "statistic.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>



class Game : public QGraphicsView{
    Q_OBJECT

public:

    // constructors
    Game();


private:

    // private attributes
    int choosen;
    bool isGameOver = false;

    // private methods



public:

    // public attributes
    DrawCards *draw;
    Cards *cards, *lvlLabel;
    QGraphicsScene *scene;
    QGraphicsTextItem *titleText;
    MainButtons *playButton, *quitbutton, *statisticsbutton, *optionsbutton;
    game_over *overGame;
    timer timer;
    options_difficulty_level *difficult;
    statistic *sta;



public slots:

    // public slots
    void start();
    void statisticbutton();
    void displayMainMenu();

};

#endif // GAME_H
