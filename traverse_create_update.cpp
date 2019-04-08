#include "traverse_create_update.h"
#include "game.h"

#include <QDebug>

extern Game *game;

Traverse_Create_Update::Traverse_Create_Update(Traverse &obj) : Traverse_Create_Continue(obj){

}

void Traverse_Create_Update::update_start( int value ){

    number_of_colour = value;
    which_graphic();
    how_many_save();

    game->scene->clear();
    back_button(1);

    create_objects();
    add_description();

}
