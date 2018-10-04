#include "game.h"



Game::Game()
{
    //create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1300,867);


    //Background set
    setBackgroundBrush(QBrush(QImage(":/background/images/others/bg.jpg")));


    //Visualize scene and disable scroll bars
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1300,867);

    setScene(scene);


    // add a view to visualize the scene
    //QGraphicsView * view = new QGraphicsView(scene);
}

void Game::keyPressEvent(QKeyEvent *event)
{

}
