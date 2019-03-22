#include "traverse_create_new_object.h"
#include "traverse_create_new.h"
#include "game.h"

extern Game *game;

Traverse_Create_New_Object::Traverse_Create_New_Object(QObject *parent) : QObject (parent) {}

Traverse_Create_New_Object::Traverse_Create_New_Object(int value, int x, int y)
        : id_colour(value), x_pos(x), y_pos(y) {

}

void Traverse_Create_New_Object::set_buttons(){

    Traverse_Create_new traverse;

    // Add picture of card

    picture.setPixmap(picture.setImageVeryHardNeutral(id_colour));
    picture.setScale(0.85);
    picture.setPos(x_pos, y_pos);

    game->scene->addItem(&picture);


    // Create fild with text edit
    text.move(x_pos + 120, y_pos + 20);
    text.resize(350,100);

    ProxyWidget = game->scene->addWidget(&text);


    // Create button with save options
    save_button.setText("Save");
    save_button.move(380, 180);
    ProxyWidget = game->scene->addWidget(&save_button);

    connect(save_button, &QPushButton::clicked, traverse, [=](){ traverse.save_changes();} );

    // Create button with update options
    update_button.setText("Update");
    update_button.move(380, 180);
    ProxyWidget = game->scene->addWidget(&update_button);
    update_button.hide();

    connect(text, &QTextEdit::selectionChanged, this, [=](){

        if(is_save){

            update_button.show();

            connect(update_button, &QPushButton::clicked, &traverse, [=]{ &traverse.update(description,10);});
        }

    } );

}
