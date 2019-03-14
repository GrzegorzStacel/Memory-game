#include "graphic_options.h"
#include <QDebug>

Graphic_options::Graphic_options(){

}

QString Graphic_options::setImageOptions(int number){

    switch (number) {

        case 1: return ":/others/images/others/options/Options.png";
        case 2: return ":/others/images/others/options/difficultLevel.png";
        case 3: return ":/others/images/others/options/buttonEasy.png";
        case 4: return ":/others/images/others/options/buttonMedium.png";
        case 5: return ":/others/images/others/options/buttonHard.png";
        case 6: return ":/others/images/others/options/buttonHardcore.png";

        default: qDebug() << "We have a problem in method Cards::setImageOptions";
            return nullptr;
    }
}
