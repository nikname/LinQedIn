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


    Utente* u1 = new UtenteBasic( "username1", "None1", "Cognome1" );
    Utente* u2 = new UtenteBasic( "username2", "Nome2", "Cognome2" );
    Utente* u3 = new UtenteBasic( "username3", "Nome3", "Cognome3" );

    LinQedInAdmin admin;

    admin.insertUser( u1 );
    admin.insertUser( u2 );
    admin.insertUser( u3 );

    qDebug() << admin.getDB();

    u1->addContact( u2->getUsername(), admin.getDB() );
    u1->addContact( u3->getUsername(), admin.getDB() );
    u2->addContact( u1->getUsername(), admin.getDB() );

    qDebug() << "Contatti di u1:";
    QVector<SmartUtente> v1 = u1->getContactsList();
    for( int i = 0; i < v1.size(); i++ )
        qDebug() << v1[i]->getUsername();

    qDebug() << "Contatti di u2:";
    QVector<SmartUtente> v2 = u2->getContactsList();
    for( int i = 0; i < v2.size(); i++ )
        qDebug() << v2[i]->getUsername();

    qDebug() << "Contatti di u3:";
    QVector<SmartUtente> v3 = u3->getContactsList();
    for( int i = 0; i < v3.size(); i++ )
        qDebug() << v3[i]->getUsername();

    return a.exec();
}
