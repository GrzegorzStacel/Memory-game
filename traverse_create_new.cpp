#include "traverse_create_new.h"
#include "game.h"
#include "traverse.h"
#include "database.h"

#include <QDebug>

extern Game *game;

Traverse_Create_new::Traverse_Create_new(QObject *paretn) : QObject (paretn){

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


    add_button(group_card - 13, 250, 50);
//    add_button(group_card - 12, 800, 50);
//    add_button(group_card - 11, 1300, 50);

//    add_button(group_card - 10, 250, 230);
//    add_button(group_card - 9, 800, 230);
//    add_button(group_card - 8, 1300, 230);

//    add_button(group_card - 7, 250, 410);
//    add_button(group_card - 6, 800, 410);
//    add_button(group_card - 5, 1300, 410);

//    add_button(group_card - 4, 250, 590);
//    add_button(group_card - 3, 800, 590);
//    add_button(group_card - 2, 1300, 590);

//    add_button(group_card - 1, 800, 770);

    bool change = false;

    // Create fild with text edit
    list_text.append( text  = new QTextEdit("My") );
    text->move(370,70);
    text->resize(350,100);
    pProxyWidget = game->scene->addWidget(text);



    connect(text, &QTextEdit::textChanged, this, [&](){ change = true;     save_button->show(); } );

    QString description = text->toPlainText();


    // Create button with save option
    save_button = new QPushButton("Save");
    save_button->move(380, 180);
    pProxyWidget = game->scene->addWidget(save_button);
    connect(save_button, &QPushButton::clicked, this, [=](){ this->save_changes(value, description); } );



}

void Traverse_Create_new::add_button(int value, int x_pos, int y_pos){

    QPointer <graphic_cards> picture = new graphic_cards;
    picture->setPixmap(picture->setImageVeryHardNeutral(value));
    picture->setScale(0.85);
    picture->setPos(x_pos, y_pos);
    game->scene->addItem(picture);

}

void Traverse_Create_new::which_graphic(int value){

    // Chose the group of cards to learning
    if(value == 0)      group_card = 13;
    else if(value == 1) group_card = 26;
    else if(value == 2) group_card = 39;
    else if(value == 3) group_card = 52;
}

void Traverse_Create_new::save_changes(int colour, QString description){

    int id_card = 10;

    DataBase db;
    db.insert("INSERT INTO user_cards (colour, id_card, description) "
              "VALUES (" + QString::number(colour) + ", " + QString::number(id_card) + ", \"" + description + "\" );");

    save_button->hide();
}

void Traverse_Create_new::update(QString description){

    qDebug() << "update";
}

