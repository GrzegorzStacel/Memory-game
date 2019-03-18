#ifndef CARDS_POSITION_H
#define CARDS_POSITION_H

#include <QList>

class Cards_Position{

public:
    // Cosnstructors
    Cards_Position();

     // Public Methods
    void select_lvl(int level);

    // getter
    int getX_POS(int value)   const        { return x_position[value]; }
    int getY_POS(int value)   const        { return y_position[value]; }
    bool getActive(int value) const        { return Active[value]; }
    bool getWhich_Card()      const        { return Which_Card; }

private:
    // Private Attributes
    QList<int> x_position;
    QList<int> y_position;
    QList<bool> Active;
    bool Which_Card;

    // Private Methods
    void placeCardsEasy(int x, int y, int cards);
    void placeCardsMedium(int x, int y, int cards);
    void placeCardsHard(int x, int y, int cards);
    void placeCardsHardcore(int x, int y, int cards);
};

#endif // CARDS_POSITION_H
