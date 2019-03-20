#include "traverse_create_new.h"
#include "game.h"

#include <QDebug>

extern Game *game;

Traverse_Create_new::Traverse_Create_new(){

}

void Traverse_Create_new::Learn(int value){

    game->scene->clear();


    add_button( value, 100, 100 );

}

void Traverse_Create_new::add_button(int value, int x_pos, int y_pos){

    Graphic_others *picture = new Graphic_others();
    picture->setPixmap(picture->setImageOthers(value));
    picture->setPos(x_pos, y_pos);
    game->scene->addItem(picture);

}

void Traverse_Create_new::which_graphic(int value){

    // Chose the group of cards to learning
    if(value == 0)      group_card = 0;
    else if(value == 1) group_card = 13;
    else if(value == 2) group_card = 26;
    else if(value == 3) group_card = 39;
}

