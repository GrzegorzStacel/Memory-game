#ifndef TRAVERSE_H
#define TRAVERSE_H

#include "mainbuttons.h"
#include "traverse_visibility_managmement.h"

#include <QObject>
#include <QGraphicsSceneMouseEvent>

class Traverse : public QObject {
    Q_OBJECT

public:
    // Constructors
    Traverse();

    inline void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }

    // Public Attributes
    Traverse_visibility_managmement *visible;



public slots:
    void traverse_menu();

signals:
    void clicked();
};

#endif // TRAVERSE_H
