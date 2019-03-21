#ifndef TRAVERSE_CREATE_H
#define TRAVERSE_CREATE_H

#include "graphic_others.h"

#include <QObject>
#include <QTextEdit>
#include <QPushButton>
#include <QPointer>

class Traverse_Create_new : public QObject {
    Q_OBJECT

public:
    // Constructors
    Traverse_Create_new(QObject *parent = nullptr);


    // Public Attributes
    void Learn(int x);


private:
    // Private Methods
    void add_button(int value, int x_pos, int y_pos);
    void which_graphic(int value);
    void save_changes(int colour, QString description);
    void update(QString description);

    // Pribate Attributes
    QList<Graphic_others> list;
    QList<QTextEdit> text_list;    
    QList <QPointer <QTextEdit> > list_text;


    QGraphicsProxyWidget *pProxyWidget;
    QPointer <QPushButton> save_button;
    QPointer <QTextEdit> text;

    int group_card;
    bool is_save;








};

#endif // TRAVERSE_CREATE_H
