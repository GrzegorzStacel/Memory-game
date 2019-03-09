#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQueryModel>

#include <QDebug>

//#include <QtSql>
//INCLUDEPATH += F:/Programy/Qt/SQL_CONNECTOR/mysql-connector-c-6.1.11-win32/mysql-connector-c-6.1.11-win32/include
class DataBase{

public:
    // Constructor
    DataBase();

    QSqlDatabase db;
};

#endif // DATABASE_H
