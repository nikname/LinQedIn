#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>
#include "linqedinwindow.h"

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
    exitAct->setStatusTip( tr( "Chiudi applicazione" ) );
    connect( exitAct, SIGNAL( triggered() ), this, SLOT( close() ) );

    aboutAct->setStatusTip( tr( "Mostra informazioni sull'applicazione") );
    connect( aboutAct, SIGNAL( triggered() ), this, SLOT( about() ) );
}

// METODO LinQedInWindow::createMenus
void LinQedInWindow::createMenus() {
    menu->addAction( exitAct );
    helpMenu->addAction( aboutAct );
}

// METODO LinQedInWindow::setButtonProperties( QPushButton*, QString )
void LinQedInWindow::setButtonProperties( QPushButton* button, const QString& pressed_color ) {
    button->setFixedSize( 50, 50 );
    QString style = QString(
        "QPushButton { border-radius: 25px; outline: 0; }"
        "QPushButton:pressed { background: %1; }"
    ).arg( pressed_color );

    button->setStyleSheet( style );
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
