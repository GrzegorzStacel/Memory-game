#include "game.h"
#include "drawgui.h"
#include "statistic.h"
#include "statisticbesttime.h"

#include <QGraphicsTextItem>

#include <QtDebug>
#include <QTimer>
#include <QTime>

Game::Game()
{
    //create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1920,1080);


    //Background set
    setBackgroundBrush(QBrush(QImage(":/background/images/others/bg_1920x1080.jpg")));


    //Visualize scene and disable scroll bars
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1920,1080);

}

void Game::start(){

    scene->clear();

    cards = new Cards();
    cards->generatorOfRandomNumbers();

    timer.start();

    draw = new DrawCards();
    draw->placeCards(475,650,13);

}



void Game::displayMainMenu(){

    statisticBestTime statBest;
    statBest.ResetStaticBestTimeVariable();

    scene->clear();

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

    // create the options button
    optionsbutton = new MainButtons(QString("Options"));
    difficult = new options_difficulty_level();
    optionsbutton->setPos(bxPos, 650);
    connect(optionsbutton, SIGNAL(clicked()), difficult, SLOT(show_options()));
    scene->addItem(optionsbutton);

    // create the quit button
    quitbutton = new MainButtons(QString("Quit"));
    quitbutton->setPos(bxPos,750);
    connect(quitbutton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitbutton);

}

void Game::statisticbutton(){

    scene->removeItem(titleText);
    scene->removeItem(playButton);
    scene->removeItem(statisticsbutton);
    scene->removeItem(optionsbutton);
    scene->removeItem(quitbutton);

    statistic *stat = new statistic();
    stat->showstatic();
}

