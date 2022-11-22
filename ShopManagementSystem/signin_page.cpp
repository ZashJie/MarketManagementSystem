#include "signin_page.h"
#include "ui_signin_page.h"
#include "mainpage.h"
#include "ui_signin_page.h"
//#include "mainpage2.h"

SignIn_Page::SignIn_Page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignIn_Page)
{
    ui->setupUi(this);
    this->myDatabase.getConnection();
}

SignIn_Page::~SignIn_Page()
{
    delete ui;
}
void SignIn_Page::on_PBtn_signIn_clicked()
 {
    qDebug() << "进入按钮函数";
    QString userInputtype;
    if (ui->RBtn_G->isChecked()) {
        userInputtype = "counter";
    }
    else {
        userInputtype = "manager";
    }

    QString userInputNumber = ui->InputNumber->text();               // 从账号输入框组件中，获取输入的信息，以字符串的形式返回给变量userInputNumber
    QString userInputPassword = ui->InputPassWord->text();
    qDebug() << "用户输入的账号"+userInputNumber;
    qDebug() << "用户输入的密码"+userInputPassword;
    qDebug() << "用户输入的类别"+userInputtype;

    if (ui->RBtn_G->isChecked()) {
        // 获取数据库信息
        QSqlQuery sql;
        sql.prepare("select * from u_info where usernumber = :userInputNumber");
        sql.bindValue(":userInputNumber", userInputNumber);
        sql.exec();

        QString userNumber;
        QString userPassward;
        QString usertype;

        while (sql.next()) {
            userNumber = sql.value("usernumber").toString();
            userPassward = sql.value("userpassword").toString();
            usertype = sql.value("usertype").toString();
            qDebug() << "数据库找到的账号" + userNumber;
            qDebug() << "数据库找到的密码" + userPassward;
        }
        qDebug() << "数据库找到的账号" + userNumber;
        qDebug() << "数据库找到的密码" + userPassward;
        qDebug() << "数据库找到的类别" + usertype;
        sql.clear();

        if (userInputPassword == userPassward && userInputNumber == userNumber && usertype == "2") {
            qDebug() << "登录成功！";
            // return 1;
            this->~SignIn_Page();
            // mainpage2* w = new mainpage2();
            // w->show();
        }
        else {
            qDebug() << "登录失败！";
            // return 0;
        }
    }
    else
    {

        // 获取数据库中的信息
        QSqlQuery sql;
        sql.prepare("select * from m_info where usernumber = :userInputNumber");
        sql.bindValue(":userInputNumber", userInputNumber);
        sql.exec();

        QString userNumber;
        QString userPassward;
        QString usertype;

        while (sql.next()) {
            userNumber = sql.value("usernumber").toString();
            userPassward = sql.value("userpassword").toString();
            usertype = sql.value("usertype").toString();
        }
        qDebug() << "数据库找到的账号" + userNumber;
        qDebug() << "数据库找到的密码" + userPassward;
        qDebug() << "数据库找到的类别" + usertype;
        sql.clear();

        if (userInputPassword == userPassward && userInputNumber == userNumber && usertype == "1") {
            qDebug() << "登录成功！";
            // return 1;
            this->~SignIn_Page();
            mainpage* w = new mainpage();
            w->show();
        }
        else {
            qDebug() << "登录失败！";
            // return 0;
        }

    }

}


