#ifndef CARDS_H
#define CARDS_H

#include <QGraphicsTextItem>
//#include <QGraphicsView>

class Cards : public QObject, public QGraphicsPixmapItem{

public:

    // constructors
    Cards();

    // public methods
    void setImage(int number);
    void generatorOfRandomNumbers();
    //Cards(bool isActive);


private:

    //private attributes
    static int tablica[13];

    // private methods
    bool czyBylaWylosowana( int iL, int i );


};

#endif // CARDS_H
