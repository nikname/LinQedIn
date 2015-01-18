#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "utente.h"
#include "utente_gratis.h"
#include "utente_basic.h"
#include "utente_pagante.h"
#include "utente_express.h"
#include "utente_business.h"
#include "linqedin_admin.h"
#include "linqedin_client.h"

int main( int argc, char *argv[] ) {
    QApplication a( argc, argv );
    MainWindow w;
    w.show();

    Utente* u1 = new UtenteBasic( Username( "nikname" ),
                                  Profilo( "Nicola", "Dalla Costa" ) );
    qDebug() << u1;

    delete u1;

    return a.exec();
}
