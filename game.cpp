#include "game.h"
#include "statistic.h"
#include "generator_of_random_numbers.h"
#include "graphic_options.h"
#include "graphic_others.h"

#include <QGraphicsTextItem>
#include <QtDebug>
#include <QTimer>
#include <QTime>

Game::Game(){

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

    QString result;

    {

        DataBase db;

        // Set the user settings - difficult
        result = db.select("SELECT difficult FROM user_settings WHERE id = 1", 0);

        // Update the best time and amount of correct for later comparisons in who_is_best::comparison()
        QString best_id = db.select("SELECT id FROM statistic_db WHERE correct = (SELECT MAX(correct) FROM statistic_db) "
                  "AND t_time = (SELECT MIN(t_time) FROM statistic_db "
                   "WHERE correct = (SELECT MAX(correct) FROM statistic_db))", 0);

        db.insert("UPDATE user_settings SET b_time = (SELECT t_time FROM statistic_db WHERE id = " + best_id + "), "
                  "b_correct = (SELECT correct FROM statistic_db WHERE id = " + best_id + ");");

    }

    int difficultLvl = result.toInt();


    scene->clear();


    Generator_of_random_numbers *generator = new Generator_of_random_numbers();
    generator->GenerateNumber(difficultLvl);

    timer.start();

    draw = new DrawCards();
    draw->drawcardsManager(difficultLvl);

}



void Game::displayMainMenu(){

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

    // create the travers button
    Traverse *trav = new Traverse();
//    travers = new MainButtons(QString("Travers"));
//    travers->setPos(bxPos,550);
//    connect(travers, SIGNAL(clicked()), trav, SLOT(lets_start()));
//    scene->addItem(travers);
//    trav->lets_start();
    // create the statistics button
    statisticsbutton = new MainButtons(QString("Statistic"));
    statisticsbutton->setPos(bxPos, 650);
    connect(statisticsbutton, SIGNAL(clicked()), this, SLOT(statisticbutton()));
    scene->addItem(statisticsbutton);

    // create the options button
    optionsbutton = new MainButtons(QString("Options"));
    difficult = new options_difficulty_level();
    optionsbutton->setPos(bxPos, 750);
    connect(optionsbutton, SIGNAL(clicked()), difficult, SLOT(show_options()));
    scene->addItem(optionsbutton);

    // create the quit button
    quitbutton = new MainButtons(QString("Quit"));
    quitbutton->setPos(bxPos,850);
    connect(quitbutton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitbutton);

    // creating information with information about the last selected / and current level of difficulty
    //cards = new Cards();
    Graphic_others *actual_lvl = new Graphic_others();
    actual_lvl->setPixmap(actual_lvl->setImageOthers(2));
    actual_lvl->setToolTip("Click the options button to change the difficulty level");
    actual_lvl->setPos(bxPos + 300, 800);
    scene->addItem(actual_lvl);

    // showing the label with actually level of difficulty
    Graphic_options *graphic = new Graphic_options();

    int showDifficult = 0;
    QString result;

    {
        DataBase db;
        result = db.select("SELECT difficult FROM user_settings WHERE id = 1", 0);
    }

    showDifficult = result.toInt();

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

