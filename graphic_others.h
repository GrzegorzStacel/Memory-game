#ifndef GRAPGHIC_OTHERS_H
#define GRAPGHIC_OTHERS_H
#include <QString>
#include <QObject>
#include <QGraphicsPixmapItem>

class Graphic_others : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    // Constructors
    Graphic_others();

    QString setImageOthers(int number);

    inline void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }

signals:

    //signals
    void clicked();
    void buttonClickedWrong(int);
    void buttonClickedCorrect(int);

private slots:
    void handleClickWrong();
    void handleClickCorrect();
};

#endif // GRAPGHIC_OTHERS_H
