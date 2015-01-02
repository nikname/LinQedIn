#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "utente.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Profilo p( "Nicola", "Dalla Costa", QDate( 1993, 12, 1 ) );
    Utente u( Username( "nikname" ), p );

    qDebug() << u;

    return a.exec();
}
