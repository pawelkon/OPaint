QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractpaintevent.cpp \
    debug.cpp \
    labelpixmap.cpp \
    mouse/mouse.cpp \
    ui/drawingarea.cpp \
    main.cpp \
    ui/mainwindow.cpp \
    program.cpp

HEADERS += \
    abstractpaintevent.h \
    debug.h \
    labelpixmap.h \
    mouse/mouse.h \
    ui/drawingarea.h \
    ui/mainwindow.h \
    program.h

FORMS += \
    mainwindow.ui

DISTFILES += \
    ../../include/opaint/AbstractPaintEvent \
    ../../include/opaint/Debug \
    ../../include/opaint/LabelPixmap \
    ../../include/opaint/Program \
    ../../include/opaint/ui/DrawingArea \
    ../../include/opaint/ui/MainWindow

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += ../../include
