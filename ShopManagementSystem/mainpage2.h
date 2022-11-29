#ifndef MAINPAGE2_H
#define MAINPAGE2_H

#include <QMainWindow>

namespace Ui {
class mainpage2;
}

class mainpage2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainpage2(QWidget *parent = nullptr);
    ~mainpage2();

private:
    Ui::mainpage2 *ui;
};

#endif // MAINPAGE2_H
