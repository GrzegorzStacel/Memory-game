#ifndef TIMER_H
#define TIMER_H

//#include <QTimer>
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

    QDateTime mStartTime;
    qint64 mSessionTime;
    game_over *gameover;


public:
    // public methods
    void stop();
    void start();

    void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }

    bool get_mRunning() { return mRunning; }
    QString get_time() { return timeString; }

    void set_mRunning( bool decision ) { mRunning = decision; }
    void set_timeString(QString foo) { timeString = foo; }

public slots:
    //void pause(void);
    //void start(void);

signals:
    void clicked();


protected:
    // protected methods
    void timerEvent(QTimerEvent *);
};

#endif // TIMER_H
