#include "game.h"
#include "statistic.h"
#include "statisticbesttime.h"
#include "generator_of_random_numbers.h"
#include "graphic_options.h"

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

    sta = new statistic();
    int difficultLvl = sta->read(7,0).toInt();

    scene->clear();

    //cards = new Cards();
    //cards->generatorOfRandomNumbers(difficultLvl);

    Generator_of_random_numbers *generator = new Generator_of_random_numbers();
    generator->GenerateNumber(difficultLvl);

    timer.start();



    draw = new DrawCards();
    draw->setDifficultLvl(difficultLvl);

    if( difficultLvl == 13 )
        draw->placeCardsEasy(475, 650, difficultLvl);
    if( difficultLvl == 26 )
        draw->placeCardsMedium(120, 720, difficultLvl);
    if( difficultLvl == 39 )
        draw->placeCardsHard(5, 740, difficultLvl);
    if( difficultLvl == 52 )
        draw->placeCardsHardcore(70, 790, difficultLvl);


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
    Graphic_options *graphic = new Graphic_options();
    int showDifficult = 0;

    showDifficult = sta->read(7,0).toInt();

    if( showDifficult == 13 )
        graphic->setPixmap(graphic->setImageOptions(3));
    else if( showDifficult == 26 )
        graphic->setPixmap(graphic->setImageOptions(4));
    else if( showDifficult == 39 )
        graphic->setPixmap(graphic->setImageOptions(5));
    else if( showDifficult == 52 )
        graphic->setPixmap(graphic->setImageOptions(6));
    else
        qDebug() << "Error in method game::displayMainMenu - if/else...";


    graphic->setPos(bxPos + 495, 890);
    scene->addItem(graphic);

}

void Game::statisticbutton(){

    scene->clear();

    statistic *stat = new statistic();
    stat->showstatic();
}

