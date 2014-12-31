#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QDebug>
#include <string>
#include "utente.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Utente u( Username( "nikname" ), Profilo( "Nicola", "Dalla Costa" ) );
    u.getNet().addContact( Username( "dalla.costa.nicola@gmail.com" ) );
    u.getNet().addContact( Username( "nik.dalla.costa@gmail.com" ) );

    qDebug() << u;

    return a.exec();
}
