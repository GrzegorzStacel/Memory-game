#ifndef TRAVERSE_CREATE_CONTINUE_H
#define TRAVERSE_CREATE_CONTINUE_H

#include "traverse_create_new.h"

#include <QObject>

class Traverse_Create_Continue : public Traverse_Create_New {
    Q_OBJECT

public:
    // Constructors
    Traverse_Create_Continue(Traverse &obj);
    void continue_start(int value);

private:
    // Private attributes
    void add_description();
    void connect_save_button();
    void save_changes();

    DataBase db;


};

#endif // TRAVERSE_CREATE_CONTINUE_H
