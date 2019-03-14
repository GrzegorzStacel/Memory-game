#include "statistic.h"
#include "game.h"
#include "timer.h"

#include "game_over.h"
#include "statisticbesttime.h"
#include "graphic_others.h"

#include "database.h"

#include <QFile>
#include <QDebug>
#include <QTextStream>

extern Game *game;

int statistic::totalTimeHours;
int statistic::totalTimeMinutes;
int statistic::totalTimeSeconds;

int statistic::correct;
int statistic::wrong;


statistic::statistic(){

}

void statistic::showstatic(){

    DataBase db;
    QString bestID = db.select("SELECT id FROM statistic_db WHERE correct = (SELECT MAX(correct) FROM statistic_db) "
                               "AND t_time = (SELECT MIN(t_time) FROM statistic_db "
                                "WHERE correct = (SELECT MAX(correct) FROM statistic_db))",0);

    statisticBestTime best;
    game_over *over = new game_over();

    //read(6,1);

    double x_pos = game->scene->width();
    double y_pos = game->scene->height();

    over->drawPanel(x_pos/5, y_pos/5, x_pos/2 + 150, y_pos/2 - 10, Qt::white, 0.75);

    // adds a label showing all the time spent memorizing cards
    QGraphicsTextItem *Ttime = new QGraphicsTextItem(QString("Total time: \t" + db.select("SELECT SEC_TO_TIME( SUM( TIME_TO_SEC( t_time ) ) ) FROM statistic_db;", 0).mid(0,8)));
    QFont title("comic sans", 25, QFont::Bold);
    Ttime->setFont(title);
    Ttime->setPos(x_pos/5 + 25, y_pos - 750);
    game->scene->addItem(Ttime);

    // adds a label showing the user best time
    QGraphicsTextItem *Tbest = new QGraphicsTextItem(QString("Best time: \t\t"+ db.select("SELECT t_time FROM statistic_db WHERE id = " + bestID + ";",0).mid(0,8)));
    Tbest->setFont(title);
    Tbest->setPos(x_pos/5 + 25, y_pos - 675);
    game->scene->addItem(Tbest);

    // adds a label showing value of correct answers from the best time
    QGraphicsTextItem *TbestCorrect = new QGraphicsTextItem(QString("Correct: " + db.select("SELECT correct FROM statistic_db WHERE id = " + bestID + ";",0)));
    QFont title2("comic sans", 15, QFont::Bold);
    TbestCorrect->setFont(title2);
    TbestCorrect->setDefaultTextColor(Qt::darkGreen);
    TbestCorrect->setPos(x_pos/2 + 225, y_pos - 660);
    game->scene->addItem(TbestCorrect);

    // adds a label showing value of wrong answers from the best time

    QGraphicsTextItem *TbestWrong = new QGraphicsTextItem(QString("Wrong: " + db.select("SELECT wrong FROM statistic_db WHERE id = " + bestID + ";",0)));
    TbestWrong->setFont(title2);
    TbestWrong->setDefaultTextColor(Qt::darkRed);
    TbestWrong->setPos(x_pos/2 + 380, y_pos - 660);
    game->scene->addItem(TbestWrong);

    // adds a label showing all correct answers
    QGraphicsTextItem *Tcorrect = new QGraphicsTextItem(QString("Total correct: \t" + db.select("SELECT SUM(correct) FROM statistic_db", 0)));
    Tcorrect->setDefaultTextColor(Qt::darkGreen);
    Tcorrect->setFont(title);
    Tcorrect->setPos(x_pos/5 + 25, y_pos - 600);
    game->scene->addItem(Tcorrect);

    // adds a label showing all wrong answers
    QGraphicsTextItem *Twrong = new QGraphicsTextItem(QString("Total wrong: \t" + db.select("SELECT SUM(wrong) FROM statistic_db",0)));
    Twrong->setDefaultTextColor(Qt::darkRed);
    Twrong->setFont(title);
    Twrong->setPos(x_pos/5 + 25, y_pos - 525);
    game->scene->addItem(Twrong);

    // create the back button
    Graphic_others *buttonBack = new Graphic_others();
    buttonBack->setPixmap(buttonBack->setImageOthers(1));
    buttonBack->setPos(x_pos/2 + 100, y_pos - 400);
    connect(buttonBack, SIGNAL(clicked()), game, SLOT(displayMainMenu()));
    game->scene->addItem(buttonBack);

    best.ResetStaticBestTimeVariable();
}


void statistic::ResetStatisticVariable(){

    totalTimeHours = 0;
    totalTimeMinutes = 0;
    totalTimeSeconds = 0;

    correct = 0;
    wrong = 0;
}

void statistic::manageStatistic(){

    if(getCorrect() != 0 || getWrong() != 0){

        timer time;
        DataBase db;

        QString clock = time.getTimeStringHour() + time.getTimeStringMin() + time.getTimeStringSec();
        QString difficult = db.select("SELECT difficult FROM user_settings WHERE id = 1", 0);
        QString corr = QString::number(getCorrect());
        QString wro = QString::number(getWrong());

        db.insert("INSERT INTO statistic_db ( data, time, t_time, correct, wrong, difficult ) "
                  "VALUES (NOW(), CURTIME(), " + clock + ", " + corr + ", " + wro + ", \"" + difficult + "\" " + ");");

    } else
         qDebug() << "Error in statistic::manageStatistic()";

}

//                                     Attention!
//
// I used non-portable file addresses because the compiler makes strange problems with writing to a file when
// given files are added to resources.
// There were no problems with the reading only with the record.
