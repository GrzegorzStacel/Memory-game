#include "drawgui.h"
#include "timer.h"
#include "game.h"


extern Game *game;

drawGUI::drawGUI(){

    gameOver = new game_over();

    // Draw rectagne for the timer
    //gameOver->drawPanel(15, 15, 110, 60, "yellow", 1);

}
