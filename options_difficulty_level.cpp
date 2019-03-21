#include "options_difficulty_level.h"
#include "game.h"
#include "graphic_options.h"
#include "database.h"

#include <QDebug>

extern Game *game;

options_difficulty_level::options_difficulty_level(QObject *parent) : QObject (parent){

}

void options_difficulty_level::show_options(){

    game->scene->clear();

    double x_pos = game->scene->width()/3;
    double y_pos = game->scene->height()/6;

    // add the title text from image
    QPointer <Graphic_options> graphics_title_text = new Graphic_options;
    graphics_title_text->setPixmap(graphics_title_text->setImageOptions(1));
    graphics_title_text->setPos(x_pos - 25, y_pos);
    game->scene->addItem(graphics_title_text);

    // add the difficult text from image
    QPointer <Graphic_options> graphics_difficult_text = new Graphic_options;
    graphics_difficult_text->setPixmap(graphics_difficult_text->setImageOptions(2));
    graphics_difficult_text->setPos(x_pos, y_pos+170);
    game->scene->addItem(graphics_difficult_text);

    // add the easy button from image
    QPointer <Graphic_options> graphics_easy = new Graphic_options;
    graphics_easy->setPixmap(graphics_easy->setImageOptions(3));
    graphics_easy->setPos(x_pos + 200, y_pos + 360);
    game->scene->addItem(graphics_easy);
    connect(graphics_easy, SIGNAL(clicked()),this,SLOT(easy()));

    // add the medium button from image
    QPointer <Graphic_options> graphics_medium = new Graphic_options;
    graphics_medium->setPixmap(graphics_medium->setImageOptions(4));
    graphics_medium->setPos(x_pos + 200, y_pos + 440);
    game->scene->addItem(graphics_medium);
    connect(graphics_medium, SIGNAL(clicked()),this,SLOT(medium()));

    // add the hard button from image
    QPointer <Graphic_options> graphics_hard= new Graphic_options;
    graphics_hard->setPixmap(graphics_hard->setImageOptions(5));
    graphics_hard->setPos(x_pos + 200, y_pos + 520);
    game->scene->addItem(graphics_hard);
    connect(graphics_hard, SIGNAL(clicked()),this,SLOT(hard()));

    // add the hardcore button from image
    QPointer <Graphic_options> graphics_hardcore= new Graphic_options;
    graphics_hardcore->setPixmap(graphics_hardcore->setImageOptions(6));
    graphics_hardcore->setPos(x_pos + 200, y_pos+600);
    game->scene->addItem(graphics_hardcore);
    connect(graphics_hardcore, SIGNAL(clicked()),this,SLOT(hardcore()));

    // add the back button from image
    QPointer <Graphic_others> buttonBack = new Graphic_others;
    buttonBack->setPixmap(buttonBack->setImageOthers(1));
    buttonBack->setPos(x_pos + 550, y_pos+710);
    game->scene->addItem(buttonBack);
    connect(buttonBack, SIGNAL(clicked()), game, SLOT(displayMainMenu()));

}

void options_difficulty_level::easy(){

    {
        DataBase db;
        db.insert("UPDATE user_settings SET difficult = 13 WHERE id = 1");
    }

}

void options_difficulty_level::medium(){

    {
        DataBase db;
        db.insert("UPDATE user_settings SET difficult = 26 WHERE id = 1");
    }

}

void options_difficulty_level::hard(){


    {
        DataBase db;
        db.insert("UPDATE user_settings SET difficult = 39 WHERE id = 1");
    }

}

void options_difficulty_level::hardcore(){

    {
        DataBase db;
        db.insert("UPDATE user_settings SET difficult = 52 WHERE id = 1");
    }

}



