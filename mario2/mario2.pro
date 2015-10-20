#-------------------------------------------------
#
# Project created by QtCreator 2015-10-02T11:46:16
#
#-------------------------------------------------

QT       += core gui \
            multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mario2
TEMPLATE = app


SOURCES += main.cpp \
    character.cpp \
    stove.cpp \
    ennemy.cpp \
    game.cpp \
    score.cpp \
    health.cpp \
    floor.cpp \
    bonus.cpp \
    block.cpp \
    menu.cpp \
    brique.cpp \
    controller.cpp \
    view.cpp

HEADERS  += \
    character.h \
    stove.h \
    ennemy.h \
    game.h \
    score.h \
    health.h \
    floor.h \
    bonus.h \
    block.h \
    menu.h \
    brique.h \
    controller.h \
    view.h

FORMS    +=

RESOURCES += \
    res.qrc
