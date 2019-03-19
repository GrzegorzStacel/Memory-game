#ifndef TRAVERSE_VISIBILITY_MANAGMEMENT_H
#define TRAVERSE_VISIBILITY_MANAGMEMENT_H

#include "database.h"
#include "mainbuttons.h"
#include "cards.h"
#include "traverse_create.h"

#include <QGraphicsPixmapItem>
#include <QObject>

class Traverse_visibility_managmement : public QObject, public QGraphicsPixmapItem{
   Q_OBJECT

public:
    // Constructors
    Traverse_visibility_managmement();

    // Public Methods
    void showMenu();

    inline void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }

private:
    // Private Attributes
    bool isMenu;
    int isNew;

    // Private Attributes
    DataBase *db;
    MainButtons *adds_new, *exercise, *back;
    QList<Cards *> ListOfCards;
    Cards *cards;
    Traverse_Create *create;

signals:
    void clicked();

public slots:
    void Add_New_Menu();
    void Exercise();
};

#endif // TRAVERSE_VISIBILITY_MANAGMEMENT_H
