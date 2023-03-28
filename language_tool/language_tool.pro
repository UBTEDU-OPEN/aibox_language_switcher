#-------------------------------------------------
#
# Project created by QtCreator 2021-08-30T10:36:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TRANSLATIONS += language_tool_zh_CN.ts \
                language_tool_en_US.ts

TARGET = language_tool
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
        mainwindow.cpp \
    titlebar.cpp \
    content.cpp \
    dialog.cpp \
    setting.cpp

HEADERS += \
        mainwindow.h \
    titlebar.h \
    content.h \
    dialog.h \
    setting.h

FORMS += \
        mainwindow.ui \
    titlebar.ui \
    content.ui \
    dialog.ui \
    setting.ui

include(qtsingleapplication/src/qtsingleapplication.pri)

RESOURCES += \
    icon.qrc

DISTFILES += \
    language_tool_en_US.ts \
    language_tool_zh_CN.ts
