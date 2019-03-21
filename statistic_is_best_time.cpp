#include "statistic_is_best_time.h"
#include "who_is_best.h"

#include <QDebug>

statistic_Is_Best_Time::statistic_Is_Best_Time(){

}

QString statistic_Is_Best_Time::Set_Icon_Time(){

    Who_Is_Best who;

    value = who.score();

    switch (value) {
        //Better time
        case 1: return "\t\t\t\tNew Rcord!\nYou have a better time and have given more correct answers!";
        case 2: return "\t\t\t\tNew Rcord!\nYou have a better time and gave the same correct answers!";
        case 3: return "\tYou have a better time but gave less correct answers";
        //At the same time
        case 4: return "\tYou have the same time but have more correct answers";
        case 5: return "\tYou have the same time and gave the same correct answers";
        case 6: return "\tYou have the same time but gave less correct answers";
        //Worse time
        case 7: return "You have a worse time but have given more correct answers";
        case 8: return "You have a worse time but gave the same correct answers";
        case 9: return "You have a worse time and gave less correct answers";

        default:
            qDebug() << "Attention! Error in statistic_Is_Best_Time::SetIcon"; break;
    }

    // Error - show the picture
    return ":/others/images/others/empty.png";
}

QString statistic_Is_Best_Time::Set_Colour_Of_Text(){

    if( value == 1 || value == 2 || value == 4 )
        return "green";
    else if( value == 3 || value == 4 || value == 5 || value == 6)
        return "black";
    else
        return "red";

}
