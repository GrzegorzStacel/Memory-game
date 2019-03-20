#ifndef TRAVERSE_CREATE_H
#define TRAVERSE_CREATE_H

#include "graphic_others.h"

#include <QObject>
#include <QTextEdit>
#include <QPushButton>

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
    QList<QTextEdit> text_list;
    int group_card;
    bool is_save;

    // Private Object
    QGraphicsProxyWidget* pProxyWidget;
    QTextEdit *text;
    QPushButton *save_button;

public slots:
    void save_changes();

};

#endif // TRAVERSE_CREATE_H
