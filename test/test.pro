TARGET = test

TEMPLATE = app

QT += testlib
QT -= gui

CONFIG += console
CONFIG -= debug_and_release debug_and_release_target

LIBS += -L../QtJsonSchema/ -lQtJsonSchema

include($$PWD/test.pri)
