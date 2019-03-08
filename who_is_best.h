#ifndef WHO_IS_BEST_H
#define WHO_IS_BEST_H

#include <QString>

class Who_Is_Best {

public:
    // Constructors
    Who_Is_Best();

    // Public Methods
    int score();

private:
    // Private Attributes
    int count_ActualTime;
    int count_BestTime;

    // Private Methods
    int Comparison();
    void Receive_Value();
};

#endif // WHO_IS_BEST_H
