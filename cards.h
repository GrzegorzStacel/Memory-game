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
    void VisualizeCards(int=0, int=0);

    Cards *cards[13];
    QGraphicsScene *scene;
};

#endif // CARDS_H
