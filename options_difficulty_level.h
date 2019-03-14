#ifndef OPTIONS_DIFFICULTY_LEVEL_H
#define OPTIONS_DIFFICULTY_LEVEL_H



#include <QObject>
#include <QFont>
#include <QGraphicsTextItem>

#include "statistic.h"

class options_difficulty_level : public QObject {
    Q_OBJECT

    // private attrubutes


public:

    // constructors
    options_difficulty_level();

signals:
    void clicked();

public slots:

    // public slots
    void show_options();
    void easy();
    void medium();
    void hard();
    void hardcore();

};

#endif // OPTIONS_DIFFICULTY_LEVEL_H
