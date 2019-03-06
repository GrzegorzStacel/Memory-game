#include "options_difficulty_level.h"

#include "game.h"
#include "cards.h"
#include "statistic.h"

#include "graphic_options.h"

#include <QDebug>

extern Game *game;

options_difficulty_level::options_difficulty_level(){

}

void options_difficulty_level::show_options(){

    game->scene->clear();

    double x_pos = game->scene->width()/3;
    double y_pos = game->scene->height()/6;

    // add the title text from image
    Graphic_options *graphics_title_text = new Graphic_options();
    graphics_title_text->setPixmap(graphics_title_text->setImageOptions(1));
    graphics_title_text->setPos(x_pos - 25, y_pos);
    game->scene->addItem(graphics_title_text);

    // add the difficult text from image
    Graphic_options *graphics_difficult_text = new Graphic_options();
    graphics_difficult_text->setPixmap(graphics_difficult_text->setImageOptions(2));
    graphics_difficult_text->setPos(x_pos, y_pos+170);
    game->scene->addItem(graphics_difficult_text);

    // add the easy button from image
    Graphic_options *graphics_easy = new Graphic_options();
    graphics_easy->setPixmap(graphics_easy->setImageOptions(3));
    graphics_easy->setPos(x_pos + 200, y_pos + 360);
    game->scene->addItem(graphics_easy);
    connect(graphics_easy, SIGNAL(clicked()),this,SLOT(easy()));

    // add the medium button from image
    Graphic_options *graphics_medium = new Graphic_options();
    graphics_medium->setPixmap(graphics_medium->setImageOptions(4));
    graphics_medium->setPos(x_pos + 200, y_pos + 440);
    game->scene->addItem(graphics_medium);
    connect(graphics_medium, SIGNAL(clicked()),this,SLOT(medium()));

    // add the hard button from image
    Graphic_options *graphics_hard= new Graphic_options();
    graphics_hard->setPixmap(graphics_hard->setImageOptions(5));
    graphics_hard->setPos(x_pos + 200, y_pos + 520);
    game->scene->addItem(graphics_hard);
    connect(graphics_hard, SIGNAL(clicked()),this,SLOT(hard()));

    // add the hardcore button from image
    Graphic_options *graphics_hardcore= new Graphic_options();
    graphics_hardcore->setPixmap(graphics_hardcore->setImageOptions(6));
    graphics_hardcore->setPos(x_pos + 200, y_pos+600);
    game->scene->addItem(graphics_hardcore);
    connect(graphics_hardcore, SIGNAL(clicked()),this,SLOT(hardcore()));

    // add the back button from image
    Cards *buttonBack = new Cards();
    buttonBack->setPixmap(buttonBack->setImageOthers(1));
    buttonBack->setPos(x_pos + 550, y_pos+710);
    game->scene->addItem(buttonBack);
    connect(buttonBack, SIGNAL(clicked()), game, SLOT(displayMainMenu()));

}

void options_difficulty_level::easy(){

    stat = new statistic();

    stat->setSettings(13);
    stat->write(7,0);
}

void options_difficulty_level::medium(){

    stat = new statistic();

    stat->setSettings(26);
    stat->write(7,0);
}

void options_difficulty_level::hard(){

    stat = new statistic();

    stat->setSettings(39);
    stat->write(7,0);
}

void options_difficulty_level::hardcore(){

    stat = new statistic();

    stat->setSettings(52);
    stat->write(7,0);
}



