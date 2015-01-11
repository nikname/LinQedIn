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

int main(int argc, char *argv[])
{
    QApplication a( argc, argv );
    MainWindow w;
    w.show();

    Utente* u1 = new UtenteBasic( Username( "nikname" ),
                                  Profilo( "Nicola", "Dalla Costa", QDate( 1993, 12, 1 ) ) );

    qDebug() << u1->getUsername();
    u1->getUsername().changeLogin( "ciao" );
    qDebug() << u1->getUsername();

    LinQedInAdmin admin = LinQedInAdmin();
    admin.insertUser( u1 );
    qDebug() << admin.getDB()->usersNumber();

    admin.getDB()->saveUsersList();

    return a.exec();
}
