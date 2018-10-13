#ifndef MAINBUTTONS_H
#define MAINBUTTONS_H

#include <QGraphicsTextItem>

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class MainButtons : public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:

    //constructors
    MainButtons(QString name, QGraphicsItem *parent=nullptr);


private:

    // private attributes
    QGraphicsTextItem *text;


public:

    // public methods
    void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);

signals:

    // public signals
    void clicked();



};

#endif // MAINBUTTONS_H
