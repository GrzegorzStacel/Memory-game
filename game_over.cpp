#include "game_over.h"
#include "game.h"
#include "mainbuttons.h"

#include "drawcards.h"
#include "timer.h"
#include "cards.h"

#include "graphic_others.h"
#include "statistic_is_best_time.h"
#include "options_difficulty_level.h"

#include <QFont>
#include <QWhatsThis>


extern Game *game;

game_over::game_over(QObject *parent) : QObject (parent){

}

void game_over::drawPanel(double x, double y, double width, double height, QColor color, double opacity){

    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem *panel = new QGraphicsRectItem(x,y,width,height);
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
    drawPanel(470, 150, x_pos/2, y_pos/2 + 260, Qt::lightGray, 0.85);

    // create text annoucning winner
    QPointer <QGraphicsTextItem> overText = new QGraphicsTextItem("Congratulations!");
    QFont titleFont("comic sans", 60);
    overText->setFont(titleFont);
    double txPos3 = x_pos/2 - overText->boundingRect().width()/2;
    overText->setPos(txPos3-15,200);
    game->scene->addItem(overText);

    // create playAgain button
    QPointer <MainButtons> playAgain = new MainButtons(QString("Play Again"));
    playAgain->setPos(600, 430);
    game->scene->addItem(playAgain);
    connect(playAgain, SIGNAL(clicked()),this,SLOT(restartGame()));

    // create options button
    QPointer <MainButtons> options = new MainButtons(QString("Options"));
    options_difficulty_level *difficult = new options_difficulty_level();
    options->setPos(850, 430);
    game->scene->addItem(options);
    connect(options, SIGNAL(clicked()), difficult, SLOT(show_options()));

    // create quit button
    QPointer <MainButtons> quit = new MainButtons(QString("Quit"));
    quit->setPos(1100, 430);
    game->scene->addItem(quit);
    connect(quit, SIGNAL(clicked()), game, SLOT(close()));

    // set the image with "Your memorizing time ", correct and wrong
    QPointer <Graphic_others> graphic = new Graphic_others;
    graphic->setPixmap(graphic->setImageOthers(11));
    graphic->setPos(550, 350);
    game->scene->addItem(graphic);

    // create text with the time reminding
    QPointer <timer> time = new timer;
    QPointer <QGraphicsTextItem> clock2 = new QGraphicsTextItem(time->getTime());
    clock2->setDefaultTextColor(Qt::darkBlue);
    QFont title2("comic sans", 18, QFont::Bold);
    clock2->setFont(title2);
    clock2->setPos(800,650);
    game->scene->addItem(clock2);

    // create a label that displays a summary of the statistics of the completed game - correct answers
    QPointer <QGraphicsTextItem> stats1 = new QGraphicsTextItem(QString(QString::number(stat->getCorrect())));
    stats1->setDefaultTextColor(Qt::darkGreen);
    QFont title3("comic sans", 15, QFont::Bold);
    stats1->setFont(title3);
    stats1->setPos(860,755);
    game->scene->addItem(stats1);

    // create a label that displays a summary of the statistics of the completed game - wrong answers
    QPointer <QGraphicsTextItem> stats2 = new QGraphicsTextItem(QString(QString::number(stat->getWrong())));
    stats2->setDefaultTextColor(Qt::darkRed);
    stats2->setFont(title3);
    stats2->setPos(1120,755);
    game->scene->addItem(stats2);

    // Show icon in arrow up/down or point depending on the time obtained
    QPointer <statistic_Is_Best_Time> is_best = new statistic_Is_Best_Time;
    QPointer <QGraphicsTextItem> Summary_Text = new QGraphicsTextItem(is_best->Set_Icon_Time());
    QString text_colour = is_best->Set_Colour_Of_Text();
    Summary_Text->setDefaultTextColor(text_colour);
    QFont SummaryFont("comic sans", 15, 87);
    Summary_Text->setFont(SummaryFont);
    Summary_Text->setPos(530,840);
    game->scene->addItem(Summary_Text);

    // creates an icon that leads to statistics
    QPointer <Graphic_others> stat_icon = new Graphic_others;
    stat_icon->setToolTip("Your statistics");
    stat_icon->setPixmap(stat_icon->setImageOthers(6));
    stat_icon->setPos(x_pos/5 + 100, 170);
    game->scene->addItem(stat_icon);
    connect(stat_icon, SIGNAL(clicked()),this,SLOT(goToStatistics()));

}



void game_over::restartGame(){

    // reset important counters
    QPointer <DrawCards> draw = new DrawCards;
    draw->setResetDrawCards();

    QPointer <timer> time = new timer;
    time->ResetTimerVariable();

    stat->ResetStatisticVariable();

    game->start();
    time->start();
}

void game_over::goToStatistics(){

    restartGame();

    game->scene->clear();

    stat->showstatic();
}

