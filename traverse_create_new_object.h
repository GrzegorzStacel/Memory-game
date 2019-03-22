#ifndef TRAVERSE_CREATE_NEW_OBJECT_H
#define TRAVERSE_CREATE_NEW_OBJECT_H

#include "graphic_cards.h"
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QPointer>
#include <QObject>

class Traverse_Create_New_Object : public QObject {
    Q_OBJECT

public:
    // Constructors
    Traverse_Create_New_Object(QObject *parent = nullptr);
    Traverse_Create_New_Object(int value, int x, int y);

    // Public Attributes
    graphic_cards picture;
    QPushButton save_button, update_button;
    QTextEdit text;

    QGraphicsProxyWidget *ProxyWidget;

private:
    // Private Methods
    void set_buttons();

    // Private Attributes
    int id_colour;
    int x_pos;
    int y_pos;
};

#endif // TRAVERSE_CREATE_NEW_OBJECT_H
