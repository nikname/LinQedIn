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
        mainwindow.cpp \
    profilo.cpp \
    username.cpp \
    utente.cpp \
    rete.cpp \
    esperienza.cpp \
    formazione.cpp \
    smartutente.cpp \
    database.cpp \
    linqedin_admin.cpp \
    linqedin_client.cpp

HEADERS  += mainwindow.h \
    profilo.h \
    rete.h \
    username.h \
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
    linqedin_client.h

FORMS    += mainwindow.ui
