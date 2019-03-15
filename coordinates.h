#ifndef COORDINATES_H
#define COORDINATES_H


class coordinates {

public:
    // Constructors
    coordinates();

    // Public Methods
    void level(int difficulty);


private:
    // Private methods
    void placeCardsEasy(int x, int y, int cards);
    void placeCardsMedium(int x, int y, int cards);
    void placeCardsHard(int x, int y, int cards);
    void placeCardsHardcore(int x, int y, int cards);

};

#endif // COORDINATES_H
