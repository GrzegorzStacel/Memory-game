#include "game_over.h"
#include "game.h"
#include "mainbuttons.h"

#include "drawcards.h"
#include "timer.h"
#include <cards.h>

#include <QFont>
#include <QWhatsThis>


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
    drawPanel(312, 150, x_pos/2, y_pos/2 + 50, Qt::lightGray, 0.85);

    // create text with the time reminding
    QGraphicsTextItem* clock = new QGraphicsTextItem("Your memorizing time:\n ");
    QFont title("comic sans", 18, QFont::Bold);
    clock->setFont(title);
    double txPos1 = x_pos/2 - clock->boundingRect().width()/2;
    clock->setPos(txPos1,180);
    game->scene->addItem(clock);

    // create text with the time reminding
    timer *time = new timer();
    QGraphicsTextItem* clock2 = new QGraphicsTextItem(time->getTime());
    clock2->setDefaultTextColor(Qt::darkBlue);
    QFont title2("comic sans", 18, QFont::Bold);
    clock2->setFont(title2);
    double txPos2 = x_pos/2 - clock->boundingRect().width()/2;
    clock2->setPos(txPos2+30,230);
    game->scene->addItem(clock2);

    // create text annoucning winner
    QGraphicsTextItem* overText = new QGraphicsTextItem("Congratulations!");
    QFont titleFont("comic sans", 40);
    overText->setFont(titleFont);
    double txPos3 = x_pos/2 - overText->boundingRect().width()/2;
    overText->setPos(txPos3-15,280);
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

    // create a label that displays a summary of the statistics of the completed game - correct answers
    QGraphicsTextItem* stats1 = new QGraphicsTextItem(QString("Correct: " + QString::number(stat->getCorrect())));
    stats1->setDefaultTextColor(Qt::darkGreen);
    QFont title3("comic sans", 15, QFont::Bold);
    stats1->setFont(title3);
    stats1->setPos(x_pos/4 + 90,550);
    game->scene->addItem(stats1);

    // create a label that displays a summary of the statistics of the completed game - wrong answers
    QGraphicsTextItem* stats2 = new QGraphicsTextItem(QString("Wrong: " + QString::number(stat->getWrong())));
    stats2->setDefaultTextColor(Qt::darkRed);
    stats2->setFont(title3);
    stats2->setPos(x_pos/2 + 20,550);
    game->scene->addItem(stats2);

    // creates an icon that leads to statistics
    Cards *icon = new Cards();
    icon->setToolTip("Your statistics");
    icon->setPixmap(icon->setImageRegularNeutral(99));
    icon->setPos(x_pos/4, 165);
    game->scene->addItem(icon);
    connect(icon, SIGNAL(clicked()),this,SLOT(goToStatistics()));

}



void game_over::restartGame(){

    // reset important counters
    DrawCards *draw = new DrawCards();
    draw->setResetDrawCards();

    timer *time = new timer();
    time->ResetTimerVariable();

    stat->ResetStatisticVariable();

    statisticBestTime bestStat;
    bestStat.ResetStaticBestTimeVariable();

    game->start();
    time->start();
}

void game_over::goToStatistics(){

    restartGame();

    game->scene->clear();

    stat->showstatic();
}

