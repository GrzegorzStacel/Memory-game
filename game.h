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
    //game_over *overGame;
    timer timer;


    // public methods
    void displayMainMenu();
    //void gameOver();
    //void startClock();
    void setisGameOver(bool value) { isGameOver = value; }


public slots:

    // public slots
    void start();

};

#endif // GAME_H
