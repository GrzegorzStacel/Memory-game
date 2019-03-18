#include "cards_position.h"

Cards_Position::Cards_Position(){

}

void Cards_Position::select_lvl(int level){

    if( level== 13 )
        placeCardsEasy(475, 650, level);
    if( level == 26 )
        placeCardsMedium(120, 720, level);
    if( level == 39 )
        placeCardsHard(5, 740, level);
    if( level == 52 )
        placeCardsHardcore(70, 790, level);
}


void Cards_Position::placeCardsEasy(int x, int y, int cards){

    int X_SHIFT = 0;
    int Y_SHIFT = 0;
    bool isActive = false; // this variable is used by the constructor as the card argument in (this->) createBoard method

    for( int i = 0, n = cards; i < n; i++){

        if( i == 0 )
            isActive = true;
        else
            isActive = false;

        if( i % 3 == 0 && i != 6 ) // distance from triples
            X_SHIFT += 100;

        else if( i % 6 == 0 || i % 12 == 0 ){ // new row
            X_SHIFT = 0;
            Y_SHIFT -= 250;
        }

        if( i == 0 || i == 6) // distance of first cards from the left side
            X_SHIFT = 50;
        else // distance from cards (inside triples)
            X_SHIFT += 150;

        if( i == 12 ){ // distance in third row (last card)
            X_SHIFT = 475;
            Y_SHIFT -= 250;
        }

        x_position.append(x + X_SHIFT);
        y_position.append(y + Y_SHIFT);
        Active.append(isActive);
    }

        Which_Card = true;
}

void Cards_Position::placeCardsMedium(int x, int y, int cards){

    int X_SHIFT = 0;
    int Y_SHIFT = 0;
    bool isActive = false; // this variable is used by the constructor as the card argument in (this->) createBoard method

    for( int i = 0; i < cards; i++){

        if( i == 0 )
            isActive = true;
        else
            isActive = false;


        if( i % 3 == 0 && i != 9 && i != 18 && i != 24 ) // distance from triples
            X_SHIFT += 100;

        else if( i == 9 || i == 18 || i == 24 ){ // new row
            X_SHIFT = 0;
            Y_SHIFT -= 230;
        }


        if( i == 0 || i == 9  ) // distance of first cards from the left side
            X_SHIFT = 50;
        else // distance from cards (inside triples)
            X_SHIFT += 150;


        if( i == 18 ) // distance in third row
            X_SHIFT = 325;

        else if( i == 24 ) // distance in fourth row
            X_SHIFT = 670;


        x_position.append(x + X_SHIFT);
        y_position.append(y + Y_SHIFT);
        Active.append(isActive);
    }

        Which_Card = true;
}

void Cards_Position::placeCardsHard(int x, int y, int cards){

    int X_SHIFT = 0;
    int Y_SHIFT = 0;
    bool isActive = false; // this variable is used by the constructor as the card argument in (this->) createBoard method

    for( int i = 0; i < cards; i++){

        if( i == 0 )
            isActive = true;
        else
            isActive = false;


        if( i % 3 == 0 && i != 12 && i != 24 && i != 36) // distance from triples
            X_SHIFT += 40;

        else if( i == 12 || i == 24 || i == 36 ){ // new row
            X_SHIFT = 0;
            Y_SHIFT -= 230;
        }


        if( i == 0 || i == 12 || i == 24 ) // distance of first cards from the left side
            X_SHIFT = 30;
        else // distance from cards (inside triples)
            X_SHIFT += 145;


        if( i == 36 ) // distance in fourth row
            X_SHIFT = 730;


        x_position.append(x + X_SHIFT);
        y_position.append(y + Y_SHIFT);
        Active.append(isActive);
    }

        Which_Card = true;
}

void Cards_Position::placeCardsHardcore(int x, int y, int cards){

    int X_SHIFT = 0;
    int Y_SHIFT = 0;
    bool isActive = false; // this variable is used by the constructor as the card argument in (this->) createBoard method

    for( int i = 0; i < cards; i++){

        if( i == 0 )
            isActive = true;
        else
            isActive = false;


        if( i % 3 == 0 && i != 12 && i != 24 && i != 36 && i != 48) // distance from triples
            X_SHIFT += 40;

        else if( i == 12 || i == 24 || i == 36 || i == 48){ // new row
            X_SHIFT = 0;
            Y_SHIFT -= 190;
        }


        if( i == 0 || i == 12 || i == 24 || i == 36) // distance of first cards from the left side
            X_SHIFT = 30;
        else // distance from cards (inside triples)
            X_SHIFT += 135;


        if( i == 48 ) // distance in fourth row
            X_SHIFT = 630;


        x_position.append(x + X_SHIFT);
        y_position.append(y + Y_SHIFT);
        Active.append(isActive);
    }

        Which_Card = false;
}

