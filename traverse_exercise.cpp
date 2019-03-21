#include "traverse_exercise.h"
#include "game.h"

#include <QDebug>

extern Game *game;

Traverse_exercise::Traverse_exercise(QObject *parent) : QObject (parent) {

}


void Traverse_exercise::Exercise(){ // TODO Move to other class
    qDebug() << "in exercose";
}


