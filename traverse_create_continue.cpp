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
    connect_save_button();

}

void Traverse_Create_Continue::add_description(){

     int is_it_saved = 0;

    for (int i = group_card - 13, n = 0; i < group_card; ++n, ++i) {

        description = db.select("SELECT description FROM user_cards WHERE id = " + QString::number( i + 1 ) + " ;");

        list_object[n]->start();
        list_object[n]->text.setPlainText(description);

        is_it_saved = db.select("SELECT is_it_saved FROM user_cards WHERE id = " + QString::number( i + 1 ) + " ;").toInt();
        if( is_it_saved == 1){
            list_object[n]->save_button.hide();
            list_object[n]->set_is_save(true);
        }

    }
}

void Traverse_Create_Continue::connect_save_button(){

    for (int i = 0; i < 13; ++i)
        connect( & list_object[i]->save_button, &QPushButton::clicked, this, [=](){ this->save_changes(); } );

}

void Traverse_Create_Continue::save_changes(){

    QString id_card = QString::number( list_object[who_is_active]->get_id_colour() );
    description = list_object[who_is_active]->text.toPlainText();

    int id_card_to_update = (group_card + who_is_active) - 12;

    db.insert("UPDATE user_cards SET description = \"" + description + "\", is_it_saved = " + QString::number(1) +
              " WHERE id = " + QString::number(id_card_to_update) + " AND is_it_saved = 0 AND colour = " + QString::number(number_of_colour) +
              " AND id_card = " + id_card + ";");


    list_object[who_is_active]->save_button.hide();
    list_object[who_is_active]->set_is_save(true);
}
