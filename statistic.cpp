#include "statistic.h"
#include "game.h"
#include "timer.h"

#include "game_over.h"
#include "database.h"
#include "statistic_set_data.h"

#include <QFile>
#include <QDebug>
#include <QTextStream>

extern Game *game;

int statistic::correct;
int statistic::wrong;

statistic::statistic(QObject *parent) : QObject (parent){

}

void statistic::hall_of_glory(int level, int X_Position, int Y_Position){

    // Search, downloads and checks data
    statistic_set_data set;
    set.set_the_data(level);

    // Information on the level of difficulty
    QPointer <QGraphicsTextItem> diffi = new QGraphicsTextItem(QString(set.difficult));
    QFont font("comic sans", 21, QFont::Bold);
    diffi->setDefaultTextColor(set.colour);
    diffi->setFont(font);
    diffi->setPos( X_Position, Y_Position );
    game->scene->addItem(diffi);

    // adds a label showing the user best time
    QPointer <QGraphicsTextItem> collapse = new QGraphicsTextItem(QString(set.time));
    collapse->setDefaultTextColor(set.colour);
    collapse->setFont(font);
    collapse->setPos( X_Position + 270, Y_Position );
    game->scene->addItem(collapse);

    // adds a label showing value of correct answers from the best time
    QPointer <QGraphicsTextItem> TbestCorrect = new QGraphicsTextItem(QString(set.correct));
    TbestCorrect->setFont(font);
    TbestCorrect->setDefaultTextColor(Qt::darkGreen);
    TbestCorrect->setPos( X_Position + 470, Y_Position );
    game->scene->addItem(TbestCorrect);

    // adds a label showing value of wrong answers from the best time
    QPointer <QGraphicsTextItem> TbestWrong = new QGraphicsTextItem(QString(set.wrong));
    TbestWrong->setFont(font);
    TbestWrong->setDefaultTextColor(Qt::darkRed);
    TbestWrong->setPos( X_Position + 680, Y_Position );
    game->scene->addItem(TbestWrong);

}



void statistic::showstatic(){

    DataBase db;

    QPointer <game_over> over = new game_over;

    double x_pos = game->scene->width();
    double y_pos = game->scene->height();

    over->drawPanel(x_pos/5, y_pos/5, x_pos/2 + 150, y_pos/2 + 20, Qt::white, 0.75);

    // adds a label showing all the time spent memorizing cards
    QPointer <QGraphicsTextItem> Ttime = new QGraphicsTextItem(QString("Total time: \t\t" + db.select("SELECT SEC_TO_TIME( SUM( TIME_TO_SEC( t_time ) ) ) FROM statistic_db;").mid(0,8)));
    QFont title("comic sans", 24, QFont::Bold);
    Ttime->setFont(title);
    Ttime->setPos(420, 230);
    game->scene->addItem(Ttime);


    // adds a label showing the user best time
    QPointer <QGraphicsTextItem> Tbest = new QGraphicsTextItem(QString("Best time "));
    Tbest->setFont(title);
    Tbest->setPos(470, 290);
    game->scene->addItem(Tbest);

    hall_of_glory(13, 520, 340);
    hall_of_glory(26, 520, 390);
    hall_of_glory(39, 520, 440);
    hall_of_glory(52, 520, 490);


    // adds a label showing all correct answers
    QPointer <QGraphicsTextItem> Tcorrect = new QGraphicsTextItem(QString("Total correct: \t" + db.select("SELECT SUM(correct) FROM statistic_db")));
    Tcorrect->setDefaultTextColor(Qt::darkGreen);
    Tcorrect->setFont(title);
    Tcorrect->setPos(420, 550);
    game->scene->addItem(Tcorrect);

    // adds a label showing all wrong answers
    QPointer <QGraphicsTextItem> Twrong = new QGraphicsTextItem(QString("Total wrong: \t" + db.select("SELECT SUM(wrong) FROM statistic_db")));
    Twrong->setDefaultTextColor(Qt::darkRed);
    Twrong->setFont(title);
    Twrong->setPos(420, 610);
    game->scene->addItem(Twrong);

    // create the back button
    QPointer <Graphic_others> buttonBack = new Graphic_others;
    buttonBack->setPixmap(buttonBack->setImageOthers(1));
    buttonBack->setPos(1270, 630);
    connect(buttonBack, SIGNAL(clicked()), game, SLOT(displayMainMenu()));
    game->scene->addItem(buttonBack);

}


void statistic::ResetStatisticVariable(){

    correct = 0;
    wrong = 0;

}

void statistic::manageStatistic(){

    if(getCorrect() != 0 || getWrong() != 0){

        timer time;
        DataBase db;

        QString clock = time.getTimeStringHour() + time.getTimeStringMin() + time.getTimeStringSec();
        QString difficult = db.select("SELECT difficult FROM user_settings WHERE id = 1");
        QString corr = QString::number(getCorrect());
        QString wro = QString::number(getWrong());

        db.insert("INSERT INTO statistic_db ( data, time, t_time, correct, wrong, difficult ) "
                  "VALUES (NOW(), CURTIME(), " + clock + ", " + corr + ", " + wro + ", \"" + difficult + "\" " + ");");

    } else
         qDebug() << "Error in statistic::manageStatistic()";

}
