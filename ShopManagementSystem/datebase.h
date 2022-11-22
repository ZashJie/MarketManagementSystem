#ifndef DATEBASE_H
#define DATEBASE_H
#include <Qsql>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlError>
#include <QSqlQuery>

class Database {
public:
    Database();
    // 数据库相关函数
    static bool getConnection();            // 获得数据库连接
    static void quitConnection();           // 断开数据库

private:
    static  QSqlDatabase db;            // 定义静态变量db作为数据库实例
    static QSqlQuery* sql;                  // 定义静态变量sql作为数据库执行语言实例
};




#endif // DATEBASE_H
