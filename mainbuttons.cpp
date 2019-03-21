#include "mainbuttons.h"
#include "game.h"

#include <QBrush>
#include <QGraphicsTextItem>
#include <QFont>

extern Game *game;

MainButtons::MainButtons(QString name, int x, int y, QGraphicsItem *parent) : QGraphicsRectItem(parent){


    // draw the rect
    drawRect(x,y);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name, this);
    double xPos = rect().width()/3 - text->boundingRect().width()/3;
    double yPos = rect().height()/3 - text ->boundingRect().height()/3;
    QFont titleFont("comic sans", 15);
    text->setFont(titleFont);
    text->setPos(xPos, yPos);

    // allow responding to hover events
    setAcceptHoverEvents(true);

}

void MainButtons::drawRect(int x, int y){
    setRect(0,0,x,y);
}

void MainButtons::hoverEnterEvent(QGraphicsSceneHoverEvent *){
    // change color to cyan
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void MainButtons::hoverLeaveEvent(QGraphicsSceneHoverEvent *){
    // change color to dark cyan
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}

void MainButtons::handleClickWrong(){

    QPointer <DrawCards> draw = new DrawCards;
    emit buttonClickedWrong(draw->getVariableForChooseImage());
}

void MainButtons::handleClickCorrect(){

    QPointer <DrawCards> draw = new DrawCards;
    emit buttonClickedCorrect(draw->getVariableForChooseImage());
}
