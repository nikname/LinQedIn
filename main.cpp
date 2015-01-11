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
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    UtenteBasic u1( Username( "dalla.costa.nicola@gmail.com" ),
              Profilo( "Nicola", "Dalla Costa", QDate( 1993, 12, 1 ) ) );
    //Utente u2( Username( "matteo.dallacosta92@gmail.com" ),
              //Profilo( "Matteo", "Dalla Costa", QDate( 1992, 1, 8 ) ) );

    LinQedInAdmin admin = LinQedInAdmin();
    admin.insertUser( &u1 );
    //admin.insertUser( &u2 );

    //u1.getNet().addContact( Username( u2.getUsername().getLogin() ), admin.getDB() );
    u1.getEducations().addEducation( Formazione::Titolo( "A. Meucci",
                                                         QDate( 2012, 07, 02 ),
                                                         "Niente",
                                                         "Liceo Scientifico Tecnologico",
                                                         "67" ) );
    u1.getExperiences().addExperience( Esperienza::Lavoro( "Nessuna",
                                                           "Nessuno",
                                                           "Nessuna",
                                                           QDate( 2015, 1, 1 ),
                                                           QDate( 2015, 1, 1 ) ) );

    qDebug() << admin.getDB()->usersNumber();

    admin.getDB()->saveUsersList();

    return a.exec();
}
