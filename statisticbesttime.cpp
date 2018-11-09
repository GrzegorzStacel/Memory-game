#include "statisticbesttime.h"


QString statisticBestTime::complete;
int statisticBestTime::iterator;
QList<long int> statisticBestTime::list;
//int statisticBestTime::list[100];
QList<long int> statisticBestTime::listTmp;
QList<QString> statisticBestTime::besttime;


statisticBestTime::statisticBestTime(){
    iterator = 0;

}

statisticBestTime::statisticBestTime(QString d, QString t) : currentDateTime(d), timeLaps(t) {
    statistic stat;

    complete = currentDateTime + " "
            + timeLaps + " "
            + QString::number(stat.getCorrect()) + " "
            + QString::number(stat.getTotalWrong());

    write(6, 1);

}

void statisticBestTime::transformationSring(QString line, int i){

    besttime.append(line);

    list.append(( line.mid(20,2).toInt() * 100000 ) +
                ( line.mid(24,2).toInt() * 10000 ) +
                ( line.mid(28,2).toInt() * 1000 ) +
                  line.mid(32,3).toInt() );

    listTmp = list;
    iterator = i;
}

QString statisticBestTime::showTheBest(){

    bubbleSort();

    for( int i = 0; i <= iterator; ++i )
        if(listTmp[i] == list[0]){

            return prepareTextComplete(besttime[i]);
        }

    return "Error, it's empty";
}

void statisticBestTime::bubbleSort(){

    int x=0;

    for(int j = 0; j < iterator; j++)
        for(int i = 0; i < iterator; i++)
          if(list[i] > list[i + 1]) {

            x = list[i];
            list[i] = list[i + 1];
            list[i + 1] = x;
          }
}

QString statisticBestTime::prepareTextComplete(QString text){

    return prepareTextHour(text) + "h : "
           + prepareTextMinute(text) + "m : "
           + prepareTextSecond(text) + "s : "
           + text.mid(32,3) + "ms";
}

QString statisticBestTime::prepareTextHour(QString text){

    if(text.mid(20,2).toInt() == 0)
        return "0";

    else if(text.mid(20,1).toInt() != 0)
        return text.mid(20,2);

    else if(text.mid(20,1).toInt() == 0)
        return text.mid(21,1);

    qDebug() << "We have problem in method statisticBestTime::prepareTextHour";

    return "Error";
}

QString statisticBestTime::prepareTextMinute(QString text){

    if(text.mid(24,2).toInt() == 0)
        return "0";

    else if(text.mid(24,1).toInt() != 0)
        return text.mid(24,2);

    else if(text.mid(24,1).toInt() == 0)
        return text.mid(25,1);

    qDebug() << "We have problem in method statisticBestTime::prepareTextMinute";

    return "Error";
}

QString statisticBestTime::prepareTextSecond(QString text){

    if(text.mid(28,2).toInt() == 0)
        return "0";

    else if(text.mid(28,1).toInt() != 0)
        return text.mid(28,2);

    else if(text.mid(28,1).toInt() == 0)
        return text.mid(29,1);

    qDebug() << "We have problem in method statisticBestTime::prepareTextSecond";

    return "Error";
}

void statisticBestTime::ResetStaticVariable(){

    list.clear();
    listTmp.clear();
    besttime.clear();
    iterator = 0;
}
