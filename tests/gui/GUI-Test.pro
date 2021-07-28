QT += widgets
QT += core
QT += testlib
QT += gui

CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  \
    main.cpp

HEADERS += \
    main.h

INCLUDEPATH += ../../include/
INCLUDEPATH += ../../src/OPaint/
