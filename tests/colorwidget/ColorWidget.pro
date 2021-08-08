QT += widgets
QT += core
QT += testlib
QT += gui

CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

include(../../src/OPaint/OPaint.pri)

SOURCES +=  \
    ts_colorwidget.cpp

HEADERS += \
    ts_colorwidget.h

INCLUDEPATH += $$PWD/../../src/OPaint/
