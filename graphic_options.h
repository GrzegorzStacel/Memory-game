#ifndef GRAPHIC_OPTIONS_H
#define GRAPHIC_OPTIONS_H

#include <QObject>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Graphic_options : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    // Constructors
    Graphic_options();

    // Methods
    QString setImageOptions(int number);

    inline void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }

signals:

    //signals
    void clicked();
};

#endif // GRAPHIC_OPTIONS_H
