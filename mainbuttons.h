#ifndef MAINBUTTONS_H
#define MAINBUTTONS_H

#include <QGraphicsTextItem>
#include <QKeyEvent>

class MainButtons : public QGraphicsTextItem{
public:
    MainButtons();

    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINBUTTONS_H
