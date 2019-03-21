#ifndef IS_BEST_TIME_H
#define IS_BEST_TIME_H

#include "statistic.h"
#include "statisticbesttime.h"

#include <QString>
#include <QGraphicsPixmapItem>

#include <QPointer>

class statistic_Is_Best_Time : public statistic, public QGraphicsPixmapItem {

public:
    // Constructors
    statistic_Is_Best_Time();

    // Methods
    QString Set_Icon_Time();
    QString Set_Colour_Of_Text();

private:
    //Attributes
    int value;
};

#endif // IS_BEST_TIME_H
