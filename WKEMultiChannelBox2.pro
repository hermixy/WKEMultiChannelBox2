#-------------------------------------------------
#
# Project created by QtCreator 2014-09-26T12:11:29
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
RC_FILE  =Icon.rc
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WKEMultiChannelBox2
TEMPLATE = app


SOURCES += main.cpp\
    clsPortListener.cpp \
    clsConnectSWBox.cpp \
    clsMainWindow.cpp

HEADERS  += \
    clsPortListener.h \
    clsConnectSWBox.h \
    clsMainWindow.h

FORMS    += \
    clsMainWindow.ui

RESOURCES += \
    MyRec.qrc
