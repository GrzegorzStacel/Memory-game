#ifndef DRAWCARDS_H
#define DRAWCARDS_H

#include "cards.h"

#include <QGraphicsSceneMouseEvent>
#include <QList>

class DrawCards{

public:

    // constructors
    DrawCards();


private:

    //private attributes
    QList<Cards *> listOfCards;
    QList<int> listOfImage;

    // private methods
    void createBoard(int x, int y, int cards);


public:

    // public attributes
    QList<Cards *> getCards() { return listOfCards; }

    // public methods
    void placeCards(int x, int y, int cards);
    void mousePressEvent(QGraphicsSceneMouseEvent *event) { emit clicked(); }
    void cardSupport();


signals:

    // public signals
    void clicked();

};

#endif // DRAWCARDS_H
