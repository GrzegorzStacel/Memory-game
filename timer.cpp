#include "timer.h"
#include "game.h"
#include "cards.h"
#include "statistic.h"

#include "drawcards.h"
#include "database.h"

#include <QThread>
#include <QDebug>

extern Game *game;

bool timer::mRunning;
QString timer::timeString;
QString timer::timeStringHour;
QString timer::timeStringMin;
QString timer::timeStringSec;

timer::timer(){

}

void timer::start(){
    DrawCards *draw = new DrawCards();
    draw->isActive = true;


    // initialize counting time
    startTimer(0);
    mStartTime = QDateTime::currentDateTime();
    mRunning = true;


            // CODE TO IMPLEMENT THE PAUSE TIME OPTION - FOR NOW IS WITHHELD
// BECAUSE THIS CODE HAS A FEW BUGS AND I DON'T HAVE ANY IDEA HOW TO SOLVE THIS - THE LIST OF ERRORS IS AT THE END OF THE SITE
//----------------------------------------------------------------------------------------------------------------------------
//    for (int i = 0, n = game->scene->items().size(); i < n; i++){
//        game->scene->items()[i]->setEnabled(true);
//    }

//    timer * time = new timer();
//    time->setPixmap(QString(":/others/images/others/pause.png"));
//    time->setPos(1150,50);
//    connect(time, SIGNAL(clicked()), time, SLOT(pause()));
//    game->scene->addItem(time);
//----------------------------------------------------------------------------------------------------------------------------
}


void timer::stop(){

    mRunning = false;
}

void timer::timerEvent(QTimerEvent *){

    if(mRunning){

        mSessionTime = mStartTime.msecsTo(QDateTime::currentDateTime());

        long long int h = mSessionTime / 1000 / 60 / 60;
        long long int m = (mSessionTime / 1000 / 60) - (h * 60);
        long long int s = (mSessionTime / 1000) - ((m + (h * 60))* 60);
        long long int ms = mSessionTime - (s + ((m + (h * 60))* 60)) * 1000;
        timeString = QString("%1h %2m %3s %4ms")
                            .arg(h,  2, 10, QChar('0'))
                            .arg(m,  2, 10, QChar('0'))
                            .arg(s,  2, 10, QChar('0'))
                            .arg(ms, 3, 10, QChar('0'));

        timeStringHour = QString("%1").arg(h, 2, 10, QChar('0'));
        timeStringMin = QString("%1").arg(m, 2, 10, QChar('0'));
        timeStringSec = QString("%1").arg(s, 2, 10, QChar('0'));        
     }
}

QString timer::showTotalTime(){
    QString value = 0;

    {
        DataBase db;
//        value = db.select("SELECT SUM(t_time) FROM statistic_db", 0);
        value = db.select("SELECT  SEC_TO_TIME( SUM( TIME_TO_SEC( t_time ) ) ) FROM statistic_db;", 0);
    }

    return value;

//    statistic *stat = new statistic();

//    setTimeStringSecRegular(stat->read(3,0));
//    setTimeStringMinRegular(stat->read(4,0));
//    setTimeStringHourRegular(stat->read(5,0));

//    return time = timeStringHour + "h : " + timeStringMin + "m : " + timeStringSec + "s";
}

void timer::ResetTimerVariable(){

    setMRunning(false);
    setTimeString("");

    timeStringSec = "";
    timeStringMin = "";
    timeStringHour = "";
}

            // CODE TO IMPLEMENT THE PAUSE TIME OPTION - FOR NOW IS WITHHELD
// BECAUSE THIS CODE HAS A FEW BUGS AND I DON'T HAVE ANY IDEA HOW TO SOLVE THIS - THE LIST OF ERRORS IS AT THE END OF THE SITE
//----------------------------------------------------------------------------------------------------------------------------
//void timer::pause(){
//    qDebug() << "pause - outside";

//    DrawCards *draw = new DrawCards();

//    if( draw->isActive ){
//        qDebug() << "pause - inside";

//        for (int i = 0, n = game->scene->items().size(); i < n; i++){
//            game->scene->items()[i]->setEnabled(false);
//        }
        
//        // create the play (time) button
//        timer * time = new timer();
//        time->setPixmap(QString(":/others/images/others/play.png"));
//        time->setPos(1150, 50);
//        connect(time, SIGNAL(clicked()), time, SLOT(resume()));
//        game->scene->addItem(time);


//        timerEvent(new QTimerEvent(0));
//        mTotalTime += mSessionTime;
//        mRunning = false;

//    }
//}


//----------------------------------------------------------------------------------------------------------------------------

// BUGS:
// * AFTER PAUSE, VARIABLE THAT PASSES TIME CONTAINS DAILY VALUES
// * WHEN I IMPLEMENT QGRAPHICSTEXTITEM TO DISPLAY THE TIME ON THE GAME->SCENE, ILLUSTRATION TIME DISAPPOINTED AT YOURSELF
