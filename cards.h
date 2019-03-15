#ifndef CARDS_H
#define CARDS_H


#include "graphic_cards.h"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QObject>
#include <QDebug>

class Cards : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:

    bool isActive;
    bool level;
    int x_pos_card;
    int y_pos_card;
//    int x_pos_button;
//    int y_pos_button;
    int graphic;

    // constructors
    Cards();
    Cards(bool active, bool lvl, int x_car, int y_car);


    // Public Methods
    void setActive(bool isActive, bool lvl);



    inline void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }



signals:

    //signals
    void clicked();

};

#endif // CARDS_H
