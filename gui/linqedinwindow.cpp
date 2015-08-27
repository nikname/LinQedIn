#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include "linqedinwindow.h"
#include "mainwindow.h"

// COSTRUTTORE LinQedInWindow
LinQedInWindow::LinQedInWindow( QWidget *parent ) :
    QMainWindow( parent )
{
    initUI();
    setupUI();
}

// DISTRUTTORE LinQedInWindow
LinQedInWindow::~LinQedInWindow() {}

// METODO LinQedInWindow::initUI
void LinQedInWindow::initUI() {
    menu = menuBar()->addMenu( tr( "&Menu" ) );
    helpMenu = menuBar()->addMenu( tr( "&Help" ) );
    logoutAct = new QAction( tr( "Log Out" ), this );
    exitAct = new QAction( tr( "Exit" ), this );
    aboutAct = new QAction( tr( "About" ), this );
}

// METODO LinQedinWindow::setupUI
void LinQedInWindow::setupUI() {
    createMenuActions();
    createMenus();
}

// METODO LinQedInWindow::createMenuActions
void LinQedInWindow::createMenuActions() {
    logoutAct->setStatusTip( tr( "Log out dall'applicazione"));
    connect( logoutAct, SIGNAL( triggered() ), this, SLOT( logout() ) );

    exitAct->setStatusTip( tr( "Chiudi applicazione" ) );
    connect( exitAct, SIGNAL( triggered() ), this, SLOT( close() ) );

    aboutAct->setStatusTip( tr( "Mostra informazioni sull'applicazione") );
    connect( aboutAct, SIGNAL( triggered() ), this, SLOT( about() ) );
}

// METODO LinQedInWindow::createMenus
void LinQedInWindow::createMenus() {
    menu->addAction( logoutAct );
    menu->addAction( exitAct );
    helpMenu->addAction( aboutAct );
}

// SLOT LinQedInWindow::logout
void LinQedInWindow::logout() {
    this->close();

    new MainWindow;
}

// SLOT LinQedInWindow::about
void LinQedInWindow::about() {
    QMessageBox::about( this, tr("About Menu"), tr(
        "<b>LinQedIn</b>"
        "<p>Progetto per il corso di Programmazione ad Oggetti presso l'Università degli "
        "Studi di Padova.</p>"
        "<p>Lo scopo del progetto era lo sviluppo in C++/Qt di un sistema minimale per "
        "l'amministrazione ed utilizzo tramite interfaccia utente grafica di un (piccolo) "
        "database di contatti professionali ispirato a LinkedIn.</p>" ) );
}
