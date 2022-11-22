#include "signin_page.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SignIn_Page s;
    s.show();

    return a.exec();
}
