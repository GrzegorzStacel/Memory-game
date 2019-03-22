#include "traverse_create_new.h"
#include "game.h"
#include "traverse.h"
#include "database.h"

#include <QDebug>
#include <QString>

extern Game *game;

Traverse_Create_new::Traverse_Create_new(QObject *paretn) : QObject (paretn){
    counter = 0;
}



void Traverse_Create_new::Learn(int value){

    number_of_colour = value;

    which_graphic();
    game->scene->clear();

    // Create back button
    QPointer <Traverse> traverse = new Traverse;
    QPointer <Graphic_others> buttonBack = new Graphic_others;
    buttonBack->setPixmap(buttonBack->setImageOthers(1));
    buttonBack->setPos(20, 20);
    game->scene->addItem(buttonBack);
    connect(buttonBack, &Graphic_others::clicked, traverse, [=](){ traverse->Add_New_Menu(); } );


    create_objects();

    list_object[counter]->start();

}



void Traverse_Create_new::which_graphic(){

    // Chose the group of cards to learning
    if(number_of_colour == 0)      group_card = 13;
    else if(number_of_colour == 1) group_card = 26;
    else if(number_of_colour == 2) group_card = 39;
    else if(number_of_colour == 3) group_card = 52;
}





void Traverse_Create_new::save_changes(){
qDebug() << "Save";
    QString id_card = QString::number( list_object[counter]->get_id_colour() );
    description = list_object[counter]->text.toPlainText();

    DataBase db;
    db.insert("INSERT INTO user_cards (colour, id_card, description) "
              "VALUES (" + QString::number(number_of_colour) + ", " + id_card + ", \"" + description + "\" );");

    list_object[counter]->save_button_hide();
    list_object[counter]->set_is_save(true);

    counter++;

    list_object[counter]->start();

//    if( ! disconnect(save_button, nullptr, this, nullptr) )
//        qDebug() << "Disconnect save is broken - Traverse_Create_new::save_changes(int, QString)";

}





void Traverse_Create_new::update(int obj_number){
qDebug() << "Update";
    QString id_card_ = QString::number( list_object[counter]->get_id_colour() );
    description = list_object[counter]->text.toPlainText();

    DataBase db;
    db.select("UPDATE user_cards SET description = \"" + description + "\" WHERE id = " + id_card_ + ";" );

    list_object[obj_number]->update_button.hide();

    //if( ! disconnect(update_button, nullptr, this, nullptr) )
      //  qDebug() << "Disconnect update is broken - Traverse_Create_new::save_changes(int, QString)";

}





void Traverse_Create_new::get_coordinate(int value){


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

    int x_pos = 0, y_pos = 0, obj_number = 0;

    for(int i = group_card - 13; i < group_card; ++i){

        get_coordinate(i);

        object = new Traverse_Create_New_Object(i, x_pos, y_pos, obj_number);
        list_object.append(object);

        obj_number++;

    }
}

