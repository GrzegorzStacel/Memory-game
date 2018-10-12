#ifndef GAME_H
#define GAME_H

#include "mainbuttons.h"
#include "cards.h"

//#include "QObject"
//#include <QGraphicsItem>
//#include <QGraphicsRectItem>
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
    Cards *cards[13];
    QGraphicsScene *scene;

    // public methods
    void VisualizeCards();
    void displayMainMenu();


public slots:

    // public slots
    void start();

};

#endif // GAME_H
