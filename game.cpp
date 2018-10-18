#include "game.h"


#include <QGraphicsTextItem>

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

}

void Game::start(){

    scene->clear();

    cards = new Cards();
    cards->generatorOfRandomNumbers();

    draw = new DrawCards();
    draw->placeCards(100,600,13);


}


void Game::displayMainMenu(){
    // create the title text
    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("Memory Cards"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);
    double txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 250;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);

    // create the play button
    MainButtons *playButton = new MainButtons(QString("Play"));
    double bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 450;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    MainButtons *quitbutton = new MainButtons(QString("Quit"));
    double qxPos = this->width()/2 - quitbutton->boundingRect().width()/2;
    int qyPos = 550;
    quitbutton->setPos(qxPos,qyPos);
    connect(quitbutton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitbutton);


}

void Game::gameOver(){
    overGame = new game_over();
}

