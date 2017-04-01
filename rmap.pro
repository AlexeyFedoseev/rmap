#-------------------------------------------------
#
# Project created by QtCreator 2017-02-25T19:14:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rmap
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    city.cpp \
    graphicspixmapitem.cpp \
    question.cpp \
    answerwindow.cpp

HEADERS  += mainwindow.h \
    city.h \
    graphicspixmapitem.h \
    question.h \
    answerwindow.h

FORMS    += mainwindow.ui \
    city.ui \
    answerwindow.ui

RESOURCES += \
    resource.qrc

DISTFILES += \
    SUx182.jpeg \
    krest.jpg \
    galochka.png
