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
    ennemy.cpp \
    score.cpp \
    health.cpp \
    floor.cpp \
    bonus.cpp \
    block.cpp \
    brique.cpp \
    controller.cpp \
    view.cpp \
    model.cpp \
    piece.cpp \
    cake.cpp

HEADERS  += \
    character.h \
    ennemy.h \
    score.h \
    health.h \
    floor.h \
    bonus.h \
    block.h \
    brique.h \
    controller.h \
    view.h \
    model.h \
    piece.h \
    cake.h

FORMS    +=

RESOURCES += \
    res.qrc
