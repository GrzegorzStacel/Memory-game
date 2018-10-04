#include "game.h"


#include <QtDebug>

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

    //Create main menu
     scene->addItem(main);
     main->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
     main->setFocus();

}

void Game::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Keypressevent work";
}
