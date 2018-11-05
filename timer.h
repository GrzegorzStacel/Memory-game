#ifndef TIMER_H
#define TIMER_H

#include <QTime>
#include <QObject>
#include "game_over.h"

#include <QFont>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include <QElapsedTimer>

class timer : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    // constructors
    explicit timer();


private:
    // private attributes
    static bool mRunning;
    static QString timeString;
    static QString timeStringSec;
    static QString timeStringMin;
    static QString timeStringHour;

    QDateTime mStartTime;
    qint64 mSessionTime;
    game_over *gameover;


public:
    // public attributes
    QString time;

    // public methods
    void stop();
    void start();
    QString showTotalTime();

    void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }

    bool get_mRunning() { return mRunning; }
    QString get_time() { return timeString; }



public slots:
    //void pause(void);
    //void start(void);

signals:
    void clicked();


protected:
    // protected methods
    void timerEvent(QTimerEvent *);


public:
    // getters
    static QString getTimeStringSec()                     { return timeStringSec; }
    static QString getTimeStringMin()                     { return timeStringMin; }
    static QString getTimeStringHour()                    { return timeStringHour; }

    // setters
    static void setTimeStringSecAdd(const QString value)  { timeStringSec += value; }
    static void setTimeStringMinAdd(const QString value)  { timeStringMin += value; }
    static void setTimeStringHourAdd(const QString value) { timeStringHour += value; }

    static void setTimeStringSecRegular(QString value)    { timeStringSec = value; }
    static void setTimeStringMinRegular(QString value)    { timeStringMin = value; }
    static void setTimeStringHourRegular(QString value)   { timeStringHour = value; }

    static void setTimeStringSecReset()                   { timeStringSec = ""; }
    static void setTimeStringMinReset()                   { timeStringMin = ""; }
    static void setTimeStringHourReset()                  { timeStringHour = ""; }

    void set_mRunning( bool decision )                    { mRunning = decision; }
    void set_timeString(QString value)                    { timeString = value; }
};




#endif // TIMER_H
