#ifndef STATISTIC_SET_DATA_H
#define STATISTIC_SET_DATA_H

#include <QString>
#include <QColor>
class statistic_set_data{

public:
    // Constructors
    statistic_set_data();

    // Public Methods
    void set_the_data(int level);

    // Public Attributes
    QString correct;
    QString wrong;
    QString time;
    QString difficult;
    QColor colour;

private:
    // Private Methods
    void check_the_level(int level);

};

#endif // STATISTIC_SET_DATA_H
