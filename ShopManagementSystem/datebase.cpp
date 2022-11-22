#include "datebase.h"
QSqlDatabase Database::db = QSqlDatabase::addDatabase("QODBC");     //创建静态数据实例
QSqlQuery* Database::sql = NULL;

Database::Database() {
        qDebug() << "数据库实例已创建";
}

bool Database::getConnection() {
    // 数据库连接
    db.setHostName("127.0.0.1");                // 绑定数据库IP路径
    db.setPort(3306);                                   // 绑定数据库端口号
    db.setDatabaseName("shopmanagement");      // 绑定ODBC数据源名称
    db.setUserName("root");                         // 绑定数据库系统用户名
    db.setPassword("123456");                   // 输入数据库系统登录密码
    if (!db.open()) {
        qDebug() << "DataBase Error";
        qDebug() << db.lastError().text();
        return false;
    }
    else {
        qDebug() << "connect successed!";
        return false;
    }

}

void Database::quitConnection() {
    db.close();
}
