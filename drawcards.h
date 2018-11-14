#ifndef DRAWCARDS_H
#define DRAWCARDS_H

#include "mainbuttons.h"
#include "cards.h"
#include "statistic.h"

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
    static int variableForChooseImage;
    QString statisticBestTimeCurrentDateAndGameTime;

    // private methods
    void createBoard(int x, int y, bool iisActive);
    void connectCardWithMap();
    bool isItRepeat(int, int);
    void manageAnswers();


public:

    // public attributes
    Cards *cards, *information;
    statistic *stat;

    static bool isActive;

    // public methods
    void placeCards(int x, int y, int cards);
    inline void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }

    // setters
    void setResetDrawCards();
    void setVariableForChooseImage(const int value) { variableForChooseImage = value; }

    // getters
    int getVariableForChooseImage() { return variableForChooseImage; }


public slots:
    void addImageWithRandomNumber(); // first part of game ( memorizing )
    void showImageAfterReminding(int); // second part of game ( reminder from memory )
    void remember(int x); // if the player remembers well
    void wrong(int x); // if the player misbehaves



signals:
    void clicked();

};

#endif // DRAWCARDS_H
