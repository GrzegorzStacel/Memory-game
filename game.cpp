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
    scene->setSceneRect(0,0,1920,990);


    //Background set
    setBackgroundBrush(QBrush(QImage(":/background/images/others/bg_1920x1080.jpg")));


    //Visualize scene and disable scroll bars
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1920,990);

}

void Game::start(){

    int difficultLvl = sta->read(7,0).toInt();

    scene->clear();

    cards = new Cards();
    cards->generatorOfRandomNumbers(difficultLvl);

    timer.start();

    sta = new statistic();
    int difficult;
    difficult = sta->read(7, 1).toInt();

    draw = new DrawCards();
    draw->placeCards(475, 650, difficultLvl);
    //draw->placeCards(475,650,13);

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

    // creating information with information about the last selected / and current level of difficulty
    cards = new Cards();
    cards->setPixmap(cards->setImageOthers(2));
    cards->setToolTip("Click the options button to change the difficulty level");
    cards->setPos(bxPos + 300, 800);
    scene->addItem(cards);

    // showing the label with actually level of difficulty
    lvlLabel = new Cards();
    int showDifficult = 0;

    showDifficult = sta->read(7,0).toInt();

    if( showDifficult == 13 )
        lvlLabel->setPixmap(lvlLabel->setImageOptions(3));
    else if( showDifficult == 26 )
        lvlLabel->setPixmap(lvlLabel->setImageOptions(4));
    else if( showDifficult == 39 )
        lvlLabel->setPixmap(lvlLabel->setImageOptions(5));
    else if( showDifficult == 52 )
        lvlLabel->setPixmap(lvlLabel->setImageOptions(6));
    else
        qDebug() << "Error in method game::displayMainMenu - if/else...";


    lvlLabel->setPos(bxPos + 495, 890);
    scene->addItem(lvlLabel);

}

void Game::statisticbutton(){

    scene->clear();

    statistic *stat = new statistic();
    stat->showstatic();
}

