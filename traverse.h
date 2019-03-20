#ifndef TRAVERSE_H
#define TRAVERSE_H

#include "mainbuttons.h"
#include "traverse_exercise.h"
#include "traverse_create_new.h"
#include "database.h"

#include <QObject>
#include <QGraphicsSceneMouseEvent>

class Traverse : public QObject {
    Q_OBJECT

public:
    // Constructors
    Traverse();


    // Public Methods
    void Add_New_Menu();
    inline void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }



private:
    // Private Attributes
    bool isMenu;
    int isNew;


    // Private Object
    DataBase *db;
    MainButtons *adds_new, *exercise, *back;
    QList<Cards *> ListOfCards;
    Cards *cards;
    Traverse_Create_new *create;
    Traverse_exercise *traverse_exer;


public slots:
    void showMenu();

signals:
    void clicked();

};

#endif // TRAVERSE_H
