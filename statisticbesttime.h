#ifndef STATISTICBESTTIME_H
#define STATISTICBESTTIME_H

#include "statistic.h"

#include <QDebug>

class statisticBestTime : public statistic{

    // private attributes
    QString currentDateTime;
    QString timeLaps;
    static QString complete;
    static QList<long int> list;
    //static int list[];
    static QList<long int> listTmp;
    static QList<QString> besttime;
    static int iterator;


    // private methods
    void bubbleSort();
    QString prepareTextComplete(QString text);
    QString prepareTextHour(QString text);
    QString prepareTextMinute(QString text);
    QString prepareTextSecond(QString text);

public:
    // constructors
    statisticBestTime();
    statisticBestTime(QString d, QString t);

    // public methods
    void transformationSring(const QString line, int i);
    QString showTheBest();
    void ResetStaticVariable();


    // getters
    static QString getComplete() { return complete; }

    // setters

};

#endif // STATISTICBESTTIME_H
