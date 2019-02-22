#ifndef GENERATOR_OF_RANDOM_NUMBERS_H
#define GENERATOR_OF_RANDOM_NUMBERS_H


class Generator_of_random_numbers {

public:

    // constructor
    Generator_of_random_numbers();

    //public methods
    int getRandomNubmer(int x) { return RandomNumbers[x]; }
    void GenerateNumber(int);

private:
    //private methods
    bool IfItWasDrawn(int, int);

    //private attributes
    static int RandomNumbers[52];
};

#endif // GENERATOR_OF_RANDOM_NUMBERS_H
