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
    explicit Traverse_Create_New(Traverse &obj, QObject *parent = nullptr);

    // Public Attributes
    void Learn(int x);

    // Public Methods

    void update(int obj_number);

private:
    // Private Methods
    void connect_save_button();
    void cleaning_before_back(Traverse &Traverse_Object);

    // Private Attributes
    QPointer< Traverse_Create_New_Object> object;
    QString actual_description;
    int x_pos, y_pos;
    int activ_object;

protected:
    // Protected Attributes
    QList< QPointer <Traverse_Create_New_Object> > list_object;

    QPointer< Traverse > Traverse_Object;
    DataBase db;
    int number_of_colour;
    int group_card;
    int counter;
    QString description;

    // Protected Methods
    void which_graphic();
    void get_coordinate(int value);
    void back_button(int number_of_image);
    void create_objects();
    void update_pack_of_cards();
    void save_changes(int counter);

};

#endif // TRAVERSE_CREATE_NEW_H
