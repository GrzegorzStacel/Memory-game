#ifndef CARDS_H
#define CARDS_H


#include "graphic_cards.h"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QObject>
#include <QDebug>

class Cards : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

private:
    bool isActive;
    bool level;
    int x_pos_card;
    int y_pos_card;
    int graphic;

public:
    // constructors
    Cards(QObject *parent = nullptr);
    Cards(bool active, bool lvl, int x_car, int y_car);


    // Public Methods
    void setActive(bool isActive, bool lvl);
    void Picture_Neutral(int value, bool lvl);
    void Picture_Correct(int value, bool lvl);
    void Picture_Wrong(int value, bool lvl);

    // getters
    int getX_POS() const { return x_pos_card; }
    int getY_POS() const { return y_pos_card; }


    inline void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }
    graphic_cards picture;


signals:

    //signals
    void clicked();

};

#endif // CARDS_H
