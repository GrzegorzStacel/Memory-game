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
    static QList<long int> listTmp;
    static QList<QString> besttime;
    static int iterator;
    static QString bestStatToSave;
    static QString bestStatToSaveCorrect;
    static QString bestStatToSaveWrong;
    static QString StringTmp;


    // private methods
    void bubbleSort();
    QString prepareTextComplete(QString text);
    QString prepareTextHour(QString text);
    QString prepareTextMinute(QString text);
    QString prepareTextSecond(QString text);

public:
    // constructors
    statisticBestTime();

    // public methods
    void transformationSring(const QString line, int i);
    QString showTheBest(int value);
    void showTheBestCorrect();
    QString showTHeBestWrong();
    void ResetStaticBestTimeVariable();
    void transformationCorrect(QString value, int x);
    void transformationWrong(QString value, int x);

    QString mama2;

    // getters
    static QString getComplete()                             { return complete; }
    static QString getBestStatToSave()                       { return bestStatToSave; }
    static QString getBestStatToSaveCorrect()                { return bestStatToSaveCorrect; }
    static QString getBestStatToSaveWrong()                  { return bestStatToSaveWrong; }
    static QString getStringTmp()                            { return StringTmp; }

    // setters
    void setComplete(const QString value)                    { complete = value; }
    static void setBestStatToSave(const QString value)       { bestStatToSave = value; }
    static void setBestStatToSaveCorrect(const QString value){ bestStatToSaveCorrect = value; }
    static void setBestStatToSaveWrong(const QString value)  { bestStatToSaveWrong = value; }
    static void setStringTmp(const QString &value)           { StringTmp = value; }
};

#endif // STATISTICBESTTIME_H
