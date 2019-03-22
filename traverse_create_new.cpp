#include "traverse_create_new.h"
#include "game.h"
#include "traverse.h"
#include "database.h"

#include <QDebug>

extern Game *game;

Traverse_Create_new::Traverse_Create_new(QObject *paretn) : QObject (paretn){
    counter = 0;
}



void Traverse_Create_new::Learn(int value){

    which_graphic(value);
    game->scene->clear();

    // Create back button
    QPointer <Traverse> traverse = new Traverse;
    QPointer <Graphic_others> buttonBack = new Graphic_others;
    buttonBack->setPixmap(buttonBack->setImageOthers(1));
    buttonBack->setPos(20, 20);
    game->scene->addItem(buttonBack);
    connect(buttonBack, &Graphic_others::clicked, traverse, [=](){ traverse->Add_New_Menu(); } );

    create_objects();

}



void Traverse_Create_new::which_graphic(int value){

    // Chose the group of cards to learning
    if(value == 0)      group_card = 13;
    else if(value == 1) group_card = 26;
    else if(value == 2) group_card = 39;
    else if(value == 3) group_card = 52;
}





void Traverse_Create_new::save_changes(int colour){

    int id_card = 10;
    description = list_object[counter]->text.toPlainText();

    DataBase db;
    db.insert("INSERT INTO user_cards (colour, id_card, description) "
              "VALUES (" + QString::number(colour) + ", " + QString::number(id_card) + ", \"" + description + "\" );");

    list_object[counter]->save_button.hide();
    is_save = true;
    counter++;

//    if( ! disconnect(save_button, nullptr, this, nullptr) )
//        qDebug() << "Disconnect save is broken - Traverse_Create_new::save_changes(int, QString)";

}





void Traverse_Create_new::update(int id_card){

    description = list_object[counter]->text.toPlainText();

    DataBase db;
    db.select("UPDATE user_cards SET description = \"" + description + "\" WHERE id = " + QString::number(id_card) + ";" );

    list_object[counter]->update_button.hide();

    //if( ! disconnect(update_button, nullptr, this, nullptr) )
      //  qDebug() << "Disconnect update is broken - Traverse_Create_new::save_changes(int, QString)";

}





void Traverse_Create_new::get_coordinate(int value){

    is_save = false;

    switch (value) {

        case 0:  x_pos = 250;     y_pos = 50;     break;
        case 1:   x_pos = 800;     y_pos = 50;     break;
        case 2:    x_pos = 1300;    y_pos = 50;     break;

        case 3:  x_pos = 250;     y_pos = 230;    break;
        case 4:   x_pos = 800;     y_pos = 230;    break;
        case 5:    x_pos = 1300;    y_pos = 230;    break;

        case 6:  x_pos = 250;     y_pos = 410;    break;
        case 7:   x_pos = 800;     y_pos = 410;    break;
        case 8:    x_pos = 1300;    y_pos = 410;    break;

        case 9:  x_pos = 250;     y_pos = 590;    break;
        case 10:  x_pos = 800;    y_pos = 590;    break;
        case 11:   x_pos = 1300;   y_pos = 590;    break;

        case 12: x_pos = 800;    y_pos = 770;    break;

    }

}

void Traverse_Create_new::create_objects(){

    int x_pos = 0, y_pos = 0;

    for(int i = group_card - 13; i < group_card; ++i){

        get_coordinate(i);

        object = new Traverse_Create_New_Object(i, x_pos, y_pos);
        list_object.append(object);

    }
}

