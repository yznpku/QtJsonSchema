TARGET = QtJsonSchema

TEMPLATE = lib

QT -= gui

CONFIG += static
CONFIG -= debug_and_release debug_and_release_target

include($$PWD/QtJsonSchema.pri)

HEADERS += \
    src/error/jsonschemavalidationerror.h

SOURCES += \
    src/error/jsonschemavalidationerror.cpp
