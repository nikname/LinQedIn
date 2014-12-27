#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <string>
#include <vector>
#include "utente.cpp"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Utente u( Username( "dalla.costa.nicola@gmail.com" ), Profilo( "Nicola", "Dalla Costa", Data( "01", "12", "1993" ), "Single" ) );
    cout << u << endl;

    return a.exec();
}
