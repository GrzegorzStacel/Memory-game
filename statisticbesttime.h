#ifndef STATISTICBESTTIME_H
#define STATISTICBESTTIME_H

#include "statistic.h"
#include "who_is_best.h"

#include <QDebug>

class statisticBestTime : public statistic{

    // private attributes
    QString currentDateTime;
    QString timeLaps;
    static QString complete;
    static QList<int> list;
    static QList<int> tmp;
    static QList<QString> listTmp;
    static QList<QString> besttime;
    static int iterator;
    static QString bestStatToSave;
    static QString bestStatToSaveCorrect;
    static QString bestStatToSaveWrong;


    // private methods
    void bubbleSortModifiedForCorrectAnswer();
    QString prepareTextComplete(QString text);
    QString prepareTextHour(QString text);
    QString prepareTextMinute(QString text);
    QString prepareTextSecond(QString text);

public:
    // constructors
    statisticBestTime();

    // public methods
    void transformationSring(const QString line, int i);
    QString showTheBest();
    void showTheBestAnswers();
    QString showTHeBestWrong();
    void ResetStaticBestTimeVariable();
    void transformationWrong(QString value, int x);

    //QString mama2;

    // getters
    static QString getComplete()                             { return complete; }
    static QString getBestStatToSave()                       { return bestStatToSave; }
    static QString getBestStatToSaveCorrect()                { return bestStatToSaveCorrect; }
    static QString getBestStatToSaveWrong()                  { return bestStatToSaveWrong; }

    // setters
    void setComplete(const QString value)                    { complete = value; }
    static void setBestStatToSave(const QString value)       { bestStatToSave = value; }
    static void setBestStatToSaveCorrect(const QString value){ bestStatToSaveCorrect = value; }
    static void setBestStatToSaveWrong(const QString value)  { bestStatToSaveWrong = value; }
};

#endif // STATISTICBESTTIME_H
