#-------------------------------------------------
#
# Project created by QtCreator 2014-12-19T12:29:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LinqedIn
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    profilo.cpp \
    username.cpp \
    data.cpp \
    utente.cpp

HEADERS  += mainwindow.h \
    profilo.h \
    rete.h \
    smart_utente.h \
    username.h \
    utente.h \
    utente_gratis.h \
    utente_pagante.h \
    utente_basic.h \
    utente_express.h \
    utente_business.h \
    esperienza.h \
    data.h \
    titolo_studio.h

FORMS    += mainwindow.ui
