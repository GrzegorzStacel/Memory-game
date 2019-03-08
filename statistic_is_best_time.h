#ifndef IS_BEST_TIME_H
#define IS_BEST_TIME_H

#include "statistic.h"
#include "statisticbesttime.h"

#include <QString>
#include <QGraphicsPixmapItem>

class statistic_Is_Best_Time : public statistic, public QGraphicsPixmapItem {

public:
    // Constructors
    statistic_Is_Best_Time();

    // Methods
    QString SetIcon();
};

#endif // IS_BEST_TIME_H
