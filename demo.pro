#-------------------------------------------------
#
# Project created by QtCreator 2012-05-16T22:47:21
#
#-------------------------------------------------

QT       += core gui webkit

TARGET = demo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    htmlview.cpp \
    addressbar.cpp \
    tabpage.cpp

HEADERS  += mainwindow.h \
    htmlview.h \
    addressbar.h \
    tabpage.h

FORMS    += mainwindow.ui

RESOURCES += \
    html.qrc \
    script.qrc \
    style.qrc \
    resource.qrc
