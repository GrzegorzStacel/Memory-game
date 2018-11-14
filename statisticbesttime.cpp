#include "statisticbesttime.h"


QString statisticBestTime::complete;
QString statisticBestTime::bestStatToSave;
QString statisticBestTime::bestStatToSaveCorrect;
QString statisticBestTime::bestStatToSaveWrong;
QString statisticBestTime::StringTmp;
int statisticBestTime::iterator;
QList<long int> statisticBestTime::list;
QList<long int> statisticBestTime::listTmp;
QList<QString> statisticBestTime::besttime;



statisticBestTime::statisticBestTime(){
    iterator = 0;

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

    for( int i = 0; i <= iterator; ++i ){
        if(listTmp[i] == list[0]){

            setBestStatToSave(besttime[i]);
            write(7,0);

            return prepareTextComplete(besttime[i]);

        }
    }

    qDebug() << "Error in method staticBestTime::showTheBest";
    return "Error";
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


void statisticBestTime::showTheBestCorrect(){
    qDebug() << "value: " << getBestStatToSave();

    setBestStatToSaveCorrect(QString::number(getBestStatToSave().mid(38, 2).toInt()));

    setBestStatToSaveWrong(QString::number(getBestStatToSave().mid(41, 2).toInt()));

}

void statisticBestTime::transformationCorrect(QString value, int x){

//    if(x == 0){
//        setBestStatToSave(value);
//    }
//    else if(x == 1)
//       setBestStatToSaveCorrect(value);

//    else if(x == 2)
//       setBestStatToSaveWrong(value);

//    qDebug() << "--------------------------------";
//    qDebug() << "save: " << getBestStatToSave();
//    qDebug() << "correct: " << getBestStatToSaveCorrect();
//    qDebug() << "wrong: " << getBestStatToSaveWrong();
//    qDebug() << "--------------------------------";

}


void statisticBestTime::ResetStaticBestTimeVariable(){

    list.clear();
    listTmp.clear();
    besttime.clear();
    iterator = 0;
}
