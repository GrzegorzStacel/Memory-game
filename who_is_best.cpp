#include "who_is_best.h"
#include "timer.h"

#include <QDebug>

int Who_Is_Best::Best_Correct;

Who_Is_Best::Who_Is_Best(){

}

int Who_Is_Best::score(){
    return Comparison();
}

void Who_Is_Best::set_Best_Correct(int corr){
    // Receive the value of correct answers from the best time
    Best_Correct = corr;

}

int Who_Is_Best::Comparison(){

    Receive_Value();

    statistic *stat = new statistic();
    int Actual_Correct = stat->getCorrect();

    //Numbers are the text version used in the summary result when the user ends the game
    // Better time
    if( count_ActualTime < count_BestTime && Actual_Correct > Best_Correct )
        return 1;
    else if( count_ActualTime < count_BestTime && Actual_Correct == Best_Correct )
        return 2;
    else if( count_ActualTime < count_BestTime && Actual_Correct < Best_Correct )
        return 3;
    // At the same time
    else if( count_ActualTime == count_BestTime && Actual_Correct > Best_Correct)
        return 4;
    else if( count_ActualTime == count_BestTime && Actual_Correct == Best_Correct)
        return 5;
    else if( count_ActualTime == count_BestTime && Actual_Correct < Best_Correct)
        return 6;
    // Worse time
    else if( count_ActualTime > count_BestTime && Actual_Correct > Best_Correct )
        return 7;
    else if( count_ActualTime > count_BestTime && Actual_Correct == Best_Correct)
        return 8;
    else if( count_ActualTime > count_BestTime && Actual_Correct < Best_Correct)
        return 9;

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


    statisticBestTime *BestTIme = new statisticBestTime();
    BestTIme->read(6, 1);
    QString Best = BestTIme->showTheBest();

    count_BestTime = 0;
    count_BestTime += Best.mid(0,2).toInt() * 3600000;
    count_BestTime += Best.mid(4,2).toInt() * 60000;
    count_BestTime += Best.mid(8,2).toInt() * 1000;
    count_BestTime += Best.mid(12,3).toInt();

}
