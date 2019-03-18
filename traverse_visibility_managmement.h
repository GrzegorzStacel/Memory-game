#ifndef TRAVERSE_VISIBILITY_MANAGMEMENT_H
#define TRAVERSE_VISIBILITY_MANAGMEMENT_H

#include "database.h"
#include "mainbuttons.h"

#include <QObject>

class Traverse_visibility_managmement : public QObject {
   Q_OBJECT

public:
    // Constructors
    Traverse_visibility_managmement();


    // Public Attributes
    DataBase *db;
    MainButtons *adds_new, *exercise, *back;

    // Public Methods
    void showMenu();

private:
    // Private Attributes
    bool isMenu;
    int isNew;



public slots:
    void Add_New();
    void Exercise();
};

#endif // TRAVERSE_VISIBILITY_MANAGMEMENT_H
