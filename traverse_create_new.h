#ifndef TRAVERSE_CREATE_H
#define TRAVERSE_CREATE_H

#include "graphic_cards.h"
#include "graphic_others.h"
#include "traverse_create_new_object.h"

#include <QObject>
#include <QTextEdit>
#include <QPushButton>
#include <QPointer>


class Traverse_Create_new : public QObject {
    Q_OBJECT

public:
    // Constructors
    Traverse_Create_new(QObject *parent = nullptr);

    // Public Attributes
    void Learn(int x);


    // Public Methods
    void save_changes();
    void update(int obj_number);


private:
    // Private Methods
    void which_graphic();
    void get_coordinate(int value);
    void create_objects();

    // Pribate Attributes
    QPointer< Traverse_Create_New_Object> object;
    QList< QPointer <Traverse_Create_New_Object> > list_object;

    QString description;
    int group_card;
    int counter;
    int x_pos, y_pos;
    int number_of_colour;








};

#endif // TRAVERSE_CREATE_H
