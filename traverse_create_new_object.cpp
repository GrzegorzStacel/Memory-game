#include "traverse_create_new_object.h"
#include "game.h"

extern Game *game;

Traverse_Create_New_Object::Traverse_Create_New_Object(QObject *parent) : QObject (parent) {}

Traverse_Create_New_Object::Traverse_Create_New_Object(int value, int x, int y, int object)
        : id_colour(value), x_pos(x), y_pos(y), object_number(object) {

    is_save = false;

}

void Traverse_Create_New_Object::set_scene(){

    game->scene->addItem(&picture);
    ProxyWidget = game->scene->addWidget(&text);
    ProxyWidget = game->scene->addWidget(&save_button);
    ProxyWidget = game->scene->addWidget(&update_button);
    picture.setParent(this);

    update_button.hide();

}

void Traverse_Create_New_Object::clear(){

   game->scene->removeItem(text.graphicsProxyWidget());
   game->scene->removeItem(save_button.graphicsProxyWidget());
   game->scene->removeItem(update_button.graphicsProxyWidget());
   game->scene->removeItem(&picture);

}

void Traverse_Create_New_Object::set_buttons(){

    // Add picture of card
    picture.setPixmap(picture.setImageVeryHardNeutral(id_colour));
    picture.setScale(0.85);
    picture.setPos(x_pos, y_pos);


    // Create fild with text edit
    text.setText(description);
    text.move(x_pos + 120, y_pos + 20);
    text.resize(350,100);


    // Create button with save options
    save_button.setText("Save");
    save_button.move(x_pos + 130, y_pos + 125);


    // Create button with update options
    update_button.setText("Update");
    update_button.move(x_pos + 130, y_pos + 125);
    update_button.hide();

}
