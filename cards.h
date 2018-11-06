#ifndef CARDS_H
#define CARDS_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QObject>
#include <QDebug>
class Cards : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:

    // constructors
    Cards();
    Cards(bool isActive);

    // public methods
    int getRandomNubmer(int x) { return RandomNumbers[x]; }
    QString setImage(int number);
    QString setImageWrong(int number);
    QString setImageCorrect(int number);
    QString setActive(bool foo);
    void generatorOfRandomNumbers();

    inline void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }

private:

    //private attributes
    static int RandomNumbers[13];

    // private methods
    bool IfItWasDrawn( int number, int selectedAtRandom );

signals:
    void clicked();
};

#endif // CARDS_H
