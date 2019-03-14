#ifndef STATISTIC_H
#define STATISTIC_H

#include <QString>
#include <QGraphicsTextItem>
#include <QObject>
#include <QDebug>

class statistic : public QObject {
    Q_OBJECT

    // private attributes
    static int totalTimeHours;
    static int totalTimeMinutes;
    static int totalTimeSeconds;
    static int correct;
    static int wrong;
    int settings;

    // private methods


public:
    // constructors
    statistic();

    // public methods
    QString read(int valueA, int valueB);
    void write(int valueA, int valueB );
    void showstatic();
    void ResetStatisticVariable();
    void manageStatistic();

    // getters
    static int getTotalTimeHours()                      { return totalTimeHours; }
    static int getTotalTimeMinutes()                    { return totalTimeMinutes; }
    static int getTotalTimeSeconds()                    { return totalTimeSeconds; }

    static int getCorrect()                             { return correct; }
    static int getWrong()                               { return wrong; }

    int getSettings()                                   { return settings; }

    // setters
    static void setTotalTimeHoursAdd(const int value)   { totalTimeHours = value; }
    static void setTotalTimeMinutesAdd(const int value) { totalTimeMinutes = value; }
    static void setTotalTimeSecondsAdd(const int value) { totalTimeSeconds = value; }

    static void setCorrect(const int value)             { correct += value;}
    static void setWrong(const int value)               { wrong += value; }

    static void setCorrectReset()                       { correct = 0;}
    static void setWrongReset()                         { wrong = 0; }

    void setSettings(const int value)                   { settings = value; }

};

#endif // STATISTIC_H
