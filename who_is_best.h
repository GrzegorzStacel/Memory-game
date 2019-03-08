#ifndef WHO_IS_BEST_H
#define WHO_IS_BEST_H

#include <QString>

class Who_Is_Best {

public:
    // Constructors
    Who_Is_Best();

    // Public Methods
    int score();
    void set_Correct_And_Wrong(int, int);

    // Public Attributes
    static int correct;
    static int wrong;

private:
    // Private Attributes
    int count_ActualTime;
    int count_BestTime;

    // Private Methods
    int Comparison();
    void Receive_Value();
};

#endif // WHO_IS_BEST_H
