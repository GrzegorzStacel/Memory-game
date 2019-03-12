#include "game.h"
#include "statistic.h"
#include "statisticbesttime.h"
#include "generator_of_random_numbers.h"
#include "graphic_options.h"
#include "graphic_others.h"

#include <QGraphicsTextItem>
#include <QtDebug>
#include <QTimer>
#include <QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>


Game::Game()
{




                                     // TESTING DATA BASE
// --------------------------------------------------------------------------------------------------------------
//    {
//        DataBase db;
//            if(db.data_base().open()) {


//                qDebug() << "Game open";

//                int h = 100;
//                QString insert = "INSERT INTO statistic_db "

//                                 "( data, time, t_time, hour, minutes, seconds, miliseconds, "
//                                 "correct, wrong, difficult ) "

//                                 "VALUES (NOW(), CURTIME(), 001032, " + QString::number(h) +
//                                 ", 20, 12, 234, 12, 55, \"hard\" )";

//                db.data_base().exec(insert);

//            } else {
//                qDebug() << db.data_base().lastError();
//                qDebug() << "Game error";
//            }
//        qDebug() << "Game close";
//    }

//        {
//            DataBase db;
//            qDebug() << "wynik selecta: " + db.select("SELECT t_time FROM statistic_db WHERE id = 17", 0 );
//        }

//    base->query("SELECT data FROM statistic_db", 0);
//    base->query("SELECT data, time FROM statistic_db", 0, 1);

//    if(base->data_base().open()) {

//        qDebug() << "DB is opened ( all )";

//        QSqlQuery ask;

//        if(ask.exec("SELECT * FROM statistic_db")){
//            while(ask.next()){
//                qDebug() << ask.value(0).toString() + " - " +
//                            ask.value(1).toString() + " - " +
//                            ask.value(2).toString() + " - " +
//                            ask.value(3).toString() + " - " +
//                            ask.value(4).toString() + " - " +
//                            ask.value(5).toString() + " - " +
//                            ask.value(6).toString() + " - " +
//                            ask.value(7).toString() + " - " +
//                            ask.value(8).toString() + " - " +
//                            ask.value(9).toString();

//            }
//        }

//    } else {
//        qDebug() << "Error load: " << base->data_base().lastError();
//    }

//    qDebug() << "Closing...";
//    base->data_base().close();

// --------------------------------------------------------------------------------------------------------------


    DataBase db;
    db.insert("INSERT INTO statistic_db (minutes) VALUES (13)");



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
        result = db.select("SELECT difficult FROM settings", 0);
    }

    int difficultLvl = result.toInt();


    scene->clear();


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
        result = db.select("SELECT difficult FROM settings", 0);
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

