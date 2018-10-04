#include "mainbuttons.h"

#include <QFont>
#include <QPoint>

MainButtons::MainButtons()
{
    // Create the start button in main menu
    setPlainText(QString("Start"));
    setDefaultTextColor("Green");
    setFont(QFont("times", 70, 75));
    setPos(QPoint(500, 200));
    //this->setFlag(QGraphicsTextItem::ItemIsFocusable);
    //this->setFocus();
}
