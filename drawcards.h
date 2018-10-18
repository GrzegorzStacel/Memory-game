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

#include <QtAlgorithms>

class DrawCards : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:

    // constructors
    DrawCards();


private:

    //private attributes
    QList<Cards *> listOfCards;
    QList<MainButtons *> buttons;
    static int antiRepetition[13]; // TODO change value to difficult
    static int tmp;
    static int counter;
    static int counterEnd;
    static int x_posOfCard[13]; // TODO change value to difficult
    static int y_posOfCard[13]; // TODO change value to difficult

    // private methods
    void createBoard(int x, int y, bool iisActive);
    void connectCardWithMap();
    bool isItRepeat(int, int);



public:

    // public attributes
    Cards *cards;

    // public methods
    void placeCards(int x, int y, int cards);
    inline void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }

    // setter
    void setResetAllInOne();


public slots:
    void addImageWithRandomNumber(); // first part of game ( memorizing )
    int showImageAfterReminding(int); // second part of game ( reminder from memory )
    void remember(); // if the player remembers well
    void wrong(); // if the player misbehaves



signals:
    void clicked();

};

#endif // DRAWCARDS_H
