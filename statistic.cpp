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

QString statistic::read(int valueA, int valueB){

    QFile file;

    // I added a description at the bottom of the page about the address of the file
    switch (valueA) {
        case 1: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalCorrect.txt"); break;
        case 2: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalWrong.txt"); break;
        case 3: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalTimeSeconds.txt"); break;
        case 4: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalTimeMinutes.txt"); break;
        case 5: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalTimeHours.txt"); break;
        case 6: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalTime.txt"); break;
        case 7: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/settings.txt"); break;

        default:
            qDebug() << "Attention! in statistic::read (1 arg) - does not have \"" << valueA << "\" value."; break;
    }

    // Protecion
    if(!file.exists()){
        qDebug() << file.fileName() << " does not exists";
    }

    QString line;
    statisticBestTime *best = new statisticBestTime();
    int i = 0;

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){

        if(valueB == 1){

            while(!file.atEnd()){

                line = file.readLine();
                best->transformationSring(line, i);
                ++i;
            }
        } else {

            line = file.readAll();
        }

    } else {

        qDebug() << "In method statistic::read could not open file for read.";
        return nullptr;
    }


    file.close();
    return line;
}


void statistic::write(int valueA, int valueB){

    QFile file;

    // I added a description at the bottom of the page about the address of the file
    switch (valueA) {

        case 1: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalCorrect.txt"); break;
        case 2: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalWrong.txt"); break;
        case 3: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalTimeSeconds.txt"); break;
        case 4: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalTimeMinutes.txt"); break;
        case 5: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalTimeHours.txt"); break;
        case 6: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalTime.txt"); break;
        case 7: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/settings.txt"); break;

        default:
            qDebug() << "Attention! in statistic::write 1 - does not have \"" << valueA << "\" value."; break;
    }

    if(valueB == 1){

            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){

                qDebug() << "In method statistic::write could not open file for write (append).";
                return;
            }

    } else {

            if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){

                qDebug() << "In method statistic::write could not open file for write (overwrite).";
                return;
            }
    }

    QTextStream out(&file);
    statisticBestTime best;

    switch (valueA) {
        //case 1: out << getTotalCorrect();              break;
        //case 2: out << getTotalWrong();                break;
        case 3: out << getTotalTimeSeconds();          break;
        case 4: out << getTotalTimeMinutes();          break;
        case 5: out << getTotalTimeHours();            break;
        case 6: out << best.getComplete();             break;
        case 7: out << getSettings();                  break;

        default:
            qDebug() << "Attention! in statistic::write 2- does not have \"" << valueA << "\" value."; break;
    }

    file.flush();
    file.close();
}


void statistic::showstatic(){

    DataBase db;
    QString bestID = db.select("SELECT id FROM statistic_db WHERE correct = (SELECT MAX(correct) FROM statistic_db) "
                               "AND t_time = (SELECT MIN(t_time) FROM statistic_db "
                               "    WHERE correct = (SELECT MAX(correct) FROM statistic_db))",0);

    qDebug() << "bestID " << bestID;
    timer *time = new timer();
    statisticBestTime best;
    game_over *over = new game_over();

    QString tmp = time->showTotalTime();

    read(6,1);

    double x_pos = game->scene->width();
    double y_pos = game->scene->height();

    over->drawPanel(x_pos/5, y_pos/5, x_pos/2 + 150, y_pos/2 - 10, Qt::white, 0.75);

    // adds a label showing all the time spent memorizing cards
    QGraphicsTextItem *Ttime = new QGraphicsTextItem(QString("Total time: \t" + tmp));
    QFont title("comic sans", 25, QFont::Bold);
    Ttime->setFont(title);
    Ttime->setPos(x_pos/5 + 25, y_pos - 750);
    game->scene->addItem(Ttime);

    // adds a label showing the user best time
    //QGraphicsTextItem *Tbest = new QGraphicsTextItem(QString("Best time: \t\t" + best.showTheBest()));
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
    qDebug() << "manageStatistic";

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
