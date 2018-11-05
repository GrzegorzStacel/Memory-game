#ifndef GAME_H
#define GAME_H

#include "mainbuttons.h"
#include "cards.h"
#include "drawcards.h"
#include "game_over.h"
#include "timer.h"

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


public:

    // public attributes
    DrawCards *draw;
    Cards *cards;
    QGraphicsScene *scene;
    QGraphicsTextItem *titleText;
    MainButtons *playButton, *quitbutton, *statisticsbutton;
    game_over *overGame;
    timer timer;



public slots:

    // public slots
    void start();
    void statisticbutton();
    void displayMainMenu();

};

#endif // GAME_H
