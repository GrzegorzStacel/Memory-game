#ifndef STATISTIC_H
#define STATISTIC_H

#include <QString>
#include <QGraphicsTextItem>
#include <QObject>
#include <QDebug>

class statistic : public QObject {
    Q_OBJECT

    // private attributes
    static int correct;
    static int wrong;

    // private methods
    void hall_of_glory(int level, int X_Position, int Y_Position);

public:
    // constructors
    statistic();

    // public methods
    void showstatic();
    void ResetStatisticVariable();
    void manageStatistic();

    // getters
    static int getCorrect()                             { return correct; }
    static int getWrong()                               { return wrong; }

    // setters
    static void setCorrect(const int value)             { correct += value;}
    static void setWrong(const int value)               { wrong += value; }

    static void setCorrectReset()                       { correct = 0;}
    static void setWrongReset()                         { wrong = 0; }

};

#endif // STATISTIC_H
