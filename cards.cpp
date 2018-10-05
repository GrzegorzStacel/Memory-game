#include "cards.h"
#include "game.h"


#include <QDebug>
//#include <QGraphicsItem>
//#include <QLabel>

extern Game *game;

Cards::Cards(int xa) : foo(xa){

//    int x = 150, y = 600, start = 0, end = 3;

//    for(int i = 0; i < 3; ++i, ++start){

//        for(; start < end; ++start){

//            if(start == 6){
//                y-=250;
//                x=150;
//            }
//            else if(start == 12){
//                y-=250;
//                x=575;
//            }

//                 cards[start] = new Cards(start+1);
//                 cards[start]->setPixmap(QPixmap(":/others/images/cards/back.png"));
//                 cards[start]->setPos(x, y);
//                 scene->addItem(cards[start]);

//                 x += 150;
//        }
//        x += 100;
//        end += 6;
//        --start;
//    }



    //if(foo == 1)
       setPixmap(QPixmap(":/others/images/cards/back.png"));

//        switch (create) {
//            case 1: setPixmap(QPixmap(":/cards/images/karty/heart/2_serc.png")); break;
//            case 2: setPixmap(QPixmap(":/cards/images/karty/heart/3_serc.png")); break;
//            case 3: setPixmap(QPixmap(":/cards/images/karty/heart/4_serc.png")); break;
//            case 4: setPixmap(QPixmap(":/cards/images/karty/heart/5_serc.png")); break;
//            case 5: setPixmap(QPixmap(":/cards/images/karty/heart/6_serc.png")); break;
//            case 6: setPixmap(QPixmap(":/cards/images/karty/heart/7_serc.png")); break;
//            case 7: setPixmap(QPixmap(":/cards/images/karty/heart/8_serc.png")); break;
//            case 8: setPixmap(QPixmap(":/cards/images/karty/heart/9_serc.png")); break;
//            case 9: setPixmap(QPixmap(":/cards/images/karty/heart/10_serc.png")); break;
//            case 10: setPixmap(QPixmap(":/cards/images/karty/heart/jopek_serc.png")); break;
//            case 11: setPixmap(QPixmap(":/cards/images/karty/heart/dama_serc.png")); break;
//            case 12: setPixmap(QPixmap(":/cards/images/karty/heart/krol_serc.png")); break;
//            case 13: setPixmap(QPixmap(":/cards/images/karty/heart/as_serc.png")); break;
//        }



//    else
//        qDebug() << "We have problem, probably witch variable \"witchone\" in class \"cards.cpp\" ";
}

void Cards::VisualizeCards(int x, int y){

//int start = 0, end = 3;

//for(int i = 0; i < 3; ++i, ++start){

//    for(; start < end; ++start){

//        if(start == 6){
//            y-=250;
//            x=150;
//        }
//        else if(start == 12){
//            y-=250;
//            x=575;
//        }
setPixmap(QPixmap(":/others/images/cards/back.png"));
setPos(x, y);
             //cards[start] = new Cards(1);
             //cards[start]->setPos(x, y);
             //scene->addItem(cards[start]);

//             x += 150;
//    }
//    x += 100;
//    end += 6;
//    --start;
}
//}
