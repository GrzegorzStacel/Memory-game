#ifndef STATISTIC_H
#define STATISTIC_H

#include <QString>
#include <QGraphicsTextItem>
#include <QObject>


class statistic : public QObject {
    Q_OBJECT

    // private attributes
    static QString totalTime;
    static int totalTimeHours;
    static int totalTimeMinutes;
    static int totalTimeSeconds;
    static int correct;
    static int wrong;
    static int totalCorrect;
    static int totalWrong;
    static int bestTime;

public:
    // constructors
    statistic();

    // public methods
    QString read(int value);
    void write(int value);
    void showstatic();

    // getters
    static QString getTotalTIme()                       { return totalTime; }
    static int getTotalTimeHours()                      { return totalTimeHours; }
    static int getTotalTimeMinutes()                    { return totalTimeMinutes; }
    static int getTotalTimeSeconds()                    { return totalTimeSeconds; }

    static int getTotalCorrect()                        { return totalCorrect; }
    static int getTotalWrong()                          { return totalWrong; }

    static int getCorrect()                             { return correct; }
    static int getWrong()                               { return wrong; }
    static int getBestTime()                            { return bestTime; }

    // setters
    static void setTotalTIme( QString value)            { totalTime += value; }
    static void setTotalTimeHoursAdd(int value)         { totalTimeHours += value; }
    static void setTotalTimeMinutesAdd(int value)       { totalTimeMinutes += value; }
    static void setTotalTimeSecondsAdd(int value)       { totalTimeSeconds += value; }

    static void setTotalTimeHoursReset()                { totalTimeHours = 0; }
    static void setTotalTimeMinutesReset()              { totalTimeMinutes = 0; }
    static void setTotalTimeSecondsReset()              { totalTimeSeconds = 0; }

    static void setTotalCorrect(int value)              { totalCorrect = value; }
    static void setTotalWrong(int value)                { totalWrong = value; }

    static void setTotalCorrectReset()                  { totalCorrect = 0; }
    static void setTotalWrongReset()                    { totalWrong = 0; }

    static void setCorrect(int value)                   { correct += value; }
    static void setWrong(int value)                     { wrong += value; }

    static void setCorrectReset()                       { correct = 0; }
    static void setWrongReset()                         { wrong = 0; }

    static void setBestTime(int value)                  { bestTime = value; }
};

#endif // STATISTIC_H
