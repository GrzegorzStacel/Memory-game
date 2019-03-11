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
        QString query(QString value, int column);
        void query(QString value, int columnA, int columnB);
        QSqlDatabase data_base();
        void error(QString value);

    // Public Attributes
        QSqlDatabase db;
};

#endif // DATABASE_H
