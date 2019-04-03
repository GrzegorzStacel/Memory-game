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
    Traverse_Create_New_Object(int value, int x, int y, int object);

    // Public Attributes
    graphic_cards picture;
    QTextEdit text;
    QGraphicsProxyWidget *ProxyWidget;
    QPushButton save_button, update_button;

    // Public Methods
    void set_scene();
    void start() { set_buttons(); set_scene();}
    void clear();

    // getters
    int get_id_colour()     { return id_colour; }
    bool get_is_save()      { return is_save; }
    int get_object_number() { return object_number; }

    // setters
    void set_is_save(bool value){ is_save = value; }

private:
    // Private Methods
    void set_buttons();

    // Private Attributes
    int id_colour;
    int x_pos;
    int y_pos;
    bool is_save;
    int object_number;
    QString description;


};


#endif // TRAVERSE_CREATE_NEW_OBJECT_H
