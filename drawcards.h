#ifndef DRAWCARDS_H
#define DRAWCARDS_H

#include "mainbuttons.h"
#include "cards.h"
#include "statistic.h"
#include "graphic_others.h"

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
    static int x_posOfCard[52]; // TODO change value to difficult
    static int y_posOfCard[52]; // TODO change value to difficult
    static int variableForChooseImage;
    static int difficultLvl;
    QString statisticBestTimeCurrentDateAndGameTime;

    // private methods
    void createBoard(int x, int y, bool iisActive);
    void connectCardWithMap();
    bool isItRepeat(int, int);
    void manageAnswers();


public:

    // public attributes
    Cards *cards;
    statistic *stat;
    Graphic_others *graphic, *inf_clock_stop;

    static bool isActive;

    // public methods
    void placeCardsEasy(int x, int y, int cards);
    void placeCardsMedium(int x, int y, int cards);
    void placeCardsHard(int x, int y, int cards);
    void placeCardsHardcore(int x, int y, int cards);
    inline void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }

    // setters
    void setResetDrawCards();
    void setVariableForChooseImage(const int value)         { variableForChooseImage = value; }
    void setDifficultLvl(const int value)                   { difficultLvl = value; }

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
