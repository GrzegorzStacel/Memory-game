#ifndef TRAVERSE_CREATE_H
#define TRAVERSE_CREATE_H


#include <QObject>

class Traverse_Create_new : public QObject {
    Q_OBJECT

public:
    // Constructors
    Traverse_Create_new();

    // Public Attributes
    void Learn(int x);


private:
    // Private Methods
    void add_button(int value, int x_pos, int y_pos);
    void which_graphic(int value);

    // Pribate Attributes
    QList<Graphic_others> list;
    int group_card;
};

#endif // TRAVERSE_CREATE_H
