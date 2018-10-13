#ifndef DRAWCARDS_H
#define DRAWCARDS_H

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

    // private methods
    void createBoard(int x, int y, bool iisActive);


public:

    // public attributes
    QList<Cards *> getCards() { return listOfCards; }
    Cards *cards;

    // public methods
    void placeCards(int x, int y, int cards);
    void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }



public slots:
    void addImageWithRandomNumber();

signals:
    void clicked();

};

#endif // DRAWCARDS_H
