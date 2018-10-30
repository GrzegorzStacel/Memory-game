#ifndef GAME_OVER_H
#define GAME_OVER_H



#include <QColor>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

#include "statistic.h"


class game_over : public QObject{
    Q_OBJECT

public:

    // constructors
    game_over();

    // public attributes
    statistic *stat;



    // public methods
    void drawPanel(double, double, double, double, QColor, double);
    void drawButtons();
    void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }

public slots:

    // public slots
    void restartGame();


signals:
    void clicked();

};

#endif // GAME_OVER_H
