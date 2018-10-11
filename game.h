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

    int choosen;

public:
    Game();

    void VisualizeCards();
    void displayMainMenu();


    Cards *cards[13];
    QGraphicsScene *scene;


public slots:
    void start();

};

#endif // GAME_H
