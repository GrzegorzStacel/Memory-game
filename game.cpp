#include "game.h"
#include "drawgui.h"
#include "statistic.h"
#include <QGraphicsTextItem>

#include <QtDebug>
#include <QTimer>
#include <QTime>

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

    timer.start();

    draw = new DrawCards();
    //draw->setVariableForChooseImage(0);

    draw->placeCards(100,600,13);

}



void Game::displayMainMenu(){

    scene->clear();

    timer.setTimeStringSecReset();
    timer.setTimeStringMinReset();
    timer.setTimeStringHourReset();

    // create the title text
    titleText = new QGraphicsTextItem(QString("Memory Cards"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);
    double txPos = this->width()/2 - titleText->boundingRect().width()/2;
    titleText->setPos(txPos, 250);
    scene->addItem(titleText);

    // create the play button
    playButton = new MainButtons(QString("Play"));
    double bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    playButton->setPos(bxPos,450);
    connect(playButton,SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playButton);

    // create the statistics button
    statisticsbutton = new MainButtons(QString("Statistic"));
    statisticsbutton->setPos(bxPos, 550);
    connect(statisticsbutton, SIGNAL(clicked()), this, SLOT(statisticbutton()));
    scene->addItem(statisticsbutton);

    // create the quit button
    quitbutton = new MainButtons(QString("Quit"));
    quitbutton->setPos(bxPos,650);
    connect(quitbutton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitbutton);

}

void Game::statisticbutton(){

    scene->removeItem(titleText);
    scene->removeItem(playButton);
    scene->removeItem(statisticsbutton);
    scene->removeItem(quitbutton);

    statistic *stat = new statistic();
    stat->showstatic();
}

