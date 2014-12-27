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

    Profilo p( "Nicola", "Dalla Costa" );
    Utente u( Username( "dalla.costa.nicola@gmail.com" ), p );
    cout << u << endl;

    return a.exec();
}
