#include "game_over.h"
#include "game.h"
#include "mainbuttons.h"


#include <QFont>

#include <QDebug>

extern Game *game;

game_over::game_over(){

    double x_pos = game->scene->width();
    double y_pos = game->scene->height();

    for (int i = 0, n = game->scene->items().size(); i < n; i++){
        game->scene->items()[i]->setEnabled(false);
    }

    // pop up semi transparent panel
    drawPanel(0, 0, x_pos, y_pos, Qt::black, 0.65);

    // draw panel
    drawPanel(312, 184, x_pos/2, y_pos/2, Qt::lightGray, 0.85);

    // create text annoucning winner
    QGraphicsTextItem* overText = new QGraphicsTextItem("Congratulations");
    QFont titleFont("comic sans", 50);
    overText->setFont(titleFont);
    double txPos = x_pos/2 - overText->boundingRect().width()/2;
    overText->setPos(txPos-15,225);
    game->scene->addItem(overText);

    // create playAgain button
    MainButtons* playAgain = new MainButtons(QString("Play Again"));
    playAgain->setPos(400, 450);
    game->scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    // create quit button
    MainButtons* quit = new MainButtons(QString("Quit"));
    quit->setPos(x_pos/2, 450);
    game->scene->addItem(quit);
    connect(quit, SIGNAL(clicked()), game, SLOT(close()));
}

void game_over::drawPanel(int x, int y, double width, double height, QColor color, double opacity){

    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    game->scene->addItem(panel);
}

void game_over::restartGame(){

    // reset important counters
    draw = new DrawCards();
//    draw->setCounter(0);
//    draw->setCounterEnd(0);
    draw->setResetAllInOne();


    game->start();

}

void game_over::close(){
    close();
}

