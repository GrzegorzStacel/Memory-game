#include "cards.h"
#include "drawcards.h"

//#include <ctime>
//#include <cstdlib>
#include <QDebug>

Cards::Cards(){

}

Cards::Cards(bool isActive, bool lvl){

    if( lvl == true ){

        if( isActive == true )
            setPixmap(QPixmap(":/others/images/cards/active.png"));
        else
            setPixmap(QPixmap(":/others/images/cards/back.png"));

    } else if( lvl == false ){

        if( isActive == true )
            setPixmap(QPixmap(":/others/images/cards/activeVeryHard.png"));
        else
            setPixmap(QPixmap(":/others/images/cards/backVeryHard.png"));

    } else
        qDebug() << "Error in method Cards::setActive()";

}

QString Cards::setImageRegularNeutral(int number){

    switch (number+1) {
        // heart
        case 1: return ":/others/images/cards/easy, medium, hard/heart/neutral/2_serc_regular_neutral.png";
        case 2: return ":/others/images/cards/easy, medium, hard/heart/neutral/3_serc_regular_neutral.png";
        case 3: return ":/others/images/cards/easy, medium, hard/heart/neutral/4_serc_regular_neutral.png";
        case 4: return ":/others/images/cards/easy, medium, hard/heart/neutral/5_serc_regular_neutral.png";
        case 5: return ":/others/images/cards/easy, medium, hard/heart/neutral/6_serc_regular_neutral.png";
        case 6: return ":/others/images/cards/easy, medium, hard/heart/neutral/7_serc_regular_neutral.png";
        case 7: return ":/others/images/cards/easy, medium, hard/heart/neutral/8_serc_regular_neutral.png";
        case 8: return ":/others/images/cards/easy, medium, hard/heart/neutral/9_serc_regular_neutral.png";
        case 9: return ":/others/images/cards/easy, medium, hard/heart/neutral/10_serc_regular_neutral.png";
        case 10: return ":/others/images/cards/easy, medium, hard/heart/neutral/jopek_serc_regular_neutral.png";
        case 11: return ":/others/images/cards/easy, medium, hard/heart/neutral/dama_serc_regular_neutral.png";
        case 12: return ":/others/images/cards/easy, medium, hard/heart/neutral/krol_serc_regular_neutral.png";
        case 13: return ":/others/images/cards/easy, medium, hard/heart/neutral/as_serc_regular_neutral.png";
        // clover
        case 14: return ":/others/images/cards/easy, medium, hard/clover/neutral/2_clover_regular_neutral.png";
        case 15: return ":/others/images/cards/easy, medium, hard/clover/neutral/3_clover_regular_neutral.png";
        case 16: return ":/others/images/cards/easy, medium, hard/clover/neutral/4_clover_regular_neutral.png";
        case 17: return ":/others/images/cards/easy, medium, hard/clover/neutral/5_clover_regular_neutral.png";
        case 18: return ":/others/images/cards/easy, medium, hard/clover/neutral/6_clover_regular_neutral.png";
        case 19: return ":/others/images/cards/easy, medium, hard/clover/neutral/7_clover_regular_neutral.png";
        case 20: return ":/others/images/cards/easy, medium, hard/clover/neutral/8_clover_regular_neutral.png";
        case 21: return ":/others/images/cards/easy, medium, hard/clover/neutral/9_clover_regular_neutral.png";
        case 22: return ":/others/images/cards/easy, medium, hard/clover/neutral/10_clover_regular_neutral.png";
        case 23: return ":/others/images/cards/easy, medium, hard/clover/neutral/jopek_clover_regular_neutral.png";
        case 24: return ":/others/images/cards/easy, medium, hard/clover/neutral/dama_clover_regular_neutral.png";
        case 25: return ":/others/images/cards/easy, medium, hard/clover/neutral/krol_clover_regular_neutral.png";
        case 26: return ":/others/images/cards/easy, medium, hard/clover/neutral/as_clover_regular_neutral.png";
        // spade
        case 27: return ":/others/images/cards/easy, medium, hard/spade/neutral/2_spade_regular_neutral.png";
        case 28: return ":/others/images/cards/easy, medium, hard/spade/neutral/3_spade_regular_neutral.png";
        case 29: return ":/others/images/cards/easy, medium, hard/spade/neutral/4_spade_regular_neutral.png";
        case 30: return ":/others/images/cards/easy, medium, hard/spade/neutral/5_spade_regular_neutral.png";
        case 31: return ":/others/images/cards/easy, medium, hard/spade/neutral/6_spade_regular_neutral.png";
        case 32: return ":/others/images/cards/easy, medium, hard/spade/neutral/7_spade_regular_neutral.png";
        case 33: return ":/others/images/cards/easy, medium, hard/spade/neutral/8_spade_regular_neutral.png";
        case 34: return ":/others/images/cards/easy, medium, hard/spade/neutral/9_spade_regular_neutral.png";
        case 35: return ":/others/images/cards/easy, medium, hard/spade/neutral/10_spade_regular_neutral.png";
        case 36: return ":/others/images/cards/easy, medium, hard/spade/neutral/jopek_spade_regular_neutral.png";
        case 37: return ":/others/images/cards/easy, medium, hard/spade/neutral/dama_spade_regular_neutral.png";
        case 38: return ":/others/images/cards/easy, medium, hard/spade/neutral/krol_spade_regular_neutral.png";
        case 39: return ":/others/images/cards/easy, medium, hard/spade/neutral/as_spade_regular_neutral.png";

//        case 100: return ":/others/images/others/statisticsIconS.png";
//        case 101: return ":/others/images/others/informationFrame.png";

        default: qDebug() << "We have a problem in method Cards::setImageRegularNeutral";
                 return ":/others/images/cards/back.png";
    }
}

QString Cards::setImageRegularWrong(int number){

    switch (number+1) {
        // heart
        case 1: return ":/others/images/cards/easy, medium, hard/heart/wrong/2_serc_regular_wrong.png";
        case 2: return ":/others/images/cards/easy, medium, hard/heart/wrong/3_serc_regular_wrong.png";
        case 3: return ":/others/images/cards/easy, medium, hard/heart/wrong/4_serc_regular_wrong.png";
        case 4: return ":/others/images/cards/easy, medium, hard/heart/wrong/5_serc_regular_wrong.png";
        case 5: return ":/others/images/cards/easy, medium, hard/heart/wrong/6_serc_regular_wrong.png";
        case 6: return ":/others/images/cards/easy, medium, hard/heart/wrong/7_serc_regular_wrong.png";
        case 7: return ":/others/images/cards/easy, medium, hard/heart/wrong/8_serc_regular_wrong.png";
        case 8: return ":/others/images/cards/easy, medium, hard/heart/wrong/9_serc_regular_wrong.png";
        case 9: return ":/others/images/cards/easy, medium, hard/heart/wrong/10_serc_regular_wrong.png";
        case 10: return ":/others/images/cards/easy, medium, hard/heart/wrong/jopek_serc_regular_wrong.png";
        case 11: return ":/others/images/cards/easy, medium, hard/heart/wrong/dama_serc_regular_wrong.png";
        case 12: return ":/others/images/cards/easy, medium, hard/heart/wrong/krol_serc_regular_wrong.png";
        case 13: return ":/others/images/cards/easy, medium, hard/heart/wrong/as_serc_regular_wrong.png";
        // clover
        case 14: return ":/others/images/cards/easy, medium, hard/clover/wrong/2_clover_regular_wrong.png";
        case 15: return ":/others/images/cards/easy, medium, hard/clover/wrong/3_clover_regular_wrong.png";
        case 16: return ":/others/images/cards/easy, medium, hard/clover/wrong/4_clover_regular_wrong.png";
        case 17: return ":/others/images/cards/easy, medium, hard/clover/wrong/5_clover_regular_wrong.png";
        case 18: return ":/others/images/cards/easy, medium, hard/clover/wrong/6_clover_regular_wrong.png";
        case 19: return ":/others/images/cards/easy, medium, hard/clover/wrong/7_clover_regular_wrong.png";
        case 20: return ":/others/images/cards/easy, medium, hard/clover/wrong/8_clover_regular_wrong.png";
        case 21: return ":/others/images/cards/easy, medium, hard/clover/wrong/9_clover_regular_wrong.png";
        case 22: return ":/others/images/cards/easy, medium, hard/clover/wrong/10_clover_regular_wrong.png";
        case 23: return ":/others/images/cards/easy, medium, hard/clover/wrong/jopek_clover_regular_wrong.png";
        case 24: return ":/others/images/cards/easy, medium, hard/clover/wrong/dama_clover_regular_wrong.png";
        case 25: return ":/others/images/cards/easy, medium, hard/clover/wrong/krol_clover_regular_wrong.png";
        case 26: return ":/others/images/cards/easy, medium, hard/clover/wrong/as_clover_regular_wrong.png";
        // spade
        case 27: return ":/others/images/cards/easy, medium, hard/spade/wrong/2_spade_regular_wrong.png";
        case 28: return ":/others/images/cards/easy, medium, hard/spade/wrong/3_spade_regular_wrong.png";
        case 29: return ":/others/images/cards/easy, medium, hard/spade/wrong/4_spade_regular_wrong.png";
        case 30: return ":/others/images/cards/easy, medium, hard/spade/wrong/5_spade_regular_wrong.png";
        case 31: return ":/others/images/cards/easy, medium, hard/spade/wrong/6_spade_regular_wrong.png";
        case 32: return ":/others/images/cards/easy, medium, hard/spade/wrong/7_spade_regular_wrong.png";
        case 33: return ":/others/images/cards/easy, medium, hard/spade/wrong/8_spade_regular_wrong.png";
        case 34: return ":/others/images/cards/easy, medium, hard/spade/wrong/9_spade_regular_wrong.png";
        case 35: return ":/others/images/cards/easy, medium, hard/spade/wrong/10_spade_regular_wrong.png";
        case 36: return ":/others/images/cards/easy, medium, hard/spade/wrong/jopek_spade_regular_wrong.png";
        case 37: return ":/others/images/cards/easy, medium, hard/spade/wrong/dama_spade_regular_wrong.png";
        case 38: return ":/others/images/cards/easy, medium, hard/spade/wrong/krol_spade_regular_wrong.png";
        case 39: return ":/others/images/cards/easy, medium, hard/spade/wrong/as_spade_regular_wrong.png";

        default: qDebug() << "We have a problem in method Cards::setImageRegularWrong";
            return nullptr;
    }
}

QString Cards::setImageRegularCorrect(int number){

    switch (number+1) {
        // heart
        case 1: return ":/others/images/cards/easy, medium, hard/heart/correct/2_serc_regular_correct.png";
        case 2: return ":/others/images/cards/easy, medium, hard/heart/correct/3_serc_regular_correct.png";
        case 3: return ":/others/images/cards/easy, medium, hard/heart/correct/4_serc_regular_correct.png";
        case 4: return ":/others/images/cards/easy, medium, hard/heart/correct/5_serc_regular_correct.png";
        case 5: return ":/others/images/cards/easy, medium, hard/heart/correct/6_serc_regular_correct.png";
        case 6: return ":/others/images/cards/easy, medium, hard/heart/correct/7_serc_regular_correct.png";
        case 7: return ":/others/images/cards/easy, medium, hard/heart/correct/8_serc_regular_correct.png";
        case 8: return ":/others/images/cards/easy, medium, hard/heart/correct/9_serc_regular_correct.png";
        case 9: return ":/others/images/cards/easy, medium, hard/heart/correct/10_serc_regular_correct.png";
        case 10: return ":/others/images/cards/easy, medium, hard/heart/correct/jopek_serc_regular_correct.png";
        case 11: return ":/others/images/cards/easy, medium, hard/heart/correct/dama_serc_regular_correct.png";
        case 12: return ":/others/images/cards/easy, medium, hard/heart/correct/krol_serc_regular_correct.png";
        case 13: return ":/others/images/cards/easy, medium, hard/heart/correct/as_serc_regular_correct.png";
        // clover
        case 14: return ":/others/images/cards/easy, medium, hard/clover/correct/2_clover_regular_correct.png";
        case 15: return ":/others/images/cards/easy, medium, hard/clover/correct/3_clover_regular_correct.png";
        case 16: return ":/others/images/cards/easy, medium, hard/clover/correct/4_clover_regular_correct.png";
        case 17: return ":/others/images/cards/easy, medium, hard/clover/correct/5_clover_regular_correct.png";
        case 18: return ":/others/images/cards/easy, medium, hard/clover/correct/6_clover_regular_correct.png";
        case 19: return ":/others/images/cards/easy, medium, hard/clover/correct/7_clover_regular_correct.png";
        case 20: return ":/others/images/cards/easy, medium, hard/clover/correct/8_clover_regular_correct.png";
        case 21: return ":/others/images/cards/easy, medium, hard/clover/correct/9_clover_regular_correct.png";
        case 22: return ":/others/images/cards/easy, medium, hard/clover/correct/10_clover_regular_correct.png";
        case 23: return ":/others/images/cards/easy, medium, hard/clover/correct/jopek_clover_regular_correct.png";
        case 24: return ":/others/images/cards/easy, medium, hard/clover/correct/dama_clover_regular_correct.png";
        case 25: return ":/others/images/cards/easy, medium, hard/clover/correct/krol_clover_regular_correct.png";
        case 26: return ":/others/images/cards/easy, medium, hard/clover/correct/as_clover_regular_correct.png";
        // spade
        case 27: return ":/others/images/cards/easy, medium, hard/spade/correct/2_spade_regular_correct.png";
        case 28: return ":/others/images/cards/easy, medium, hard/spade/correct/3_spade_regular_correct.png";
        case 29: return ":/others/images/cards/easy, medium, hard/spade/correct/4_spade_regular_correct.png";
        case 30: return ":/others/images/cards/easy, medium, hard/spade/correct/5_spade_regular_correct.png";
        case 31: return ":/others/images/cards/easy, medium, hard/spade/correct/6_spade_regular_correct.png";
        case 32: return ":/others/images/cards/easy, medium, hard/spade/correct/7_spade_regular_correct.png";
        case 33: return ":/others/images/cards/easy, medium, hard/spade/correct/8_spade_regular_correct.png";
        case 34: return ":/others/images/cards/easy, medium, hard/spade/correct/9_spade_regular_correct.png";
        case 35: return ":/others/images/cards/easy, medium, hard/spade/correct/10_spade_regular_correct.png";
        case 36: return ":/others/images/cards/easy, medium, hard/spade/correct/jopek_spade_regular_correct.png";
        case 37: return ":/others/images/cards/easy, medium, hard/spade/correct/dama_spade_regular_correct.png";
        case 38: return ":/others/images/cards/easy, medium, hard/spade/correct/krol_spade_regular_correct.png";
        case 39: return ":/others/images/cards/easy, medium, hard/spade/correct/as_spade_regular_correct.png";

        default: qDebug() << "We have a problem in method Cards::setImageRegularCorrect";
            return nullptr;

    }
}

QString Cards::setImageVeryHardNeutral(int number){


    switch (number+1) {
        // heart
        case 1: return ":/others/images/cards/very hard/heart/neutral/2_serc_very_hard_neutral.png";
        case 2: return ":/others/images/cards/very hard/heart/neutral/3_serc_very_hard_neutral.png";
        case 3: return ":/others/images/cards/very hard/heart/neutral/4_serc_very_hard_neutral.png";
        case 4: return ":/others/images/cards/very hard/heart/neutral/5_serc_very_hard_neutral.png";
        case 5: return ":/others/images/cards/very hard/heart/neutral/6_serc_very_hard_neutral.png";
        case 6: return ":/others/images/cards/very hard/heart/neutral/7_serc_very_hard_neutral.png";
        case 7: return ":/others/images/cards/very hard/heart/neutral/8_serc_very_hard_neutral.png";
        case 8: return ":/others/images/cards/very hard/heart/neutral/9_serc_very_hard_neutral.png";
        case 9: return ":/others/images/cards/very hard/heart/neutral/10_serc_very_hard_neutral.png";
        case 10: return ":/others/images/cards/very hard/heart/neutral/jopek_serc_very_hard_neutral.png";
        case 11: return ":/others/images/cards/very hard/heart/neutral/dama_serc_very_hard_neutral.png";
        case 12: return ":/others/images/cards/very hard/heart/neutral/krol_serc_very_hard_neutral.png";
        case 13: return ":/others/images/cards/very hard/heart/neutral/as_serc_very_hard_neutral.png";
        // clover
        case 14: return ":/others/images/cards/very hard/clover/neutral/2_clover_very_hard_neutral.png";
        case 15: return ":/others/images/cards/very hard/clover/neutral/3_clover_very_hard_neutral.png";
        case 16: return ":/others/images/cards/very hard/clover/neutral/4_clover_very_hard_neutral.png";
        case 17: return ":/others/images/cards/very hard/clover/neutral/5_clover_very_hard_neutral.png";
        case 18: return ":/others/images/cards/very hard/clover/neutral/6_clover_very_hard_neutral.png";
        case 19: return ":/others/images/cards/very hard/clover/neutral/7_clover_very_hard_neutral.png";
        case 20: return ":/others/images/cards/very hard/clover/neutral/8_clover_very_hard_neutral.png";
        case 21: return ":/others/images/cards/very hard/clover/neutral/9_clover_very_hard_neutral.png";
        case 22: return ":/others/images/cards/very hard/clover/neutral/10_clover_very_hard_neutral.png";
        case 23: return ":/others/images/cards/very hard/clover/neutral/jopek_clover_very_hard_neutral.png";
        case 24: return ":/others/images/cards/very hard/clover/neutral/dama_clover_very_hard_neutral.png";
        case 25: return ":/others/images/cards/very hard/clover/neutral/krol_clover_very_hard_neutral.png";
        case 26: return ":/others/images/cards/very hard/clover/neutral/as_clover_very_hard_neutral.png";
        // spade
        case 27: return ":/others/images/cards/very hard/spade/neutral/2_spade_very_hard_neutral.png";
        case 28: return ":/others/images/cards/very hard/spade/neutral/3_spade_very_hard_neutral.png";
        case 29: return ":/others/images/cards/very hard/spade/neutral/4_spade_very_hard_neutral.png";
        case 30: return ":/others/images/cards/very hard/spade/neutral/5_spade_very_hard_neutral.png";
        case 31: return ":/others/images/cards/very hard/spade/neutral/6_spade_very_hard_neutral.png";
        case 32: return ":/others/images/cards/very hard/spade/neutral/7_spade_very_hard_neutral.png";
        case 33: return ":/others/images/cards/very hard/spade/neutral/8_spade_very_hard_neutral.png";
        case 34: return ":/others/images/cards/very hard/spade/neutral/9_spade_very_hard_neutral.png";
        case 35: return ":/others/images/cards/very hard/spade/neutral/10_spade_very_hard_neutral.png";
        case 36: return ":/others/images/cards/very hard/spade/neutral/jopek_spade_very_hard_neutral.png";
        case 37: return ":/others/images/cards/very hard/spade/neutral/dama_spade_very_hard_neutral.png";
        case 38: return ":/others/images/cards/very hard/spade/neutral/krol_spade_very_hard_neutral.png";
        case 39: return ":/others/images/cards/very hard/spade/neutral/as_spade_very_hard_neutral.png";
        // diamond
        case 40: return ":/others/images/cards/very hard/diamond/neutral/2_diamond_very_hard_neutral.png";
        case 41: return ":/others/images/cards/very hard/diamond/neutral/3_diamond_very_hard_neutral.png";
        case 42: return ":/others/images/cards/very hard/diamond/neutral/4_diamond_very_hard_neutral.png";
        case 43: return ":/others/images/cards/very hard/diamond/neutral/5_diamond_very_hard_neutral.png";
        case 44: return ":/others/images/cards/very hard/diamond/neutral/6_diamond_very_hard_neutral.png";
        case 45: return ":/others/images/cards/very hard/diamond/neutral/7_diamond_very_hard_neutral.png";
        case 46: return ":/others/images/cards/very hard/diamond/neutral/8_diamond_very_hard_neutral.png";
        case 47: return ":/others/images/cards/very hard/diamond/neutral/9_diamond_very_hard_neutral.png";
        case 48: return ":/others/images/cards/very hard/diamond/neutral/10_diamond_very_hard_neutral.png";
        case 49: return ":/others/images/cards/very hard/diamond/neutral/jopek_diamond_very_hard_neutral.png";
        case 50: return ":/others/images/cards/very hard/diamond/neutral/dama_diamond_very_hard_neutral.png";
        case 51: return ":/others/images/cards/very hard/diamond/neutral/krol_diamond_very_hard_neutral.png";
        case 52: return ":/others/images/cards/very hard/diamond/neutral/as_diamond_very_hard_neutral.png";

        default: qDebug() << "We have a problem in method Cards::setImageVeryHardNeutral";
            return nullptr;
    }

}

QString Cards::setImageVeryHardWrong(int number){

    switch (number+1) {
        // heart
        case 1: return ":/others/images/cards/very hard/heart/wrong/2_serc_very_hard_wrong.png";
        case 2: return ":/others/images/cards/very hard/heart/wrong/3_serc_very_hard_wrong.png";
        case 3: return ":/others/images/cards/very hard/heart/wrong/4_serc_very_hard_wrong.png";
        case 4: return ":/others/images/cards/very hard/heart/wrong/5_serc_very_hard_wrong.png";
        case 5: return ":/others/images/cards/very hard/heart/wrong/6_serc_very_hard_wrong.png";
        case 6: return ":/others/images/cards/very hard/heart/wrong/7_serc_very_hard_wrong.png";
        case 7: return ":/others/images/cards/very hard/heart/wrong/8_serc_very_hard_wrong.png";
        case 8: return ":/others/images/cards/very hard/heart/wrong/9_serc_very_hard_wrong.png";
        case 9: return ":/others/images/cards/very hard/heart/wrong/10_serc_very_hard_wrong.png";
        case 10: return ":/others/images/cards/very hard/heart/wrong/jopek_serc_very_hard_wrong.png";
        case 11: return ":/others/images/cards/very hard/heart/wrong/dama_serc_very_hard_wrong.png";
        case 12: return ":/others/images/cards/very hard/heart/wrong/krol_serc_very_hard_wrong.png";
        case 13: return ":/others/images/cards/very hard/heart/wrong/as_serc_very_hard_wrong.png";
        // clover
        case 14: return ":/others/images/cards/very hard/clover/wrong/2_clover_very_hard_wrong.png";
        case 15: return ":/others/images/cards/very hard/clover/wrong/3_clover_very_hard_wrong.png";
        case 16: return ":/others/images/cards/very hard/clover/wrong/4_clover_very_hard_wrong.png";
        case 17: return ":/others/images/cards/very hard/clover/wrong/5_clover_very_hard_wrong.png";
        case 18: return ":/others/images/cards/very hard/clover/wrong/6_clover_very_hard_wrong.png";
        case 19: return ":/others/images/cards/very hard/clover/wrong/7_clover_very_hard_wrong.png";
        case 20: return ":/others/images/cards/very hard/clover/wrong/8_clover_very_hard_wrong.png";
        case 21: return ":/others/images/cards/very hard/clover/wrong/9_clover_very_hard_wrong.png";
        case 22: return ":/others/images/cards/very hard/clover/wrong/10_clover_very_hard_wrong.png";
        case 23: return ":/others/images/cards/very hard/clover/wrong/jopek_clover_very_hard_wrong.png";
        case 24: return ":/others/images/cards/very hard/clover/wrong/dama_clover_very_hard_wrong.png";
        case 25: return ":/others/images/cards/very hard/clover/wrong/krol_clover_very_hard_wrong.png";
        case 26: return ":/others/images/cards/very hard/clover/wrong/as_clover_very_hard_wrong.png";
        // spade
        case 27: return ":/others/images/cards/very hard/spade/wrong/2_spade_very_hard_wrong.png";
        case 28: return ":/others/images/cards/very hard/spade/wrong/3_spade_very_hard_wrong.png";
        case 29: return ":/others/images/cards/very hard/spade/wrong/4_spade_very_hard_wrong.png";
        case 30: return ":/others/images/cards/very hard/spade/wrong/5_spade_very_hard_wrong.png";
        case 31: return ":/others/images/cards/very hard/spade/wrong/6_spade_very_hard_wrong.png";
        case 32: return ":/others/images/cards/very hard/spade/wrong/7_spade_very_hard_wrong.png";
        case 33: return ":/others/images/cards/very hard/spade/wrong/8_spade_very_hard_wrong.png";
        case 34: return ":/others/images/cards/very hard/spade/wrong/9_spade_very_hard_wrong.png";
        case 35: return ":/others/images/cards/very hard/spade/wrong/10_spade_very_hard_wrong.png";
        case 36: return ":/others/images/cards/very hard/spade/wrong/jopek_spade_very_hard_wrong.png";
        case 37: return ":/others/images/cards/very hard/spade/wrong/dama_spade_very_hard_wrong.png";
        case 38: return ":/others/images/cards/very hard/spade/wrong/krol_spade_very_hard_wrong.png";
        case 39: return ":/others/images/cards/very hard/spade/wrong/as_spade_very_hard_wrong.png";
        // diamond
        case 40: return ":/others/images/cards/very hard/diamond/wrong/2_diamond_very_hard_wrong.png";
        case 41: return ":/others/images/cards/very hard/diamond/wrong/3_diamond_very_hard_wrong.png";
        case 42: return ":/others/images/cards/very hard/diamond/wrong/4_diamond_very_hard_wrong.png";
        case 43: return ":/others/images/cards/very hard/diamond/wrong/5_diamond_very_hard_wrong.png";
        case 44: return ":/others/images/cards/very hard/diamond/wrong/6_diamond_very_hard_wrong.png";
        case 45: return ":/others/images/cards/very hard/diamond/wrong/7_diamond_very_hard_wrong.png";
        case 46: return ":/others/images/cards/very hard/diamond/wrong/8_diamond_very_hard_wrong.png";
        case 47: return ":/others/images/cards/very hard/diamond/wrong/9_diamond_very_hard_wrong.png";
        case 48: return ":/others/images/cards/very hard/diamond/wrong/10_diamond_very_hard_wrong.png";
        case 49: return ":/others/images/cards/very hard/diamond/wrong/jopek_diamond_very_hard_wrong.png";
        case 50: return ":/others/images/cards/very hard/diamond/wrong/dama_diamond_very_hard_wrong.png";
        case 51: return ":/others/images/cards/very hard/diamond/wrong/krol_diamond_very_hard_wrong.png";
        case 52: return ":/others/images/cards/very hard/diamond/wrong/as_diamond_very_hard_wrong.png";

        default: qDebug() << "We have a problem in method Cards::setImageVeryHardWrong";
            return nullptr;
    }
}

QString Cards::setImageVeryHardCorrect(int number){

    switch (number+1) {
        // heart
        case 1: return ":/others/images/cards/very hard/heart/correct/2_serc_very_hard_correct.png";
        case 2: return ":/others/images/cards/very hard/heart/correct/3_serc_very_hard_correct.png";
        case 3: return ":/others/images/cards/very hard/heart/correct/4_serc_very_hard_correct.png";
        case 4: return ":/others/images/cards/very hard/heart/correct/5_serc_very_hard_correct.png";
        case 5: return ":/others/images/cards/very hard/heart/correct/6_serc_very_hard_correct.png";
        case 6: return ":/others/images/cards/very hard/heart/correct/7_serc_very_hard_correct.png";
        case 7: return ":/others/images/cards/very hard/heart/correct/8_serc_very_hard_correct.png";
        case 8: return ":/others/images/cards/very hard/heart/correct/9_serc_very_hard_correct.png";
        case 9: return ":/others/images/cards/very hard/heart/correct/10_serc_very_hard_correct.png";
        case 10: return ":/others/images/cards/very hard/heart/correct/jopek_serc_very_hard_correct.png";
        case 11: return ":/others/images/cards/very hard/heart/correct/dama_serc_very_hard_correct.png";
        case 12: return ":/others/images/cards/very hard/heart/correct/krol_serc_very_hard_correct.png";
        case 13: return ":/others/images/cards/very hard/heart/correct/as_serc_very_hard_correct.png";
        // clover
        case 14: return ":/others/images/cards/very hard/clover/correct/2_clover_very_hard_correct.png";
        case 15: return ":/others/images/cards/very hard/clover/correct/3_clover_very_hard_correct.png";
        case 16: return ":/others/images/cards/very hard/clover/correct/4_clover_very_hard_correct.png";
        case 17: return ":/others/images/cards/very hard/clover/correct/5_clover_very_hard_correct.png";
        case 18: return ":/others/images/cards/very hard/clover/correct/6_clover_very_hard_correct.png";
        case 19: return ":/others/images/cards/very hard/clover/correct/7_clover_very_hard_correct.png";
        case 20: return ":/others/images/cards/very hard/clover/correct/8_clover_very_hard_correct.png";
        case 21: return ":/others/images/cards/very hard/clover/correct/9_clover_very_hard_correct.png";
        case 22: return ":/others/images/cards/very hard/clover/correct/10_clover_very_hard_correct.png";
        case 23: return ":/others/images/cards/very hard/clover/correct/jopek_clover_very_hard_correct.png";
        case 24: return ":/others/images/cards/very hard/clover/correct/dama_clover_very_hard_correct.png";
        case 25: return ":/others/images/cards/very hard/clover/correct/krol_clover_very_hard_correct.png";
        case 26: return ":/others/images/cards/very hard/clover/correct/as_clover_very_hard_correct.png";
        // spade
        case 27: return ":/others/images/cards/very hard/spade/correct/2_spade_very_hard_correct.png";
        case 28: return ":/others/images/cards/very hard/spade/correct/3_spade_very_hard_correct.png";
        case 29: return ":/others/images/cards/very hard/spade/correct/4_spade_very_hard_correct.png";
        case 30: return ":/others/images/cards/very hard/spade/correct/5_spade_very_hard_correct.png";
        case 31: return ":/others/images/cards/very hard/spade/correct/6_spade_very_hard_correct.png";
        case 32: return ":/others/images/cards/very hard/spade/correct/7_spade_very_hard_correct.png";
        case 33: return ":/others/images/cards/very hard/spade/correct/8_spade_very_hard_correct.png";
        case 34: return ":/others/images/cards/very hard/spade/correct/9_spade_very_hard_correct.png";
        case 35: return ":/others/images/cards/very hard/spade/correct/10_spade_very_hard_correct.png";
        case 36: return ":/others/images/cards/very hard/spade/correct/jopek_spade_very_hard_correct.png";
        case 37: return ":/others/images/cards/very hard/spade/correct/dama_spade_very_hard_correct.png";
        case 38: return ":/others/images/cards/very hard/spade/correct/krol_spade_very_hard_correct.png";
        case 39: return ":/others/images/cards/very hard/spade/correct/as_spade_very_hard_correct.png";
        // diamond
        case 40: return ":/others/images/cards/very hard/diamond/correct/2_diamond_very_hard_correct.png";
        case 41: return ":/others/images/cards/very hard/diamond/correct/3_diamond_very_hard_correct.png";
        case 42: return ":/others/images/cards/very hard/diamond/correct/4_diamond_very_hard_correct.png";
        case 43: return ":/others/images/cards/very hard/diamond/correct/5_diamond_very_hard_correct.png";
        case 44: return ":/others/images/cards/very hard/diamond/correct/6_diamond_very_hard_correct.png";
        case 45: return ":/others/images/cards/very hard/diamond/correct/7_diamond_very_hard_correct.png";
        case 46: return ":/others/images/cards/very hard/diamond/correct/8_diamond_very_hard_correct.png";
        case 47: return ":/others/images/cards/very hard/diamond/correct/9_diamond_very_hard_correct.png";
        case 48: return ":/others/images/cards/very hard/diamond/correct/10_diamond_very_hard_correct.png";
        case 49: return ":/others/images/cards/very hard/diamond/correct/jopek_diamond_very_hard_correct.png";
        case 50: return ":/others/images/cards/very hard/diamond/correct/dama_diamond_very_hard_correct.png";
        case 51: return ":/others/images/cards/very hard/diamond/correct/krol_diamond_very_hard_correct.png";
        case 52: return ":/others/images/cards/very hard/diamond/correct/as_diamond_very_hard_correct.png";

        default: qDebug() << "We have a problem in method Cards::setImageVeryHardCorrect";
            return nullptr;
    }
}

//QString Cards::setImageOptions(int number){

//    switch (number) {

//        case 1: return ":/others/images/others/options/Options.png";
//        case 2: return ":/others/images/others/options/difficultLevel.png";
//        case 3: return ":/others/images/others/options/buttonEasy.png";
//        case 4: return ":/others/images/others/options/buttonMedium.png";
//        case 5: return ":/others/images/others/options/buttonHard.png";
//        case 6: return ":/others/images/others/options/buttonHardcore.png";

//        default: qDebug() << "We have a problem in method Cards::setImageOptions";
//            return nullptr;
//    }
//}

//QString Cards::setImageOthers(int number){

//    switch (number) {
//        case 1: return ":/others/images/others/buttonBack.png";
//        case 2: return ":/others/images/others/actuallyLvl.png";
//        case 3: return ":/others/images/cards/backVeryHard.png";
//        case 4: return ":/others/images/cards/activeVeryHard.png";
//        case 5: return ":/others/images/others/informationFrame.png";
//        case 6: return ":/others/images/others/statisticsIconS.png";
//        case 7: return ":/others/images/others/correct.png";
//        case 8: return ":/others/images/others/wrong.png";
//        case 9: return ":/others/images/others/correctVeryHard.png";
//        case 10: return ":/others/images/others/wrongVeryHard.png";
//        case 11: return ":/others/images/others/summaryGameOver.png";


//        default: qDebug() << "We have a problem in method Cards::setImageOthers";
//            return nullptr;
//    }

//}

QString Cards::setActive(bool side, bool lvl){

    if( lvl == true ){

        if( side == true )
            return  ":/others/images/cards/active.png";
        else
            return ":/others/images/cards/back.png";

    } else if( lvl == false ){

        if( side == true )
            return  ":/others/images/cards/activeVeryHard.png";
        else
            return ":/others/images/cards/backVeryHard.png";

    } else
        qDebug() << "Error in method Cards::setActive()";

    return nullptr;

}



//void Cards::generatorOfRandomNumbers(int difficultLvl){

//    srand(time ( nullptr ));

//    int selectedAtRandom = 0;
//    int number;

//    do
//       {
//           number = rand() % difficultLvl;
//           if( IfItWasDrawn( number, selectedAtRandom ) == false ){
//               RandomNumbers[ selectedAtRandom ] = number;
//               selectedAtRandom++;
//           }

//    } while( selectedAtRandom < difficultLvl );
//}




//bool Cards::IfItWasDrawn( int iNumber, int selectedAtRandom ){

//    if( selectedAtRandom <= 0 )
//         return false;

//    for(int i = 0; i < selectedAtRandom; i++){
//        if( RandomNumbers[i] == iNumber)
//            return true;
//    }

//    return false;
//}

//void Cards::handleClickWrong(){

//    DrawCards *draw = new DrawCards();
//    emit buttonClickedWrong(draw->getVariableForChooseImage());
//}

//void Cards::handleClickCorrect(){

//    DrawCards *draw = new DrawCards();
//    emit buttonClickedCorrect(draw->getVariableForChooseImage());
//}
