#include "gui/clientwindow.h"
#include "../linqedin_client.h"

ClientWindow::ClientWindow( QWidget *parent ) :
    QMainWindow( parent )
{
    QWidget *widget = new QWidget;
    setCentralWidget( widget );

    this->show();
}

