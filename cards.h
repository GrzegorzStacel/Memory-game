#ifndef CARDS_H
#define CARDS_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QObject>

class Cards : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:

    // constructors
    Cards();
    Cards(bool isActive);

    // public methods
    int getRandomNubmer(int x) { return RandomNumbers[x]; }
    QString setImage(int number);
    QString setActive(bool foo);
    void generatorOfRandomNumbers();

    void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }

private:

    //private attributes
    static int RandomNumbers[13];

    // private methods
    bool IfItWasDrawn( int number, int selectedAtRandom );

signals:
    void clicked();
};

#endif // CARDS_H
