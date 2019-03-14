#include "statisticbesttime.h"

#include <algorithm>

QString statisticBestTime::complete;
QString statisticBestTime::bestStatToSave;
QString statisticBestTime::bestStatToSaveCorrect;
QString statisticBestTime::bestStatToSaveWrong;
int statisticBestTime::iterator;
QList<int> statisticBestTime::list;
QList<int> statisticBestTime::tmp;
QList<QString> statisticBestTime::listTmp;
QList<QString> statisticBestTime::besttime;



statisticBestTime::statisticBestTime(){
    iterator = 0;

}

void statisticBestTime::transformationSring(QString line, int i){

    besttime.append(line);
    iterator = i;
}

//QString statisticBestTime::showTheBest(){

//    if( besttime.isEmpty())
//        return "0h : 0m : 0s : 000ms";

//    int iter = 0;
//    // sort by the correct answer
//    bubbleSortModifiedForCorrectAnswer();

//    // searching for the number of repetitions of correct answers
//    for( int i = 0; i <= iterator; ++i )
//        if( besttime[i].mid(38,2).toInt() == besttime[iterator].mid(38,2).toInt() ){

//            listTmp.append(besttime[i]);

//            // extracts the time from the record with the highest number of correct
//            // answers and recalculates to further compare the fastest time
//            list.append(( besttime[i].mid(20,2).toInt() * 100000 ) +
//                        ( besttime[i].mid(24,2).toInt() * 10000 ) +
//                        ( besttime[i].mid(28,2).toInt() * 1000 ) +
//                          besttime[i].mid(32,3).toInt() );
//            ++iter;
//        }

//    // record the order before sorting
//    tmp = list;

//    // if there are more than one of the same correct answers, sort by time
//    std::sort(list.begin(), list.end());

//    // Compare the entire spare container with the best time by finding the container number with the whole record
//    for( int i = 0; i <= iter; ++i ){
//        if(tmp[i] == list[0]){

//            // setter abused in showTheBestCorrect method ( setBestStatToSaveCorrect() )
//            setBestStatToSave(listTmp[i]);
//            //write(7,0);
//            iter = 0;

//            return prepareTextComplete(listTmp[i]);
//        }
//    }

//    iter = 0;
//    qDebug() << "Error in method staticBestTime::showTheBest";
//    return "Error";
//}


//void statisticBestTime::bubbleSortModifiedForCorrectAnswer(){

//    QString x = "";

//    for(int j = 0; j < iterator; j++)
//        for(int i = 0; i < iterator; i++)
//          if(besttime[i].mid(38,2) > besttime[i + 1].mid(38,2)) {

//             x = besttime[i];
//             besttime[i] = besttime[i + 1];
//             besttime[i + 1] = x;
//          }
//}

//QString statisticBestTime::prepareTextComplete(QString text){

////    return prepareTextHour(text) + "h "
////           + prepareTextMinute(text) + "m "
////           + prepareTextSecond(text) + "s "
////           + text.mid(32,3) + "ms";

//    return text.mid(20,2) + "h "
//           + text.mid(24,2) + "m "
//           + text.mid(28,2) + "s "
//           + text.mid(32,3) + "ms";
//}

//QString statisticBestTime::prepareTextHour(QString text){

////    if(text.mid(20,2).toInt() == 0)
////        return "00";

////    else if(text.mid(20,1).toInt() != 0)
////        return text.mid(20,2);

////    else if(text.mid(20,1).toInt() == 0)
////        return text.mid(20,2);

////    qDebug() << "We have problem in method statisticBestTime::prepareTextHour";

////    return "Error";
//    return text.mid(20,2);
//}

//QString statisticBestTime::prepareTextMinute(QString text){

////    if(text.mid(24,2).toInt() == 0)
////        return "00";

////    else if(text.mid(24,1).toInt() != 0)
////        return text.mid(24,2);

////    else if(text.mid(24,1).toInt() == 0)
////        return text.mid(24,2);

////    qDebug() << "We have problem in method statisticBestTime::prepareTextMinute";

////    return "Error";

//    return text.mid(24,2);
//}

//QString statisticBestTime::prepareTextSecond(QString text){

////    if(text.mid(28,2).toInt() == 0)
////        return "00";

////    else if(text.mid(28,1).toInt() != 0)
////        return text.mid(28,2);

////    else if(text.mid(28,1).toInt() == 0)
////        return text.mid(29,1);

////    qDebug() << "We have problem in method statisticBestTime::prepareTextSecond";


////    return "Error";

//    return text.mid(28,2);
//}





void statisticBestTime::ResetStaticBestTimeVariable(){

    list.clear();
    listTmp.clear();
    besttime.clear();
    tmp.clear();
    iterator = 0;
}
