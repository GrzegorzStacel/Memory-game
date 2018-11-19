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
    QString setImageRegularNeutral(int number);
    QString setImageRegularWrong(int number);
    QString setImageRegularCorrect(int number);
    QString setImageVeryHardNeutral(int number);
    QString setImageVeryHardWrong(int number);
    QString setImageVeryHardCorrect(int number);
    QString setImageOptions(int number);
    QString setImageOthers(int number);
    QString setActive(bool foo);
    void generatorOfRandomNumbers(int difficultLvl);

    inline void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }

private:

    //private attributes
    static int RandomNumbers[52];

    // private methods
    bool IfItWasDrawn( int number, int selectedAtRandom );

signals:
    void clicked();
};

#endif // CARDS_H
