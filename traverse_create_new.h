#ifndef TRAVERSE_CREATE_H
#define TRAVERSE_CREATE_H


#include <QObject>

class Traverse_Create_new : public QObject {
    Q_OBJECT

public:
    // Constructors
    Traverse_Create_new();

    // Public Attributes
    void Learn(int x);

};

#endif // TRAVERSE_CREATE_H
