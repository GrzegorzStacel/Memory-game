#include "traverse.h"
#include "game.h"
#include "traverse_create_new.h"
#include "traverse_create_continue.h"
#include "traverse_create_update.h"

#include <QDebug>

extern Game *game;

Traverse::Traverse(QObject *parent) : QObject (parent){

    // Checks whether the user has created associations for some color from the cards
    if(db.select("SELECT pack_of_cards FROM user_settings WHERE id = 1").toInt() == 0)
        isMenu = false;
    else
        isMenu = true;

}


void Traverse::showMenu(){

    update();

    int y_pos = 600;
    game->scene->clear();

    // create the Add New Deck Of Cards button
    adds_new = new MainButtons(QString("Manager"));
    double bxPos = game->width()/2 - adds_new->boundingRect().width()/2;
    adds_new->setPos(bxPos,400);
    connect(adds_new, &MainButtons::clicked, this, [=](){ this->Add_New_Menu(); } );
    game->scene->addItem(adds_new);

    // create the Polygon For Memorization button
    traverse_exer = new Traverse_exercise;
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
    connect(back, &MainButtons::clicked, game, [=](){ game->displayMainMenu(); } );
    game->scene->addItem(back);

    }

void Traverse::Add_New_Menu(){

    update();
    game->scene->clear();

    // Create back button
    QPointer <Graphic_others> buttonBack = new Graphic_others;
    buttonBack->setPixmap(buttonBack->setImageOthers(1));
    buttonBack->setPos(20, 20);
    game->scene->addItem(buttonBack);
    connect(buttonBack, &Graphic_others::clicked, this, [=](){  this->showMenu();
                                                                ListOfCards.clear(); } );

    QPointer <Graphic_others> guide = new Graphic_others;
    guide->setPixmap(guide->setImageOthers(13));
    guide->setPos(1400, 750);
    game->scene->addItem(guide);


    connections();


    int x_pos = 450;

    for (int i = 13, n = 0; n <= isNew; ++n, i+=13) {

        if( n == 4 ){
            ListOfCards[n-1]->Picture_Correct( i - 14, true);
            break;

        } else if( n < isNew ){
            ListOfCards[n]->Picture_Correct( i - 1, true);

        } else
            ListOfCards[n]->Picture_Neutral( i - 1, true);


        ListOfCards[n]->setPos(x_pos += 200, 400);
        game->scene->addItem(ListOfCards[n]);

    }

}

void Traverse::clear(){

    ListOfCards.clear();

}

void Traverse::connections(){

    QPointer <Traverse_Create_New> create = new Traverse_Create_New( *this );
    QPointer <Traverse_Create_Continue> continues = new Traverse_Create_Continue( *this );
    QPointer <Traverse_Create_Update> update = new Traverse_Create_Update( *this );
    int is_finish = 0;

    for(int i = 0, k = 13; i <= isNew; k += 13, ++i) {

        bool tmp_judge_complete = true, tmp_judge_continues = true;

        if(i == 4) break;

        is_finish = db.select("SELECT SUM(is_it_saved) FROM user_cards "
                              "WHERE id_card >= " + QString::number(k - 13) + " AND id_card <= " + QString::number(k - 1) + ";").toInt();

        cards = new Cards;
        ListOfCards.append(cards);

        if( is_finish == 13 )
            tmp_judge_complete = false;

        if( is_finish >= 1 )
            tmp_judge_continues = false;


        if(i == isNew && tmp_judge_complete && !tmp_judge_continues)
            connect(cards, &Cards::clicked, create, [=](){ continues->continue_start( i ); } );

        else if( i == isNew && tmp_judge_complete && tmp_judge_continues)
            connect(cards, &Cards::clicked, create, [=](){ create->Learn( i ); } );

        else
            connect(cards, &Cards::clicked, create, [=](){ update->update_start( i ); } );
    }
}

void Traverse::update(){

    // Gets the number of well-known user-color cards
    isNew = db.select("SELECT pack_of_cards FROM user_settings WHERE id = 1").toInt();
}


