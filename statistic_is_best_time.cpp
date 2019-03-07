#include "statistic_is_best_time.h"

#include <QDebug>

statistic_Is_Best_Time::statistic_Is_Best_Time(){

}

QString statistic_Is_Best_Time::SetIcon(QString ActualTime){

    statisticBestTime *BestTIme = new statisticBestTime();
    BestTIme->read(6, 1);
    QString Best = BestTIme->showTheBest();
    int count = 0;


    count += ActualTime.mid(0,2).toInt() * 3600000;
    count += ActualTime.mid(4,2).toInt() * 60000;
    count += ActualTime.mid(8,2).toInt() * 1000;
    count += ActualTime.mid(12,3).toInt();
    qDebug() << "count suma: " << count;


    int sum = 0;
    qDebug() << "sum start: " << sum;

    sum += Best.mid(0,2).toInt() * 3600000;
    qDebug() << "sum h: " << sum;

    sum += Best.mid(4,2).toInt() * 60000;
    qDebug() << "sum m: " << sum;

    sum += Best.mid(8,2).toInt() * 1000;
    qDebug() << "sum s: " << sum;

    sum += Best.mid(12,3).toInt();
    qDebug() << "sum ms: " << sum;

    qDebug() << "sum suma: " << sum;


    if(ActualTime.toInt() < Best.toInt()){
        qDebug() << "Actual time jest lepszy!";
    }
    else {
        qDebug() << "Nie pobi?e? rekordu!";
    }
    qDebug() << "Actual time: " << ActualTime << " BestTime: " << Best;
    qDebug() << "Actual time: " << ActualTime.toInt() << " BestTime: " << Best.toInt();
//    int WhoIsBest;
//    switch (WhoIsBest) {
//        case 1:
//        ;

//    }
    return "ola";

}
