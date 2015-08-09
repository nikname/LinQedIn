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
    utente_gratis.cpp \
    utente_pagante.cpp \
    titolo.cpp \
    lavoro.cpp \
    smarttitolo.cpp \
    smartlavoro.cpp \
    gui/mainwindow.cpp \
    gui/adminwindow.cpp \
    gui/clientwindow.cpp \
    gui/tablemodel.cpp \
    gui/adduserdialog.cpp \
    gui/changeusertypedialog.cpp \
    gui/usersearchwidget.cpp \
    gui/tabprofilo.cpp \
    gui/tabrete.cpp \
    utente_executive.cpp \
    gui/adminsearchwidget.cpp \
    gui/userlistwidget.cpp \
    gui/menubutton.cpp \
    gui/profilewidget.cpp \
    gui/experienceswidget.cpp \
    gui/jobwidget.cpp \
    gui/educationswidget.cpp \
    gui/titlewidget.cpp

HEADERS  += \
    profilo.h \
    rete.h \
    utente.h \
    utente_gratis.h \
    utente_pagante.h \
    utente_basic.h \
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
    gui/adminwindow.h \
    gui/clientwindow.h \
    gui/tablemodel.h \
    gui/adduserdialog.h \
    gui/changeusertypedialog.h \
    gui/usersearchwidget.h \
    gui/tabprofilo.h \
    gui/tabrete.h \
    utente_executive.h \
    gui/userlistwidget.h \
    gui/adminsearchwidget.h \
    gui/menubutton.h \
    gui/profilewidget.h \
    gui/experienceswidget.h \
    gui/jobwidget.h \
    gui/educationswidget.h \
    gui/titlewidget.h

FORMS    +=

OTHER_FILES +=

RESOURCES += \
    icons.qrc
