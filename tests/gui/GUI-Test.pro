QT += widgets
QT += core
QT += testlib
QT += gui

CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

include(../../src/OPaint/OPaint.pri)

SOURCES +=  \
    $$PWD/gui.cpp

HEADERS += \
    $$PWD/gui.h

INCLUDEPATH += $$PWD/../../src/OPaint/
