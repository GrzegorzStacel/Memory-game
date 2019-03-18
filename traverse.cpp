#include "traverse.h"
#include "game.h"

#include <QDebug>

extern Game *game;

Traverse::Traverse(){

}

void Traverse::traverse_menu(){

    game->scene->clear();

    visible = new Traverse_visibility_managmement();
    visible->showMenu();



}


