#ifndef GAME_OVER_H
#define GAME_OVER_H



#include <QColor>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

#include <QCloseEvent>
#include "statistic.h"
#include <QGraphicsTextItem>
#include <QDebug>

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
    void manageStatistic();

    void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }
    void closeEvent(QCloseEvent *event);


public slots:

    // public slots
    void restartGame();
    void goToStatistics();


signals:
    void clicked();

};

#endif // GAME_OVER_H
