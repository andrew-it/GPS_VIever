#-------------------------------------------------
#
# Project created by QtCreator 2015-12-16T10:03:27
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OOP_Kursach
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    field.cpp \
    mypoint.cpp \
    mytrack.cpp \
    trackpoint.cpp \
    singlepoint.cpp

HEADERS  += mainwindow.h \
    field.h \
    mypoint.h \
    mytrack.h \
    storage.h \
    trackpoint.h \
    singlepoint.h

FORMS    += mainwindow.ui
