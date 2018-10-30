#ifndef STATISTIC_H
#define STATISTIC_H

#include <QString>

class statistic {

    // private attributes
    static QString totalTime;
    static int correct;
    static int wrong;
    static int totalCorrect;
    static int totalWrong;
    static int bestTime;

public:
    // constructors
    statistic();

    // public attributes


    // public methods
    void read(int value);
    void write(int value);

    // getters
    static QString getTotalTIme() { return totalTime; }
    static int getCorrect() { return correct; }
    static int getWrong() { return wrong; }
    static int getTotalCorrect() { return totalCorrect; }
    static int getTotalWrong() { return totalWrong; }
    static int getBestTime() { return bestTime; }

    // setters
    static void setTotalTIme( QString time) { totalTime = time; }
    static void setCorrect(int ok) { correct += ok; }
    static void setWrong(int notOk) { wrong += notOk; }
    static void setTotalCorrect(int tCorrect) { totalCorrect = tCorrect; }
    static void setTotalWrong(int tWrong) { totalWrong = tWrong; }
    static void setBestTime(int value) { bestTime = value; }
};

#endif // STATISTIC_H
