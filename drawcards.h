#ifndef DRAWCARDS_H
#define DRAWCARDS_H

#include "cards.h"

#include <QGraphicsSceneMouseEvent>
#include <QList>

class DrawCards{

    QList<Cards *> listOfCards;
    void createBoard(int x, int y, int cards);

public:
    DrawCards();

    void placeCards(int x, int y, int cards);
    void mousePressEvent(QGraphicsSceneMouseEvent *event) { emit clicked(); }

signals:
    void clicked();

};

#endif // DRAWCARDS_H
