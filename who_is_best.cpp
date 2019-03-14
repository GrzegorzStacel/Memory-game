#include "who_is_best.h"
#include "timer.h"
#include "database.h"

#include <QDebug>

//int Who_Is_Best::Best_Correct;

Who_Is_Best::Who_Is_Best(){

}

int Who_Is_Best::score(){
    return Comparison();
}


int Who_Is_Best::Comparison(){

    Receive_Value();

    DataBase db;
    int Actual_Correct = db.select("SELECT correct FROM statistic_db ORDER BY id DESC LIMIT 1;)", 0).toInt();
    int Best_Correct = db.select("SELECT b_correct FROM user_settings WHERE id = 1", 0).toInt();

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

    DataBase db;

    QString Actual = db.select("SELECT t_time, id FROM statistic_db ORDER BY id DESC LIMIT 1;)", 0);

    count_ActualTime = 0;
    count_ActualTime += Actual.mid(0,2).toInt() * 3600000;
    count_ActualTime += Actual.mid(3,2).toInt() * 60000;
    count_ActualTime += Actual.mid(6,2).toInt() * 1000;
    qDebug() << "count actual : " << count_ActualTime;


    QString Best = db.select("SELECT b_time FROM user_settings WHERE id = 1", 0);

    count_BestTime = 0;
    count_BestTime += Best.mid(0,2).toInt() * 3600000;
    count_BestTime += Best.mid(3,2).toInt() * 60000;
    count_BestTime += Best.mid(6,2).toInt() * 1000;
    qDebug() << "count best : " << count_BestTime;

}
