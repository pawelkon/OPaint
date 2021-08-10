QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(OPaint.pri)

SOURCES += \
    main.cpp

DISTFILES += \
    ../../include/opaint/Debug \
    ../../include/opaint/LabelPixmap \
    ../../include/opaint/Mouse \
    ../../include/opaint/MouseButton \
    ../../include/opaint/PaintColor \
    ../../include/opaint/PaintEvent \
    ../../include/opaint/PainterTools \
    ../../include/opaint/PenCursor \
    ../../include/opaint/PenEvent \
    ../../include/opaint/Program \
    ../../include/opaint/ui/ColorWidget \
    ../../include/opaint/ui/DrawingArea \
    ../../include/opaint/ui/MainWindow \
    OPaint.pri

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

