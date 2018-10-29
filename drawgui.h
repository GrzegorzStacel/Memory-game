#ifndef DRAWGUI_H
#define DRAWGUI_H

#include "game_over.h"



#include <QGraphicsTextItem>



class drawGUI{
public:

    // constructors
    drawGUI();

    // public attributes
    game_over *gameOver;
    QGraphicsTextItem *drawTime;

};

#endif // DRAWGUI_H
