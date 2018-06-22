TARGET = test

TEMPLATE = app

QT += testlib
QT -= gui

CONFIG += console
CONFIG -= debug_and_release debug_and_release_target

win32-msvc*: LIBSUFFIX = lib
else: LIBSUFFIX = a

LIBS += -L../QtJsonSchema/ -lQtJsonSchema
PRE_TARGETDEPS += ../QtJsonSchema/libQtJsonSchema.$${LIBSUFFIX}

include($$PWD/test.pri)
