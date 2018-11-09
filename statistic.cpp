#include "statistic.h"
#include "game.h"
#include "timer.h"

#include "game_over.h"
#include "statisticbesttime.h"

#include <QFile>
#include <QDebug>
#include <QTextStream>

extern Game *game;

int statistic::totalTimeHours;
int statistic::totalTimeMinutes;
int statistic::totalTimeSeconds;

int statistic::totalCorrect;
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
        case 1: out << getTotalCorrect();              break;
        case 2: out << getTotalWrong();                break;
        case 3: out << getTotalTimeSeconds();          break;
        case 4: out << getTotalTimeMinutes();          break;
        case 5: out << getTotalTimeHours();            break;
        case 6: out << best.getComplete() + "\n";      break;

        default:
            qDebug() << "Attention! in statistic::write 2- does not have \"" << valueA << "\" value."; break;
    }

    file.flush();
    file.close();
}


void statistic::showstatic(){

    timer *time = new timer();
    statisticBestTime best;
    game_over *over = new game_over();

    QString tmp = time->showTotalTime();

    read(6,1);

    double x_pos = game->scene->width();
    double y_pos = game->scene->height();

    over->drawPanel(x_pos/5, y_pos/5, x_pos/2 + 200, y_pos/2 + 50, Qt::white, 0.75);

    // adds a label showing all the time spent memorizing cards
    QGraphicsTextItem *Ttime = new QGraphicsTextItem(QString("Total time: \t" + tmp));
    QFont title("comic sans", 25, QFont::Bold);
    Ttime->setFont(title);
    Ttime->setPos(x_pos/5 + 25, y_pos - 650);
    game->scene->addItem(Ttime);

    // adds a label showing the user best time
    QGraphicsTextItem *Tbest = new QGraphicsTextItem(QString("Best time: \t\t" + best.showTheBest()));
    Tbest->setFont(title);
    Tbest->setPos(x_pos/5 + 25, y_pos - 550);
    game->scene->addItem(Tbest);

    // adds a label showing all correct answers
    setTotalCorrect(read(1,0).toInt());
    QGraphicsTextItem *Tcorrect = new QGraphicsTextItem(QString("Total correct: \t" + QString::number(totalCorrect)));
    Tcorrect->setDefaultTextColor(Qt::darkGreen);
    Tcorrect->setFont(title);
    Tcorrect->setPos(x_pos/5 + 25, y_pos - 450);
    game->scene->addItem(Tcorrect);

    // adds a label showing all wrong answers
    setTotalWrong(read(2,0).toInt());
    QGraphicsTextItem *Twrong = new QGraphicsTextItem(QString("Total wrong: \t" + QString::number(totalWrong)));
    Twrong->setDefaultTextColor(Qt::darkRed);
    Twrong->setFont(title);
    Twrong->setPos(x_pos/5 + 25, y_pos - 350);
    game->scene->addItem(Twrong);

    // create the back button
    MainButtons *backbutton = new MainButtons(QString("Back"));
    backbutton->setPos(x_pos/2 + 50, y_pos - 300);
    connect(backbutton, SIGNAL(clicked()), game, SLOT(displayMainMenu()));
    game->scene->addItem(backbutton);
}


void statistic::ResetStatisticVariable(){

    totalTimeHours = 0;
    totalTimeMinutes = 0;
    totalTimeSeconds = 0;

    totalCorrect = 0;
    totalWrong = 0;
}

void statistic::manageStatistic(){

    if(getCorrect() != 0 || getWrong() != 0){

        timer *time = new timer();
        QString textFromFile = "";

        for(int i = 1; i < 6; i++){

            // method write/read:
            // 1 ( totalCorrect.txt )
            // 2 ( totalWrong.txt )
            // 3 ( totalTimeSeconds.txt )
            // 4 ( totalTImeMinutes.txt )
            // 5 ( totalTimeHour.txt

            textFromFile += read(i,0);

            int tmp = 0;

            switch(i){

                case 1:
                    tmp = getCorrect();
                    setTotalCorrect( textFromFile.toInt() + tmp );
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
                    tmp = time->getTimeStringMin().toInt() + getTotalTimeMinutes();
                    setTotalTimeMinutesReset();

                    tmp += textFromFile.toInt();

                    if( tmp >= 60 ){

                        setTotalTimeHoursAdd(1);
                        tmp -= 60;
                    }

                    setTotalTimeMinutesAdd(tmp);
                    break;

                case 5:
                    tmp = time->getTimeStringHour().toInt() + getTotalTimeHours();
                    qDebug() << "time->getTimeStringHour().toInt(): " << time->getTimeStringHour().toInt();
                    qDebug() << "stat->getTotalTimeHours(): " << getTotalTimeHours();
                    setTotalTimeHoursReset();

                    tmp += textFromFile.toInt();

                    setTotalTimeHoursAdd(tmp);
                    break;

                default:
                    qDebug() << "Attention! in game_over::manageStatistic (switch) - does not have \"" << i << "\" value."; break;

            }

            write(i, 0);
            textFromFile = "";
        }

        // reset statistic value
        setCorrectReset();
        setWrongReset();
    }

}

//                                     Attention!
//
// I used non-portable file addresses because the compiler makes strange problems with writing to a file when
// given files are added to resources.
// There were no problems with the reading only with the record.
