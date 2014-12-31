#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "utente.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Rete r;
    //r.addContact( Username( "1" ) );
    //r.addContact( Username( "2" ) );

    qDebug() << r;

    return a.exec();
}
