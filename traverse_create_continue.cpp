#include "traverse_create_continue.h"
#include "game.h"

extern Game *game;

Traverse_Create_Continue::Traverse_Create_Continue(Traverse &obj) : Traverse_Create_New (obj) {
    // This change is important in cleanning when the user clicked a back button
    counter = 12;
}

void Traverse_Create_Continue::continue_start(int value)  {

    number_of_colour = value;
    which_graphic();
    game->scene->clear();

    back_button(1);

    create_objects();
    add_description();
}

void Traverse_Create_Continue::add_description(){

    for (int i = group_card - 13; i < group_card; ++i) {

        description = db.select("SELECT description FROM user_cards WHERE id = " + QString::number( i + 1 ) + ";");

        list_object[i]->text.setText(description);
        list_object[i]->save_button.hide();
        list_object[i]->start();
    }
}
