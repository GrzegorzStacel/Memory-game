#ifndef TRAVERSE_CREATE_CONTINUE_H
#define TRAVERSE_CREATE_CONTINUE_H

#include "traverse_create_new.h"

#include <QObject>

class Traverse_Create_Continue : public Traverse_Create_New {
    Q_OBJECT

public:
    // Constructors
    Traverse_Create_Continue(Traverse &obj);

    // Public Methods
    void continue_start(int value);


private:
    // Private attributes
    void add_description();
    void connect_save_button();
    void save_changes();
    void how_many_save();

    DataBase db;

    // Private Attributes
    int sum_is_it_save_from_db;


};

#endif // TRAVERSE_CREATE_CONTINUE_H
