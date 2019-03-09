#include "database.h"

DataBase::DataBase(){

    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setDatabaseName("memory_game");
    db.setHostName("localhost");
    db.setPassword("");
    db.setPort(3306);
    db.setUserName("root");

    if(!db.open()) {
        qDebug() << "Error load: " << db.lastError();
    } else {
        qDebug() << "DB is opened";
    }

}
