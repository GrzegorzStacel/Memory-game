#include "traverse_visibility_managmement.h"
#include "game.h"

#include <QDebug>

extern Game *game;

Traverse_visibility_managmement::Traverse_visibility_managmement(){

    // Checks whether the user has created associations for some color from the cards
    if(db->select("SELECT pack_of_cards FROM user_settings WHERE id = 1").toInt() == 0)
        isMenu = false;
    else
        isMenu = true;

    qDebug() << "ismenu: " << isMenu;

    // Gets the number of well-known user-color cards
    isNew = db->select("SELECT new_pack_of_cards FROM user_settings WHERE id = 1").toInt();

    qDebug() << "isnew: " << isNew;
}

void Traverse_visibility_managmement::showMenu(){

    int y_pos = 600;
    game->scene->clear();

    // create the Add New Deck Of Cards button
    adds_new = new MainButtons(QString("Travers"));
    double bxPos = game->width()/2 - adds_new->boundingRect().width()/2;
    adds_new->setPos(bxPos,400);
    connect(adds_new, SIGNAL(clicked()), this, SLOT(Add_New()));
    game->scene->addItem(adds_new);

    // create the Polygon For Memorization button
    exercise = new MainButtons(QString("Your Deck"));
    exercise->setPos(bxPos,500);
    connect(exercise, SIGNAL(clicked()), this, SLOT(Exercise()));

    // Checks whether the user has already created his first batch of cards, if not the button with the exercises will be hidden
    if(isMenu == false){

        adds_new->setToolTip("Create your first batch of cards to unlock other functionalities");
        y_pos = 500;

    }
    else
        game->scene->addItem(exercise);


    // create the back button to main menu
    back = new MainButtons(QString("Back"));
    back->setPos(bxPos,y_pos);
    connect(back, SIGNAL(clicked()), game, SLOT(displayMainMenu()));
    game->scene->addItem(back);

    }

void Traverse_visibility_managmement::Add_New(){


}

void Traverse_visibility_managmement::Exercise(){
    qDebug() << "in exercose";
}
