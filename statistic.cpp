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

int statistic::totalWrong;

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
        case 2: out << getTotalWrong();                break;
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
    QGraphicsTextItem *Tbest = new QGraphicsTextItem(QString("Best time: \t\t" + best.showTheBest()));
    Tbest->setFont(title);
    Tbest->setPos(x_pos/5 + 25, y_pos - 675);
    game->scene->addItem(Tbest);

    // adds a label showing value of correct answers from the best time
    best.showTheBestAnswers();
    QGraphicsTextItem *TbestCorrect = new QGraphicsTextItem(QString("Correct: " + best.getBestStatToSaveCorrect()));
    QFont title2("comic sans", 15, QFont::Bold);
    TbestCorrect->setFont(title2);
    TbestCorrect->setDefaultTextColor(Qt::darkGreen);
    TbestCorrect->setPos(x_pos/2 + 225, y_pos - 660);
    game->scene->addItem(TbestCorrect);

    // adds a label showing value of wrong answers from the best time
    QGraphicsTextItem *TbestWrong = new QGraphicsTextItem(QString("Wrong: " + best.getBestStatToSaveWrong()));
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

    totalWrong = 0;

    correct = 0;
    wrong = 0;
}

void statistic::manageStatistic(QString statisticBestTimeCurrentDateAndGameTime){

    int append = 0; // TODO change to bool
    statisticBestTime besttime;


    if(getCorrect() != 0 || getWrong() != 0){

        timer *time = new timer();
        QString textFromFile = "", a = "";

        for(int i = 1; i < 7; i++){

            // method write/read:
            // 1 ( totalCorrect.txt )
            // 2 ( totalWrong.txt )
            // 3 ( totalTimeSeconds.txt )
            // 4 ( totalTImeMinutes.txt )
            // 5 ( totalTimeHour.txt )
            // 6 ( totalTime.txt ) - current date and time + game time + correct and wrong

            textFromFile += read(i,0);

            int tmp = 0;
            append = 0;

            switch(i){

                case 1:
                    tmp = getCorrect();
                    //setTotalCorrect( textFromFile.toInt() + tmp ); // TODO Refactoring
                    break;

                case 2:
                    tmp = getWrong();
                    setTotalWrong( textFromFile.toInt() + tmp );
                    break;

                case 3:
                    tmp = time->getTimeStringSec().toInt();
                    tmp += textFromFile.toInt();

                    if( tmp >= 60 ){
                        setTotalTimeMinutesAdd(1);
                        tmp -= 60;
                    }

                    setTotalTimeSecondsAdd(tmp);
                    break;

                case 4:
                // getTimeStringMin - gets value from string
                // getTotalTImeMinutes - he has value (+1) when (see above (case 3)) tmp>=60
                    tmp = time->getTimeStringMin().toInt() + getTotalTimeMinutes();
                    setTotalTimeMinutesAdd(0);

                    tmp += textFromFile.toInt();

                    if( tmp >= 60 ){

                        setTotalTimeHoursAdd(1);
                        tmp -= 60;
                    }

                    setTotalTimeMinutesAdd(tmp);
                    break;

                case 5:
                    tmp = time->getTimeStringHour().toInt() + getTotalTimeHours();
                    setTotalTimeHoursAdd(0);

                    tmp += textFromFile.toInt();

                    setTotalTimeHoursAdd(tmp);
                    break;

                case 6:
                    textFromFile = statisticBestTimeCurrentDateAndGameTime + " ";
                            if( besttime.getCorrect() <= 9 )
                                textFromFile += "0" + QString::number( besttime.getCorrect() ) + " ";
                            else
                                textFromFile += QString::number( besttime.getCorrect() ) + " ";


                            if( besttime.getWrong() <= 9 )
                                textFromFile += "0" + QString::number( besttime.getWrong() ) + "\n";
                            else
                                textFromFile += QString::number( besttime.getWrong() ) + "\n";

                    besttime.setComplete(textFromFile);
                    append = 1;
                    break;

                default:
                    qDebug() << "Attention! in game_over::manageStatistic (switch) - does not have \"" << i << "\" value."; break;

            }

            write(i, append);
            textFromFile = "";
        }

    }

}

//                                     Attention!
//
// I used non-portable file addresses because the compiler makes strange problems with writing to a file when
// given files are added to resources.
// There were no problems with the reading only with the record.
