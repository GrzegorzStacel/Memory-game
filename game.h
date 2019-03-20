#ifndef GAME_H
#define GAME_H

#include "mainbuttons.h"
#include "cards.h"
#include "drawcards.h"

#include "game_over.h"
#include "timer.h"
#include "options_difficulty_level.h"

#include "statistic.h"
#include "database.h"
#include "traverse.h"

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
    QPointer <DrawCards> draw;
    QPointer <QGraphicsScene> scene;
    QPointer <QGraphicsTextItem> titleText;
    QPointer <MainButtons> playButton, quitbutton, statisticsbutton, optionsbutton, travers;
    QPointer <game_over> overGame;
    QPointer <options_difficulty_level> difficult;
    QPointer <statistic> sta;
    timer timer;



public slots:

    // public slots
    void start();
    void statisticbutton();
    void displayMainMenu();

};

#endif // GAME_H
