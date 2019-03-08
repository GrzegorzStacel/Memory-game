#include "statistic_is_best_time.h"
#include "who_is_best.h"

#include <QDebug>

statistic_Is_Best_Time::statistic_Is_Best_Time(){

}

QString statistic_Is_Best_Time::SetIcon(){

    Who_Is_Best *who = new Who_Is_Best();

    int value = 0;
    value = who->score();

    switch (value) {
        case 1: return ":/others/images/others/up.png";
        case 2: return ":/others/images/others/point.png";
        case 3: return ":/others/images/others/down.png";

        default:
            qDebug() << "Attention! Error in statistic_Is_Best_Time::SetIcon"; break;
    }

    // Error - show the picture
    return ":/others/images/others/empty.png";
}
