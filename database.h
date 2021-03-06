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

    // Public Methods
        QString select(QString value);
        void insert(QString value);
        void connect();

    // Public Attributes
        static QSqlDatabase dba;
};

#endif // DATABASE_H
