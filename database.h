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
        QString select(QString value, int column);
        QString select(QString value, int columnA, int columnB);
        void insert(QString value);
        QSqlDatabase data_base();
        void connect();

    // Public Attributes
        static QSqlDatabase dba;
};

#endif // DATABASE_H
