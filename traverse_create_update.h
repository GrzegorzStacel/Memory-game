#ifndef TRAVERSE_CREATE_UPDATE_H
#define TRAVERSE_CREATE_UPDATE_H

#include "traverse_create_new.h"

#include <QObject>

class Traverse_Create_Update : public Traverse_Create_New {
    Q_OBJECT

public:
    // Constructors
    Traverse_Create_Update(Traverse &obj);

    // Public Methods
    void update_start(int value);
};

#endif // TRAVERSE_CREATE_UPDATE_H
