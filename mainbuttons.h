#ifndef MAINBUTTONS_H
#define MAINBUTTONS_H

#include <QGraphicsTextItem>
#include <QKeyEvent>

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class MainButtons : public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    MainButtons(QString name, QGraphicsItem *parent=nullptr);

    void mousePressEvent(QGraphicsSceneMouseEvent *event) { emit clicked(); }
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();

private:
    QGraphicsTextItem *text;

};

#endif // MAINBUTTONS_H
