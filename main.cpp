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
    Utente* u2 = new UtenteBasic( Username( "login" ),
                                  Profilo( "Nome", "Cognome" ) );

    LinQedInAdmin admin;

    admin.insertUser( u1 );
    admin.insertUser( u2 );

    qDebug() << admin.getDB()->usersNumber();

    u1->getNet()->addContact( u2->getUsername(), admin.getDB() );
    qDebug() << *( u1->getNet() );
    qDebug() << u1;

    //delete u1;

    return a.exec();
}
