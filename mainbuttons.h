#ifndef MAINBUTTONS_H
#define MAINBUTTONS_H

#include <QGraphicsTextItem>

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class MainButtons : public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:

    //constructors
    MainButtons(QString name, int x = 200, int y = 50, QGraphicsItem *parent=nullptr);


private:

    // private attributes
    QGraphicsTextItem *text;

    // private methods
    void drawRect(int x, int y);


public:

    // public methods
    void mousePressEvent(QGraphicsSceneMouseEvent *) { emit clicked(); }
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);

signals:

    // public signals
    void clicked();
    void buttonClickedWrong(int);
    void buttonClickedCorrect(int);

private slots:
    void handleClickWrong();
    void handleClickCorrect();


};

#endif // MAINBUTTONS_H
