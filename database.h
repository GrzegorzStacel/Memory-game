#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QDebug>

class DataBase{

public:
    // Constructor
    DataBase();

    void insert(QString value);

    QSqlDatabase db;
};

#endif // DATABASE_H
