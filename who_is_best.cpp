#include "who_is_best.h"
#include "timer.h"

#include <QDebug>

Who_Is_Best::Who_Is_Best(){

}

int Who_Is_Best::score(){
    return Comparison();
}

int Who_Is_Best::Comparison(){

    Receive_Value();

    if( count_ActualTime < count_BestTime )
        return 1;
    else if( count_ActualTime == count_BestTime )
        return 2;
    else if( count_ActualTime > count_BestTime )
        return 3;

    // Error
    return 0;

}

void Who_Is_Best::Receive_Value(){

    timer *time = new timer();
    QString Actual = time->getTime();

    count_ActualTime = 0;
    count_ActualTime += Actual.mid(0,2).toInt() * 3600000;
    count_ActualTime += Actual.mid(4,2).toInt() * 60000;
    count_ActualTime += Actual.mid(8,2).toInt() * 1000;
    count_ActualTime += Actual.mid(12,3).toInt();
    qDebug() << "actual count: " << count_ActualTime;
    qDebug() << "actual time: " << Actual;

    statisticBestTime *BestTIme = new statisticBestTime();
    BestTIme->read(6, 1);
    QString Best = BestTIme->showTheBest();

    count_BestTime = 0;
    count_BestTime += Best.mid(0,2).toInt() * 3600000;
    count_BestTime += Best.mid(4,2).toInt() * 60000;
    count_BestTime += Best.mid(8,2).toInt() * 1000;
    count_BestTime += Best.mid(12,3).toInt();
    qDebug() << "best count: " << count_BestTime;
    qDebug() << "best time: " << Best;

    statistic *stat = new statistic();
    qDebug() << "correct : " << stat->getCorrect();
    qDebug() << "wrong : " << stat->getWrong();



}
