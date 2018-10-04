#ifndef GAME_H
#define GAME_H

#include "mainbuttons.h"

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
class Game : public QGraphicsView{
public:
    Game();

    void keyPressEvent(QKeyEvent *event);

    QGraphicsScene *scene;
    MainButtons *main = new MainButtons();
};

#endif // GAME_H
