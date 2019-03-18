#ifndef TRAVERSE_H
#define TRAVERSE_H

#include <QObject>

class Traverse : public QObject {
    Q_OBJECT

public:
    // Constructors
    Traverse();


public slots:
    void lets_start();

};

#endif // TRAVERSE_H
