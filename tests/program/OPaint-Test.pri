QT += widgets
QT += core
QT += testlib
QT += gui

CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

include(../../src/OPaint/OPaint.pri)

SOURCES +=  \
    $$PWD/ts_program.cpp

HEADERS += \
    $$PWD/ts_program.h

INCLUDEPATH += $$PWD/../../src/OPaint/
