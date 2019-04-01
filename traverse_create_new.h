#ifndef TRAVERSE_CREATE_NEW_H
#define TRAVERSE_CREATE_NEW_H

#include "graphic_others.h"
#include "database.h"
#include "traverse_create_new_object.h"
#include "traverse.h"

#include <QTextEdit>
#include <QPushButton>
#include <QPointer>
#include <QObject>

class Traverse_Create_New : public QObject {
    Q_OBJECT

public:
    // Constructors
    Traverse_Create_New(QObject *parent = nullptr);

    // Public Attributes
    void Learn(int x, Traverse &object);

    // Public Methods
    void save_changes();
    void update(int obj_number);

private:
    // Private Methods
    void which_graphic();
    void get_coordinate(int value);
    void create_objects();
    void connect_save_button();
    void ending();
    void cleaning_before_back(Traverse &Traverse_Object);

    // Pribate Attributes
    QPointer< Traverse_Create_New_Object> object;
    QList< QPointer <Traverse_Create_New_Object> > list_object;

    QPointer< QTextEdit > text;
    QList< QPointer <QTextEdit> > list_text;
    QPointer< Graphic_others > buttonBack;
    DataBase db;
    QString description;
    QString actual_description;
    int group_card;
    int counter;
    int x_pos, y_pos;
    int number_of_colour;
    int activ_object;

};

#endif // TRAVERSE_CREATE_NEW_H
