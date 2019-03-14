#-------------------------------------------------
#
# Project created by QtCreator 2018-10-04T11:48:51
#
#-------------------------------------------------

QT       += core gui
QT       += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Memory_Cards
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    game.cpp \
    mainbuttons.cpp \
    cards.cpp \
    drawcards.cpp \
    game_over.cpp \
    timer.cpp \
    statistic.cpp \
    options_difficulty_level.cpp \
    generator_of_random_numbers.cpp \
    graphic_options.cpp \
    graphic_others.cpp \
    statistic_is_best_time.cpp \
    who_is_best.cpp \
    database.cpp

HEADERS += \
    game.h \
    mainbuttons.h \
    cards.h \
    drawcards.h \
    game_over.h \
    timer.h \
    statistic.h \
    options_difficulty_level.h \
    generator_of_random_numbers.h \
    graphic_options.h \
    graphic_others.h \
    statistic_is_best_time.h \
    who_is_best.h \
    database.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=
