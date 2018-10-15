#ifndef DRAWCARDS_H
#define DRAWCARDS_H

#include "mainbuttons.h"
#include "cards.h"
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QList>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class DrawCards : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:

    // constructors
    DrawCards();


private:

    //private attributes
    QList<Cards *> listOfCards;
    static int counter;
    static int x_posOfCard[13]; // TODO change value to difficult
    static int y_posOfCard[13]; // TODO change value to difficult

    // private methods
    void createBoard(int x, int y, bool iisActive);
    void connectCardWithMap();


public:

    // public attributes
    QList<Cards *> getCards() { return listOfCards; }
    Cards *cards;

    // public methods
    void placeCards(int x, int y, int cards);
    void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }



public slots:
    void addImageWithRandomNumber(); // first part of game
    void showImageAfterReminding(int); // second part of game


signals:
    void clicked();

};

#endif // DRAWCARDS_H
