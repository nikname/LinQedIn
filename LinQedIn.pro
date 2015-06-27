#-------------------------------------------------
#
# Project created by QtCreator 2014-12-19T12:29:41
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LinqedIn
TEMPLATE = app


SOURCES += main.cpp\
    profilo.cpp \
    utente.cpp \
    rete.cpp \
    esperienza.cpp \
    formazione.cpp \
    smartutente.cpp \
    database.cpp \
    linqedin_admin.cpp \
    linqedin_client.cpp \
    utente_basic.cpp \
    utente_business.cpp \
    utente_express.cpp \
    utente_gratis.cpp \
    utente_pagante.cpp \
    titolo.cpp \
    lavoro.cpp \
    smarttitolo.cpp \
    smartlavoro.cpp \
    gui/mainwindow.cpp \
    gui/adminsearch_widget.cpp \
    gui/adminwindow.cpp \
    gui/clientwindow.cpp \
    gui/userlist_widget.cpp \
    gui/tablemodel.cpp \
    gui/adduserdialog.cpp

HEADERS  += \
    profilo.h \
    rete.h \
    utente.h \
    utente_gratis.h \
    utente_pagante.h \
    utente_basic.h \
    utente_express.h \
    utente_business.h \
    esperienza.h \
    formazione.h \
    database.h \
    smartutente.h \
    linqedin_admin.h \
    linqedin_client.h \
    titolo.h \
    lavoro.h \
    smarttitolo.h \
    smartlavoro.h \
    gui/mainwindow.h \
    gui/adminsearch_widget.h \
    gui/adminwindow.h \
    gui/clientwindow.h \
    gui/userlist_widget.h \
    gui/tablemodel.h \
    gui/adduserdialog.h

FORMS    +=

OTHER_FILES +=

RESOURCES += \
    icons.qrc
