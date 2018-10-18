#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "drawcards.h"

#include <QColor>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class game_over : public QObject{
    Q_OBJECT

public:
    // constructors
    game_over();

    // public attributes
    DrawCards *draw;

    // public methods
    void drawPanel(int, int, double, double, QColor, double);
    void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }

public slots:
    // public slots
    void restartGame();
    void close();


signals:
    void clicked();


};

#endif // GAME_OVER_H
