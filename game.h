#ifndef GAME_H
#define GAME_H

#include "mainbuttons.h"
#include "cards.h"
#include "drawcards.h"
#include "game_over.h"

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


public:

    // public attributes
    DrawCards *draw;
    Cards *cards;
    QGraphicsScene *scene;
    game_over *overGame;


    // public methods
    void displayMainMenu();
    void gameOver();


public slots:

    // public slots
    void start();

};

#endif // GAME_H
