#include "database.h"

#include <QDebug>

DataBase::DataBase(){

    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setDatabaseName("memory_game");
    db.setHostName("localhost");
    db.setPassword("");
    db.setPort(3306);
    db.setUserName("root");    

}

void DataBase::insert(QString value){

    if(db.open()) {

        qDebug() << "DB is opened";
        QSqlQuery ask;

        if(ask.exec(value)){
            while(ask.next()){
                qDebug() << ask.value(0).toString() + " - " +
                            ask.value(1).toString() + " - " +
                            ask.value(2).toString() + " - " +
                            ask.value(3).toString() + " - " +
                            ask.value(4).toString() + " - " +
                            ask.value(5).toString() + " - " +
                            ask.value(6).toString() + " - " +
                            ask.value(7).toString() + " - " +
                            ask.value(8).toString() + " - " +
                            ask.value(9).toString();

            }
        }

    } else {
        qDebug() << "Error load: " << db.lastError();
    }

    qDebug() << "Closing...";
    db.close();



}
