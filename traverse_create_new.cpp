#include "traverse_create_new.h"
#include "game.h"

#include <QPushButton>
#include <QDebug>
#include <QString>

extern Game *game;

Traverse_Create_New::Traverse_Create_New(Traverse &obj, QObject *parent) : QObject (parent) {

    counter = 0;
    Traverse_Object = &obj;
}

void Traverse_Create_New::Learn(int value){

    number_of_colour = value;

    which_graphic();
    game->scene->clear();

    // Add the back button
    back_button(1);

    create_objects();

    // Show first group of elements
    list_object[counter]->start();
    connect_save_button();

}

void Traverse_Create_New::which_graphic(){

    // Chose the group of cards to learning
    if(number_of_colour == 0)      group_card = 13;
    else if(number_of_colour == 1) group_card = 26;
    else if(number_of_colour == 2) group_card = 39;
    else if(number_of_colour == 3) group_card = 52;
}

void Traverse_Create_New::save_changes(){

    QString id_card = QString::number( list_object[counter]->get_id_colour() );
    description = list_object[counter]->text.toPlainText();

    int id_card_to_update = (group_card + counter) - 12;

    db.insert("UPDATE user_cards SET description = \"" + description + "\", is_it_saved = " + QString::number(0) +
              " WHERE id = " + QString::number(id_card_to_update) + " AND is_it_saved = 0 AND colour = " + QString::number(number_of_colour) +
              " AND id_card = " + id_card + ";");


    list_object[counter]->save_button_hide();
    list_object[counter]->set_is_save(true);

    if( counter < 12){

        counter++;

        list_object[counter]->start();
        connect_save_button();

        if( counter == 12 ) {

            {
                int check = db.select("SELECT pack_of_cards FROM user_settings WHERE id = 1;").toInt();

                if( check <= 4 )
                    db.insert("UPDATE user_settings SET pack_of_cards = " + QString::number(++check) + " WHERE id = 1;");

            }            
        }
    }
}


void Traverse_Create_New::update(int obj_number){

    description = list_object[obj_number]->text.toPlainText();

    int show_id_card = (group_card - 13) + obj_number;

    db.select("UPDATE user_cards SET description = \"" + description + "\" "
              "WHERE id_card = " + QString::number(show_id_card) + " AND colour = " + QString::number(number_of_colour) + " ;" );

    list_object[obj_number]->update_button.hide();
    list_object[counter]->text.setFocus();

}

void Traverse_Create_New::get_coordinate(int value){

    switch (value) {

        case 0:  x_pos = 250;     y_pos = 50;   break;
         case 1:  x_pos = 800;     y_pos = 50;   break;
          case 2:  x_pos = 1300;    y_pos = 50;   break;

        case 3:  x_pos = 250;     y_pos = 230;    break;
         case 4:   x_pos = 800;    y_pos = 230;    break;
          case 5:   x_pos = 1300;   y_pos = 230;    break;

        case 6:  x_pos = 250;     y_pos = 410;    break;
         case 7:  x_pos = 800;     y_pos = 410;    break;
          case 8:  x_pos = 1300;    y_pos = 410;    break;

        case 9:  x_pos = 250;     y_pos = 590;    break;
         case 10: x_pos = 800;     y_pos = 590;    break;
          case 11: x_pos = 1300;    y_pos = 590;    break;

        case 12: x_pos = 800;    y_pos = 770;    break;

    }

}

void Traverse_Create_New::create_objects(){

    int object_number = 0;

    for(int j = 0, i = group_card - 13; i < group_card; ++j, ++i){

        get_coordinate(j);


        object = new Traverse_Create_New_Object(i, x_pos, y_pos, object_number);
        list_object.append(object);

        text = new QTextEdit();
        list_text.append(text);


        object_number++;

        connect( & list_object[j]->text, &QTextEdit::selectionChanged, this, [=](){


                    connect( & list_object[j]->text, &QTextEdit::textChanged, this, [=](){

                        if( list_object[j]->get_is_save() )
                                list_object[j]->update_button.show(); } );


                    connect( & list_object[j]->update_button, &QPushButton::clicked, this, [=](){ this->update(j); } );

        } );
    }
}

void Traverse_Create_New::connect_save_button(){
    if( counter < 12 )
        connect( & list_object[counter]->save_button, &QPushButton::clicked, this, [=](){ this->save_changes(); } );
    else
        connect( & list_object[12]->save_button, &QPushButton::clicked, this, [&]() { this->save_changes(); this->back_button(12); });
}

void Traverse_Create_New::back_button(int number_of_image){

    // Create back button
    QPointer <Traverse> traverse = new Traverse;
    QPointer <Graphic_others> buttonDone = new Graphic_others;
    buttonDone->setPixmap(buttonDone->setImageOthers(number_of_image));
    buttonDone->setPos(20, 20);
    game->scene->addItem(buttonDone);
    connect(buttonDone, &Graphic_others::clicked, Traverse_Object, [=](){ this->cleaning_before_back(*Traverse_Object); } );

}

void Traverse_Create_New::cleaning_before_back(Traverse &Traverse_Object){

    for (int i = 0; i <= counter; ++i) {

        list_object[i]->clear();
    }

    Traverse_Object.clear();
    Traverse_Object.Add_New_Menu();

}


