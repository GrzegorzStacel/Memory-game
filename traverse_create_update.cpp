#include "traverse_create_update.h"


#include <QDebug>

Traverse_Create_Update::Traverse_Create_Update(Traverse &obj) : Traverse_Create_New (obj){

}

void Traverse_Create_Update::update_start( int value ){

    qDebug() << "update";
}
