QT += widgets
QT += core
QT += testlib
QT += gui

CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

include(../../src/OPaint/OPaint.pri)

SOURCES +=  \
    colorchoice.cpp \
    drawlinetest.cpp \
    gui.cpp

HEADERS += \
    colorchoice.h \
    drawlinetest.h \
    gui.h

INCLUDEPATH += $$PWD/../../src/OPaint/
