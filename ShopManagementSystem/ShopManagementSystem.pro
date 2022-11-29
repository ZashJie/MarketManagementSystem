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
    mainpage2.cpp \
    signin_page.cpp

HEADERS  += \
    datebase.h \
    mainpage.h \
    mainpage2.h \
    signin_page.h

FORMS    += \
    mainpage.ui \
    mainpage2.ui \
    signin_page.ui
