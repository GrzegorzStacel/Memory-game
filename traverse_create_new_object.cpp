#include "traverse_create_new_object.h"
#include "traverse_create_new.h"
#include "game.h"

extern Game *game;

Traverse_Create_New_Object::Traverse_Create_New_Object(QObject *parent) : QObject (parent) {}

Traverse_Create_New_Object::Traverse_Create_New_Object(int value, int x, int y, int object)
        : id_colour(value), x_pos(x), y_pos(y), object_number(object){

    is_save = false;

}

void Traverse_Create_New_Object::set_scene(){

    game->scene->addItem(&picture);
    ProxyWidget = game->scene->addWidget(&text);
    ProxyWidget = game->scene->addWidget(&save_button);
    ProxyWidget = game->scene->addWidget(&update_button);

    update_button.hide();

    QPointer <Traverse_Create_new> traverse;

    connect(&save_button, &QPushButton::clicked, traverse, [=](){ traverse->save_changes(); } );

    connect(&text, &QTextEdit::selectionChanged, this, [=](){

        if(is_save){

            update_button.show();

            connect(&update_button, &QPushButton::clicked, traverse, [=]{ traverse->update(object_number); } );
        }

    } );

}

void Traverse_Create_New_Object::set_buttons(){

    // Add picture of card
    picture.setPixmap(picture.setImageVeryHardNeutral(id_colour));
    picture.setScale(0.85);
    picture.setPos(x_pos, y_pos);


    // Create fild with text edit
    text.move(x_pos + 120, y_pos + 20);
    text.resize(350,100);


    // Create button with save options
    save_button.setText("Save");
    save_button.move(x_pos + 20, y_pos + 50);


    // Create button with update options
    update_button.setText("Update");
    update_button.move(x_pos + 40, y_pos + 50);
    update_button.hide();

}
