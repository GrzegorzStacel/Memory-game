#include "traverse.h"
#include "game.h"

#include <QDebug>

extern Game *game;

Traverse::Traverse(){

    // Checks whether the user has created associations for some color from the cards
    if(db->select("SELECT pack_of_cards FROM user_settings WHERE id = 1").toInt() == 0)
        isMenu = false;
    else
        isMenu = true;


    // Gets the number of well-known user-color cards
    isNew = db->select("SELECT new_pack_of_cards FROM user_settings WHERE id = 1").toInt();

}


void Traverse::showMenu(){

    int y_pos = 600;
    game->scene->clear();

    // create the Add New Deck Of Cards button
    adds_new = new MainButtons(QString("Add new"));
    double bxPos = game->width()/2 - adds_new->boundingRect().width()/2;
    adds_new->setPos(bxPos,400);
    connect(adds_new, &MainButtons::clicked, this, [=](){ this->Add_New_Menu(); } );
    game->scene->addItem(adds_new);

    // create the Polygon For Memorization button
    traverse_exer = new Traverse_exercise();
    exercise = new MainButtons(QString("Your Deck"));
    exercise->setPos(bxPos,500);
    connect(exercise, SIGNAL(clicked()), traverse_exer, SLOT(Exercise()));

    // Checks whether the user has already created his first batch of cards, if not the button with the exercises will be hidden
    if(isMenu == false){

        adds_new->setToolTip("Create your first batch of cards to unlock other functionalities");
        y_pos = 500;

    }
    else
        game->scene->addItem(exercise);


    // create the back button to main menu
    back = new MainButtons(QString("Back"));
    back->setPos(bxPos,y_pos);
    connect(back, SIGNAL(clicked()), game, SLOT(displayMainMenu()));
    game->scene->addItem(back);

    }

void Traverse::Add_New_Menu(){

    game->scene->clear();

    // Create back button
    Graphic_others *buttonBack = new Graphic_others();
    buttonBack->setPixmap(buttonBack->setImageOthers(1));
    buttonBack->setPos(20, 20);
    game->scene->addItem(buttonBack);
    connect(buttonBack, SIGNAL(clicked()), this, SLOT(showMenu()));


    create = new Traverse_Create_new();

    for (int i = 0; i < isNew; ++i) {
        cards = new Cards();
        connect(cards, &Cards::clicked, create, [=](){ create->Learn(i); } );
        ListOfCards.append(cards);
    }


    int x_pos = 450;

    for (int i = 13, n = 0; n < isNew; ++n, i+=13) {

        ListOfCards[n]->Picture_Neutral( i - 1, true);
        ListOfCards[n]->setPos(x_pos += 200, 400);
        game->scene->addItem(ListOfCards[n]);

    }

}


