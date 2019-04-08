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
    void connect_save_button();

    // Private Attributes
    int sum_is_it_save_from_db;

protected:
    // Protected Methods
    void how_many_save();
    void add_description();

};

#endif // TRAVERSE_CREATE_CONTINUE_H
