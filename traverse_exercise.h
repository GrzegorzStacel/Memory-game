#ifndef TRAVERSE_EXERCISE_H
#define TRAVERSE_EXERCISE_H

#include "cards.h"
#include "traverse_create_new.h"

#include <QGraphicsPixmapItem>
#include <QObject>

class Traverse_exercise : public QObject, public QGraphicsPixmapItem{
   Q_OBJECT

public:
    // Constructors
    Traverse_exercise(QObject *parent = nullptr);

public slots:
    void Exercise();
};

#endif // TRAVERSE_EXERCISE_H
