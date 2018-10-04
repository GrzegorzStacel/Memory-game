#ifndef GAME_H
#define GAME_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
class Game : public QGraphicsView{
public:
    Game();

    void keyPressEvent(QKeyEvent *event);

    QGraphicsScene *scene;
};

#endif // GAME_H
