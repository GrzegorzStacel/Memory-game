#ifndef TRAVERSE_CREATE_CONTINUE_H
#define TRAVERSE_CREATE_CONTINUE_H

#include "traverse_create_new.h"

#include <QObject>

class Traverse_Create_Continue : public Traverse {
    Q_OBJECT

public:
    // Constructors
    Traverse_Create_Continue(Traverse &obj);
    void continue_start();


};

#endif // TRAVERSE_CREATE_CONTINUE_H
