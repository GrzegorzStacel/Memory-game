#ifndef GRAPHIC_CARDS_H
#define GRAPHIC_CARDS_H

#include <QString>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QObject>
#include <QDebug>

class graphic_cards : public QObject, public QGraphicsPixmapItem{

public:
    // Constructors
    graphic_cards(QObject *parent = nullptr);

    // public methods
    QString setImageRegularNeutral(int number);
    QString setImageRegularWrong(int number);
    QString setImageRegularCorrect(int number);

    QString setImageVeryHardNeutral(int number);
    QString setImageVeryHardWrong(int number);
    QString setImageVeryHardCorrect(int number);

    QString setActive(bool side, bool lvl);

};

#endif // GRAPHIC_CARDS_H
