#ifndef CARDS_H
#define CARDS_H

//#include <QLabel>
#include <QGraphicsTextItem>
#include <QObject>
//#include <QGraphicsView>

class Cards : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

    int foo;
public:
    Cards(int = 0);

    //QGraphicsScene *scene;
};

#endif // CARDS_H
