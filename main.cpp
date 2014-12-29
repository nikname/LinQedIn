#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <string>
#include <vector>
#include "utente.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Utente u( Username( "nikname" ), Profilo( "Nicola", "Dalla Costa" ), Rete() );
    u.addContact( Username( "dalla.costa.nicola@gmail.com" ) );
    u.addContact( Username( "nik.dalla.costa@gmail.com" ) );
    cout << u << endl;

    return a.exec();
}
