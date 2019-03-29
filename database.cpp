#include "database.h"

#include <QDebug>

QSqlDatabase DataBase::dba;

DataBase::DataBase(){

}

void DataBase::connect(){

    dba = QSqlDatabase::addDatabase("QMYSQL");

    dba.setDatabaseName("memory_game");
    dba.setHostName("localhost");
    dba.setPassword("");
    dba.setPort(3306);
    dba.setUserName("root");

}

QString DataBase::select(QString value){


    if(dba.open()) {

        QSqlQuery ask;

            if(ask.exec(value)){

                while(ask.next())
                     return ask.value(0).toString();

            }

        } else
            qDebug() << "Error DataBase::select(QString) - " << dba.lastError();

    return "Error load in database. DataBase::select(QString)";
}

void DataBase::insert(QString value){

    if(dba.open()) {

        QSqlQuery ask;

        ask.exec(value);

    } else
        qDebug() << "Error load: " << dba.lastError();

}
