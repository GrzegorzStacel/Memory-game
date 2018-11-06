#include "mainbuttons.h"
#include "game.h"

#include <QBrush>
#include <QGraphicsTextItem>
#include <QFont>

extern Game *game;

MainButtons::MainButtons(QString name, int x, int y, QGraphicsItem *parent) : QGraphicsRectItem(parent){

    drawRect(x,y);
    // draw the rect
    //setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name, this);
    double xPos = rect().width()/2 - text->boundingRect().width()/2;
    double yPos = rect().height()/2 - text ->boundingRect().height()/2;
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
    // change color to dar cyan
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}

void MainButtons::handleClickWrong(){

    DrawCards *draw = new DrawCards();
    emit buttonClickedWrong(draw->getVariableForChooseImage());
}

void MainButtons::handleClickCorrect(){

    DrawCards *draw = new DrawCards();
    emit buttonClickedCorrect(draw->getVariableForChooseImage());
}
