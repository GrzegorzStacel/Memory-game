#ifndef TRAVERSE_CREATE_H
#define TRAVERSE_CREATE_H


#include <QObject>

class Traverse_Create : public QObject {
    Q_OBJECT

public:
    // Constructors
    Traverse_Create();

public slots:
    void Learn(int x);

};

#endif // TRAVERSE_CREATE_H
