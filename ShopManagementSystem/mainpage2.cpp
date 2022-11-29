#include "mainpage2.h"
#include "ui_mainpage2.h"

mainpage2::mainpage2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainpage2)
{
    ui->setupUi(this);
}

mainpage2::~mainpage2()
{
    delete ui;
}
