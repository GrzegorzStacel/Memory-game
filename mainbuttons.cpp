#include "mainbuttons.h"
#include "game.h"

#include <QFont>
#include <QPoint>

extern Game *game;

MainButtons::MainButtons()
{
    // Create the start button in main menu
    setPlainText(QString("Start"));
    setDefaultTextColor("Green");
    setFont(QFont("times", 70, 75));
    setPos(QPoint(500, 200));
    //this->setFlag(QGraphicsTextItem::ItemIsFocusable);
    //this->setFocus();
}

void MainButtons::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Space){
        //game->Change(1);
        game->start();
    }
}
