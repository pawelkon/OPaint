QT += widgets
QT += core
QT += testlib
QT += gui

CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  \
    ../../src/OPaint/debug.cpp \
    ../../src/OPaint/labelpixmap.cpp \
    ../../src/OPaint/mouse/mouse.cpp \
    ../../src/OPaint/mouse/mousebutton.cpp \
    ../../src/OPaint/paintcolor.cpp \
    ../../src/OPaint/paintertools.cpp \
    ../../src/OPaint/paintevent.cpp \
    ../../src/OPaint/penevent.cpp \
    ../../src/OPaint/program.cpp \
    ../../src/OPaint/ui/colorwidget.cpp \
    ../../src/OPaint/ui/drawingarea.cpp \
    ../../src/OPaint/ui/mainwindow.cpp \
    blackdrawing.cpp \
    colorchoice.cpp \
    gui.cpp

HEADERS += \
    ../../src/OPaint/debug.h \
    ../../src/OPaint/labelpixmap.h \
    ../../src/OPaint/mouse/mouse.h \
    ../../src/OPaint/mouse/mousebutton.h \
    ../../src/OPaint/paintcolor.h \
    ../../src/OPaint/paintertools.h \
    ../../src/OPaint/paintevent.h \
    ../../src/OPaint/penevent.h \
    ../../src/OPaint/program.h \
    ../../src/OPaint/ui/colorwidget.h \
    ../../src/OPaint/ui/drawingarea.h \
    ../../src/OPaint/ui/mainwindow.h \
    blackdrawing.h \
    colorchoice.h \
    gui.h

INCLUDEPATH += ../../include/
INCLUDEPATH += ../../src/OPaint/

SUBDIRS += \
    ../../src/OPaint/OPaint.pro

FORMS += \
    ../../src/OPaint/mainwindow.ui

DISTFILES += \
    ../../src/OPaint/debug/OPaint.exe
