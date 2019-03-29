#include "traverse_create_new.h"
#include "game.h"
#include "traverse.h"
#include <QPushButton>
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

    connect_object();

}



void Traverse_Create_new::which_graphic(){

    // Chose the group of cards to learning
    if(number_of_colour == 0)      group_card = 13;
    else if(number_of_colour == 1) group_card = 26;
    else if(number_of_colour == 2) group_card = 39;
    else if(number_of_colour == 3) group_card = 52;
}


void Traverse_Create_new::save_changes(){

    QString id_card = QString::number( list_object[counter]->get_id_colour() );
    description = list_object[counter]->text.toPlainText();

    db.insert("INSERT INTO user_cards ( colour, id_card, description) "
              "VALUES (" + QString::number(number_of_colour) + ", " + id_card + ", \"" + description + "\" );");

    list_object[counter]->save_button_hide();
    list_object[counter]->set_is_save(true);

    if( counter < 13){

        counter++;

        list_object[counter]->start();
        connect_object();

    }
}


void Traverse_Create_new::update(int obj_number){
qDebug() << "Update";
    description = list_object[obj_number]->text.toPlainText();

    db.select("UPDATE user_cards SET description = \"" + description + "\" WHERE id_card = " + QString::number(obj_number) + " AND colour = " + QString::number(number_of_colour) + " ;" );

    list_object[obj_number]->update_button.hide();

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

    int obj_number = 0;

    for(int i = group_card - 13; i < group_card; ++i){

        get_coordinate(i);

        object = new Traverse_Create_New_Object(i, x_pos, y_pos, obj_number);
        list_object.append(object);


        text = new QTextEdit();
        list_text.append(text);


        obj_number++;

        connect( & list_object[i]->text, &QTextEdit::selectionChanged, this, [=](){


                    connect( & list_object[i]->text, &QTextEdit::textChanged, this, [=](){

                        if( list_object[i]->get_is_save() )
                                list_object[i]->update_button.show(); } );


                    connect( & list_object[i]->update_button, &QPushButton::clicked, this, [=](){ this->update(i); } );

            qDebug() << "first id colour: " << list_object[i]->get_id_colour(); }




    ); }
}

void Traverse_Create_new::connect_object(){

    connect( & list_object[counter]->save_button, &QPushButton::clicked, this, [=](){ this->save_changes(); } );



//    connect( & list_object[counter]->text, &QTextEdit::selectionChanged, this, [=](){


//        if( counter > 0 ) {

//            for (int i = counter; i >= 0; --i) {

//                actual_description = list_object[i]->text.toPlainText();

//    qDebug() << "Actual : " << actual_description;

//                QString write = db.select("SELECT description FROM user_cards WHERE id = " + QString::number(i+1) + " AND colour = " + QString::number(number_of_colour ) + " ;" );

//    qDebug() << "Write : " << write;

//                if( actual_description == write ){

//                    if( list_object[i]->get_is_save() ) {

//                        list_object[i]->update_button.show();

////                            QString desc;
////                            int in = i;
//                            connect( & list_object[i]->text, &QTextEdit::textChanged, this, [=](){

//                                description = list_object[i]->text.toPlainText();

//                    qDebug() << "desc : " <<  description;

//                            });

//qDebug() << "desc 2: " << description;


//                        connect( & list_object[i]->update_button, &QPushButton::clicked, this, [=]{

//                                                    this->update(i);

//                                                    } );
//                    }//if
//                }//if
//            }//for
//        }//if
//        }//connect
//    );
//}










//        int object_number = list_object[counter]->get_object_number();

//qDebug() << "object number: " << object_number;

//        if( list_object[object_number]->get_is_save() ) {

//qDebug() << "connect is save " << list_object[object_number]->get_is_save() ;

//            list_object[object_number]->update_button.show();

//            connect( & list_object[object_number]->update_button, &QPushButton::clicked, this, [=]{

//                                        this->update(object_number);

//                                        } );

}
