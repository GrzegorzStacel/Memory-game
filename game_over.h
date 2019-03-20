#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "statisticbesttime.h"
#include "statistic.h"

#include <QColor>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

#include <QCloseEvent>
#include <QGraphicsTextItem>
#include <QDebug>
#include <QPointer>

class game_over : public QObject{
    Q_OBJECT

public:

    // constructors
    game_over(QObject *parent = nullptr);

    // public attributes
    QPointer <statistic> stat;



    // public methods
    void drawPanel(double, double, double, double, QColor, double);
    void drawButtons();

    void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }
    void closeEvent(QPointer <QCloseEvent> event);


public slots:

    // public slots
    void restartGame();
    void goToStatistics();


signals:
    void clicked();

};

#endif // GAME_OVER_H
