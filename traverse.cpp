#include "traverse.h"
#include "game.h"

#include <QDebug>

extern Game *game;

Traverse::Traverse(){

}

void Traverse::traverse_menu(){

    game->scene->clear();

    // create the Add New Deck Of Cards button
    adds_new = new MainButtons(QString("Travers"));
    adds_new->setPos(600,400);
    connect(adds_new, SIGNAL(clicked()), this, SLOT(Add_New()));
    game->scene->addItem(adds_new);

    // create the Polygon For Memorization button
    exercise = new MainButtons(QString("Your Deck"));
    exercise->setPos(600,500);
    connect(exercise, SIGNAL(clicked()), this, SLOT(Exercise()));
    game->scene->addItem(exercise);
}

void Traverse::Add_New(){
    qDebug() << "in new";
}

void Traverse::Exercise(){
    qDebug() << "in exercose";
}
