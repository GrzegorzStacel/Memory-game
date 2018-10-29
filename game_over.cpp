#include "game_over.h"
#include "game.h"
#include "mainbuttons.h"
#include "drawcards.h"

#include "timer.h"

#include <QFont>

#include <QDebug>

extern Game *game;

game_over::game_over(){

}

void game_over::drawPanel(double x, double y, double width, double height, QColor color, double opacity){

    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    game->scene->addItem(panel);
}

void game_over::drawButtons(){

    double x_pos = game->scene->width();
    double y_pos = game->scene->height();

    for (int i = 0, n = game->scene->items().size(); i < n; i++){
        game->scene->items()[i]->setEnabled(false);
    }

    // pop up semi transparent panel
    drawPanel(0, 0, x_pos, y_pos, Qt::black, 0.65);

    // draw panel
    drawPanel(312, 184, x_pos/2, y_pos/2, Qt::lightGray, 0.85);

    // create text with the time reminding
    timer *time = new timer();
    qDebug() << "Time gameover: " << time->get_time();
    QGraphicsTextItem* clock = new QGraphicsTextItem("Your memorizing time " + time->get_time());
    QFont title("comic sans", 18, QFont::Bold);
    clock->setFont(title);
    double txxPos = x_pos/2 - time->boundingRect().width()/3;
    clock->setPos(txxPos-310,200);
    game->scene->addItem(clock);

    // create text annoucning winner
    QGraphicsTextItem* overText = new QGraphicsTextItem("Congratulations");
    QFont titleFont("comic sans", 50);
    overText->setFont(titleFont);
    double txPos = x_pos/2 - overText->boundingRect().width()/2;
    overText->setPos(txPos-15,260);
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

void game_over::restartGame(){

    // reset important counters
    DrawCards *draw = new DrawCards();
    draw->setResetAllInOne();
    draw->isActive = true;

    timer *time = new timer();
    time->set_mRunning(false);
    time->set_timeString("");

    game->start();
    time->start();

}

