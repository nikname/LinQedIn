#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "utente.h"
#include "linqedin_admin.h"
#include "linqedin_client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Utente u1( Username( "dalla.costa.nicola@gmail.com" ),
              Profilo( "Nicola", "Dalla Costa", QDate( 1993, 12, 1 ) ) );
    Utente u2( Username( "matteo.dallacosta92@gmail.com" ),
              Profilo( "Matteo", "Dalla Costa", QDate( 1992, 1, 0 ) ) );

    LinQedInAdmin admin = LinQedInAdmin();
    admin.insertUser( &u1 );
    admin.insertUser( &u2 );

    u1.getNet().addContact( Username( u2.getUsername().getLogin() ), admin.getDB() );

    qDebug() << admin.getDB()->usersNumber();

    admin.getDB()->saveUsersList();

    return a.exec();
}
