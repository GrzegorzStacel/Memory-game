#ifndef TRAVERSE_H
#define TRAVERSE_H

#include "mainbuttons.h"
#include "traverse_exercise.h"
#include "database.h"
#include "cards.h"


#include <QObject>
#include <QGraphicsSceneMouseEvent>

class Traverse : public QObject {
    Q_OBJECT

public:
    // Constructors
    Traverse(QObject *parent = nullptr);


    // Public Methods
    void Add_New_Menu();
    inline void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }
    void clear();



private:
    // Private Attributes
    bool isMenu;
    int isNew;


    // Private Object
    DataBase db;
    QPointer <MainButtons> adds_new, exercise, back;
    QPointer <Cards> cards;
    QPointer <Traverse_exercise> traverse_exer;

    QList< QPointer <Cards> > ListOfCards;


public slots:
    void showMenu();

signals:
    void clicked();

};

#endif // TRAVERSE_H
