#-------------------------------------------------
#
# Project created by QtCreator 2018-03-21T14:11:32
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Druckersoftware
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    machinecontroller.cpp \
    gcodereader.cpp \
    serialinterface.cpp \
    motorcontroller.cpp \
    Logging/logfile.cpp \
    Logging/logger.cpp \
    UI/commandlineui.cpp \
    UI/controlwindow.cpp \
    IO/fancontroller.cpp \
    IO/heatingcontroller.cpp \
    IO/iocontroller.cpp \
    IO/sensorlistener.cpp \
    IO/iomainloop.cpp

HEADERS += \
    machinecontroller.h \
    gcodereader.h \
    serialinterface.h \
    motorcontroller.h \
    Logging/logfile.h \
    Logging/logger.h \
    UI/commandlineui.h \
    UI/controlwindow.h \
    IO/fancontroller.h \
    IO/heatingcontroller.h \
    IO/iocontroller.h \
    IO/piControl.h \
    IO/sensorlistener.h \
    IO/iomainloop.h

FORMS += \
    UI/controlwindow.ui
