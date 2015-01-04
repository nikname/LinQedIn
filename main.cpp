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

    LinQedInAdmin admin = LinQedInAdmin();

    return a.exec();
}
