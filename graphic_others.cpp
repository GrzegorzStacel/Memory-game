#include "graphic_others.h"
#include "drawcards.h"

#include <QDebug>

Graphic_others::Graphic_others()
{

}

QString Graphic_others::setImageOthers(int number){

    switch (number) {
        case 1: return ":/others/images/others/buttonBack.png";
        case 2: return ":/others/images/others/actuallyLvl.png";
        case 3: return ":/others/images/cards/backVeryHard.png";
        case 4: return ":/others/images/cards/activeVeryHard.png";
        case 5: return ":/others/images/others/informationFrame.png";
        case 6: return ":/others/images/others/statisticsIconS.png";
        case 7: return ":/others/images/others/correct.png";
        case 8: return ":/others/images/others/wrong.png";
        case 9: return ":/others/images/others/correctVeryHard.png";
        case 10: return ":/others/images/others/wrongVeryHard.png";
        case 11: return ":/others/images/others/summaryGameOver.png";


        default: qDebug() << "We have a problem in method Cards::setImageOthers";
            return nullptr;
    }

}

void Graphic_others::handleClickWrong(){

    DrawCards *draw = new DrawCards();
    emit buttonClickedWrong(draw->getVariableForChooseImage());
}

void Graphic_others::handleClickCorrect(){

    DrawCards *draw = new DrawCards();
    emit buttonClickedCorrect(draw->getVariableForChooseImage());
}
