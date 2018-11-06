#include "statistic.h"
#include "game.h"
#include "timer.h"
#include "game_over.h"

#include <QFile>
#include <QDebug>
#include <QTextStream>

extern Game *game;

QString statistic::totalTime;
int statistic::totalTimeHours;
int statistic::totalTimeMinutes;
int statistic::totalTimeSeconds;

int statistic::totalCorrect;
int statistic::totalWrong;

int statistic::correct;
int statistic::wrong;
int statistic::bestTime;


statistic::statistic(){

}

QString statistic::read(int value){

    QFile file;

    // I added a description at the bottom of the page about the address of the file
    switch (value) {

        case 1: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalCorrect.txt"); break;
        case 2: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalWrong.txt"); break;
        case 3: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalTimeSeconds.txt"); break;
        case 4: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalTimeMinutes.txt"); break;
        case 5: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalTimeHours.txt"); break;

        default:
            qDebug() << "Attention! in statistic::read - does not have \"" << value << "\" value."; break;
    }

    // Protecion
    if(!file.exists()){
        qDebug() << file.fileName() << " does not exists";
    }

    QString line;

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){

             line = file.readAll();

    } else {

        qDebug() << "In method statistic::read could not open file for read.";
        return nullptr;
    }

    file.close();
    return line;
}

void statistic::write(int value){

    QFile file;


    // I added a description at the bottom of the page about the address of the file
    switch (value) {

        case 1: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalCorrect.txt"); break;
        case 2: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalWrong.txt"); break;
        case 3: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalTimeSeconds.txt"); break;
        case 4: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalTimeMinutes.txt"); break;
        case 5: file.setFileName("F:/Programy C++/Qt/Memory_Cards/files/totalTimeHours.txt"); break;

        default:
            qDebug() << "Attention! in statistic::write 1 - does not have \"" << value << "\" value."; break;
    }

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){

        qDebug() << "In method statistic::write could not open file for write.";
        return;
    }

    QTextStream out(&file);

    switch (value) {
        case 1: out << getTotalCorrect();       break;
        case 2: out << getTotalWrong();         break;
        case 3: out << getTotalTimeSeconds();   break;
        case 4: out << getTotalTimeMinutes();   break;
        case 5: out << getTotalTimeHours();     break;

        default:
            qDebug() << "Attention! in statistic::write 2- does not have \"" << value << "\" value."; break;
    }

    file.flush();
    file.close();
}


void statistic::showstatic(){
    timer *time = new timer();
    game_over *over = new game_over();
    QString tmp = time->showTotalTime();
    double x_pos = game->scene->width();
    double y_pos = game->scene->height();

    over->drawPanel(x_pos/5, y_pos/5, x_pos/2 + 100, y_pos/2 + 50, Qt::white, 0.75);

    // adds a label showing all the time spent memorizing cards
    QGraphicsTextItem *Ttime = new QGraphicsTextItem(QString("Total time: " + tmp));
    QFont title("comic sans", 25, QFont::Bold);
    Ttime->setFont(title);
    Ttime->setPos(x_pos/5 + 25, y_pos - 650);
    game->scene->addItem(Ttime);

    // adds a label showing all correct answers
    setTotalCorrect(read(1).toInt());
    QGraphicsTextItem *Tcorrect = new QGraphicsTextItem(QString("Total correct: \t" + QString::number(totalCorrect)));
    Tcorrect->setDefaultTextColor(Qt::darkGreen);
    Tcorrect->setFont(title);
    Tcorrect->setPos(x_pos/5 + 25, y_pos - 550);
    game->scene->addItem(Tcorrect);

    // adds a label showing all wrong answers
    setTotalWrong(read(2).toInt());
    QGraphicsTextItem *Twrong = new QGraphicsTextItem(QString("Total wrong: \t" + QString::number(totalWrong)));
    Twrong->setDefaultTextColor(Qt::darkRed);
    Twrong->setFont(title);
    Twrong->setPos(x_pos/5 + 25, y_pos - 450);
    game->scene->addItem(Twrong);

    // create the back button
    MainButtons *backbutton = new MainButtons(QString("Back"));
    backbutton->setPos(x_pos/2 + 50, y_pos - 300);
    connect(backbutton, SIGNAL(clicked()), game, SLOT(displayMainMenu()));
    game->scene->addItem(backbutton);
}




//                                     Attention!
//
// I used non-portable file addresses because the compiler makes strange problems with writing to a file when
// given files are added to resources.
// There were no problems with the reading only with the record.
