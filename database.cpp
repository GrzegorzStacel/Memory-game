#include "database.h"

#include <QDebug>

QSqlDatabase DataBase::dba;

DataBase::DataBase(){

}

QSqlDatabase DataBase::data_base(){
    return dba;
}

void DataBase::connect(){

    dba = QSqlDatabase::addDatabase("QMYSQL");

    dba.setDatabaseName("memory_game");
    dba.setHostName("localhost");
    dba.setPassword("");
    dba.setPort(3306);
    dba.setUserName("root");


}

QString DataBase::select(QString value, int column){


    if(dba.open()) {

        QSqlQuery ask;

            if(ask.exec(value)){

                while(ask.next()){
                     //qDebug() << ask.value(column).toString();
                     return ask.value(column).toString();

                }
            }

        } else
            qDebug() << "Error DataBase::select(QString, int): " << dba.lastError();

    return "Error load in database. DataBase::select(QString, int)";
}

QString DataBase::select(QString value, int columnA, int columnB){

    if(dba.open()) {

        QSqlQuery ask;

        if(ask.exec(value)){
            while(ask.next()){
                    qDebug() << ask.value(columnA).toString() + " - " +
                                ask.value(columnB).toString();
            }
        }

    } else
        qDebug() << "Error DataBase::select(QString, int, int): " << dba.lastError();

    return "Error load in database. DataBase::select(QString, int, int)";
}

void DataBase::insert(QString value){

    if(dba.open()) {

        QSqlQuery ask;

        ask.exec(value);

    } else
        qDebug() << "Error load: " << dba.lastError();

}
