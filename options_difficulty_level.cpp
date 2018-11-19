#include "options_difficulty_level.h"

#include "game.h"
#include "cards.h"
#include "statistic.h"

#include <QDebug>

extern Game *game;

options_difficulty_level::options_difficulty_level(){

}

void options_difficulty_level::show_options(){

    game->scene->clear();

    double x_pos = game->scene->width()/3;
    double y_pos = game->scene->height()/6;

    // add the title text from image
    Cards *title = new Cards();
    title->setPixmap(title->setImageOptions(1));
    title->setPos(x_pos - 25, y_pos);
    game->scene->addItem(title);

    // add the difficult text from image
    Cards *difficultText = new Cards();
    difficultText->setPixmap(difficultText->setImageOptions(2));
    difficultText->setPos(x_pos, y_pos+170);
    game->scene->addItem(difficultText);

    // add the easy button from image
    Cards *buttonEasy = new Cards();
    buttonEasy->setPixmap(buttonEasy->setImageOptions(3));
    buttonEasy->setPos(x_pos + 200, y_pos + 360);
    game->scene->addItem(buttonEasy);
    connect(buttonEasy, SIGNAL(clicked()),this,SLOT(easy()));

    // add the medium button from image
    Cards *buttonMedium = new Cards();
    buttonMedium->setPixmap(buttonMedium->setImageOptions(4));
    buttonMedium->setPos(x_pos + 200, y_pos + 440);
    game->scene->addItem(buttonMedium);
    connect(buttonMedium, SIGNAL(clicked()),this,SLOT(medium()));

    // add the hard button from image
    Cards *buttonHard = new Cards();
    buttonHard->setPixmap(buttonHard->setImageOptions(5));
    buttonHard->setPos(x_pos + 200, y_pos + 520);
    game->scene->addItem(buttonHard);
    connect(buttonHard, SIGNAL(clicked()),this,SLOT(hard()));

    // add the hardcore button from image
    Cards *buttonHardcore = new Cards();
    buttonHardcore->setPixmap(buttonHardcore->setImageOptions(6));
    buttonHardcore->setPos(x_pos + 200, y_pos+600);
    game->scene->addItem(buttonHardcore);
    connect(buttonHardcore, SIGNAL(clicked()),this,SLOT(hardcore()));

    // add the back button from image
    Cards *buttonBack = new Cards();
    buttonBack->setPixmap(buttonBack->setImageOthers(1));
    buttonBack->setPos(x_pos + 550, y_pos+710);
    game->scene->addItem(buttonBack);
    connect(buttonBack, SIGNAL(clicked()), game, SLOT(displayMainMenu()));


}

void options_difficulty_level::easy(){
    qDebug() << "easy";
    stat = new statistic();

    stat->setSettings(13);
    stat->write(7,0);
}

void options_difficulty_level::medium(){
qDebug() << "easy1";

    stat = new statistic();

    stat->setSettings(26);
    stat->write(7,0);
}

void options_difficulty_level::hard(){
qDebug() << "easy2";

    stat = new statistic();

    stat->setSettings(39);
    stat->write(7,0);
}

void options_difficulty_level::hardcore(){
qDebug() << "easy3";

    stat = new statistic();

    stat->setSettings(52);
    stat->write(7,0);
}



