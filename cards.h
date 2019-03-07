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
    Cards(bool isActive, bool lvl);

    // public methods
    QString setImageRegularNeutral(int number);
    QString setImageRegularWrong(int number);
    QString setImageRegularCorrect(int number);

    QString setImageVeryHardNeutral(int number);
    QString setImageVeryHardWrong(int number);
    QString setImageVeryHardCorrect(int number);

    QString setActive(bool side, bool lvl);

    inline void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }

signals:

    //signals
    void clicked();

};

#endif // CARDS_H
