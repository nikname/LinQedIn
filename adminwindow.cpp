#include "adminwindow.h"
#include "linqedin_admin.h"
#include <QMessageBox>
#include <QVBoxLayout>

// COSTRUTTORE AdminWindow
AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent)
{
    adminClient = new LinQedInAdmin();

    initializeGUI();

    this->show();
}

// DISTRUTTORE AdminWindow
AdminWindow::~AdminWindow() {}

// METODO AdminWindow::initializeGUI
void AdminWindow::initializeGUI() {
    createMenuActions();
    createMenus();

    QWidget *mainWidget = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    userListWidget = new UserListWidget( adminClient );

    mainLayout->addWidget( userListWidget );

    mainWidget->setLayout( mainLayout );

    setCentralWidget( mainWidget );

    setWindowTitle( "LinQedIn Admin" );
    setMinimumSize( 600, 400 );
}

// METODO AdminWindow::createMenuActions
void AdminWindow::createMenuActions() {
    exitAct = new QAction( tr( "Exit" ), this );
    exitAct->setStatusTip( tr( "Esci dall'applicazione" ) );
    connect( exitAct, SIGNAL( triggered() ), this, SLOT( close() ) );

    aboutAct = new QAction( tr( "About" ), this );
    aboutAct->setStatusTip( tr( "Mostra le informazioni dell'applicazione") );
    connect( aboutAct, SIGNAL( triggered() ), this, SLOT( about() ) );
}

// METODO AdminWindow::createMenus
void AdminWindow::createMenus() {
    menu = menuBar()->addMenu( tr( "&Menu" ) );
    menu->addAction( exitAct );
    helpMenu = menuBar()->addMenu( tr( "&Help" ) );
    helpMenu->addAction( aboutAct );
}

// SLOT AdminWindow::about
void AdminWindow::about() {
    QMessageBox::about( this, tr("About Menu"), tr(
        "<b>LinQedIn</b>"
        "<p>Progetto per il corso di Programmazione ad Oggetti presso l'Università degli "
        "Studi di Padova.</p>"
        "<p>Lo scopo del progetto era lo sviluppo in C++/Qt di un sistema minimale per "
        "l'amministrazione ed utilizzo tramite interfaccia utente grafica di un (piccolo) "
        "database di contatti professionali ispirato a LinkedIn.</p>" ) );
}
