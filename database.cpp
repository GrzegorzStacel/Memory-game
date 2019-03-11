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

QSqlDatabase DataBase::data_base(){
    return db;
}

void DataBase::error(){
    qDebug() << "Data hasn't been saved in the database";
}

void DataBase::query(QString value, int column){

    if(db.open()) {

        qDebug() << "DB is opened ( one )";

        QSqlQuery ask;

        if(ask.exec(value)){
            while(ask.next()){
                 qDebug() << ask.value(column).toString();
            }
        }

    } else {
        qDebug() << "Error load: " << db.lastError();
    }

    qDebug() << "Closing...";
    db.close();
}

void DataBase::query(QString value, int columnA, int columnB){

    if(db.open()) {

        qDebug() << "DB is opened ( two )";

        QSqlQuery ask;

        if(ask.exec(value)){
            while(ask.next()){
                    qDebug() << ask.value(columnA).toString() + " - " +
                                ask.value(columnB).toString();

            }
        }

    } else {
        qDebug() << "Error load: " << db.lastError();
    }

    qDebug() << "Closing...";
    db.close();
}
