#-------------------------------------------------
#
# Project created by QtCreator 2013-11-10T21:18:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = batchEditAudioTag
TEMPLATE = app

#ifdef Q_OS_WIN32
    LIBS += C:\taglib\lib\libtag.dll
    LIBS += C:\taglib\lib\libzlib.dll
    INCLUDEPATH += C:\taglib\include
#endif

SOURCES += main.cpp\
        mainwindow.cpp \
    getdirinfo.cpp \
    showfileinfo.cpp

HEADERS  += mainwindow.h \
    getdirinfo.h \
    showfileinfo.h

FORMS    += mainwindow.ui
