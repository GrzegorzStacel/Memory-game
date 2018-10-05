#include "game.h"



#include <QtDebug>
//#include <QGraphicsItem>

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

void Game::start(){

    scene->clear();
    VisualizeCards();


}

void Game::VisualizeCards(){

        int x = 300, y = 600, start = 1, end = 3;

        cards[0] = new Cards(0);
        cards[0]->setPos(150, y);
        scene->addItem(cards[0]);

        for(int i = 0; i < 3; ++i, ++start){
            for(; start < end; ++start){

                if(start == 6){
                    y-=250;
                    x=150;
                }
                else if(start == 12){
                    y-=250;
                    x=575;
                }

                     cards[start] = new Cards(start+1);
                     cards[start]->setPos(x, y);
                     scene->addItem(cards[start]);

                     x += 150;
            }
            x += 100;
            end += 6;
            --start;
        }
}


