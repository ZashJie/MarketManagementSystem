#ifndef SIGNIN_PAGE_H
#define SIGNIN_PAGE_H

#include <QWidget>
#include <QString>
#include "datebase.h"   // "?<


QT_BEGIN_NAMESPACE
namespace Ui {              // Ui指针
class SignIn_Page;
}
QT_END_NAMESPACE


class SignIn_Page : public QWidget
{
    Q_OBJECT

public:
    Database myDatabase;
    explicit SignIn_Page(QWidget *parent = 0);
    ~SignIn_Page();
signals:
    void try_login();

private slots:
//   void on_pushButton_clicked();

    void on_PBtn_signIn_clicked();

private:
    Ui::SignIn_Page *ui;
};

#endif // SIGNIN_PAGE_H
