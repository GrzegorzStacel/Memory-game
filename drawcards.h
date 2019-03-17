#ifndef DRAWCARDS_H
#define DRAWCARDS_H

#include "mainbuttons.h"
#include "cards.h"
#include "statistic.h"
#include "graphic_others.h"
#include "cards_position.h"

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
    QList<Graphic_others *> buttons;
    static int antiRepetition[52]; // TODO change value to difficult
    static int tmp;
    static int counter;
    static int counterEnd;
    static int variableForChooseImage;
    static int difficultLvl;
    bool finish;

    // private methods
    void createCards(Cards_Position &);
    void connectCardWithMap();
    bool isItRepeat(int, int);
    void manageAnswers();


public:

    // public attributes
    Cards *cards;
    statistic *stat;
    Graphic_others *inf_clock_stop = new Graphic_others();

    static bool isActive;

    // public methods
    void drawcardsManager(int level);
    inline void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }

    // setters
    void setResetDrawCards();
    void setVariableForChooseImage(const int value)         { variableForChooseImage = value; }

    // getters
    int getVariableForChooseImage()                         { return variableForChooseImage; }


public slots:
    void addImageWithRandomNumber(); // first part of game ( memorizing )
    void showImageAfterReminding(int); // second part of game ( reminder from memory )
    void remember(int x); // if the player remembers well
    void wrong(int x); // if the player misbehaves



signals:
    void clicked();

};

#endif // DRAWCARDS_H
