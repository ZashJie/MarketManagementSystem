#-------------------------------------------------
#
# Project created by QtCreator 2022-11-12T13:34:33
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ShopManagementSystem
TEMPLATE = app


SOURCES += main.cpp\
    datebase.cpp \
    mainpage.cpp \
    signin_page.cpp

HEADERS  += \
    datebase.h \
    mainpage.h \
    signin_page.h

FORMS    += \
    mainpage.ui \
    signin_page.ui
