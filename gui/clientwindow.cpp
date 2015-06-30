#include "gui/clientwindow.h"
#include "gui/mainwindow.h"
#include "linqedin_client.h"
#include <QMessageBox>

// COSTRUTTORE ClientWindow
ClientWindow::ClientWindow( QString username, QWidget *parent ) :
    QMainWindow( parent ),
    client( new LinQedInClient( username ) )
{
    initializeGUI();

    this->show();
}

// DISTRUTTORE ClientWindow
ClientWindow::~ClientWindow() {
    delete client;
}

// METODO ClientWindow::initializeGUI
void ClientWindow::initializeGUI() {
    createMenuActions();
    createMenus();

    QWidget *mainWidget = new QWidget( this );
    QHBoxLayout *mainLayout = new QHBoxLayout( mainWidget );

    userSearchWidget = new UserSearchWidget( this );
    userSearchWidget->setFixedWidth( 200 );

    tabWidget = new QTabWidget( this );
    tabWidget->setMinimumWidth( 400 );
    tabWidget->setStyleSheet( "background: white" );

    tabProfilo = new TabProfilo( client->user );

    tabWidget->addTab( tabProfilo, tr( "Profilo" ) );
    //tabWidget->addTab( new TabRete(), tr( "Net" ) );
    //tabWidget->addTab( new TabFormazione(), tr( "Education" ) );
    //tabWidget->addTab( new TabEsperienza(), tr( "Experience" ) );

    connect( tabProfilo, SIGNAL( updateUserInfoSignal( const QString&, const QString& ) ),
             this, SLOT( updateUserInfoSlot( const QString&, const QString& ) ) );

    mainLayout->addWidget( userSearchWidget );
    mainLayout->addWidget( tabWidget );

    mainWidget->setLayout( mainLayout );
    mainWidget->setStyleSheet( "background: #069" );

    setCentralWidget( mainWidget );
    setMinimumHeight( 400 );

    setWindowTitle( "LinQedIn Client" );
}

// METODO ClientWindow::createMenuActions
void ClientWindow::createMenuActions() {
    logoutAct = new QAction( tr( "Log Out" ), this );
    logoutAct->setStatusTip( tr( "Log out dall'applicazione"));
    connect( logoutAct, SIGNAL( triggered() ), this, SLOT( logout() ) );

    exitAct = new QAction( tr( "Exit" ), this );
    exitAct->setStatusTip( tr( "Chiudi applicazione" ) );
    connect( exitAct, SIGNAL( triggered() ), this, SLOT( close() ) );

    aboutAct = new QAction( tr( "About" ), this );
    aboutAct->setStatusTip( tr( "Mostra informazioni sull'applicazione") );
    connect( aboutAct, SIGNAL( triggered() ), this, SLOT( about() ) );
}

// METODO ClientWindow::createMenus
void ClientWindow::createMenus() {
    menu = menuBar()->addMenu( tr( "&Menu" ) );
    menu->addAction( logoutAct );
    menu->addAction( exitAct );
    helpMenu = menuBar()->addMenu( tr( "&Help" ) );
    helpMenu->addAction( aboutAct );
}

// SLOT ClientWindow::logout
void ClientWindow::logout() {
    MainWindow *mainWindow = new MainWindow;

    this->close();
}

// SLOT ClientWindow::about
void ClientWindow::about() {
    QMessageBox::about( this, tr("About Menu"), tr(
        "<b>LinQedIn</b>"
        "<p>Progetto per il corso di Programmazione ad Oggetti presso l'Università degli "
        "Studi di Padova.</p>"
        "<p>Lo scopo del progetto era lo sviluppo in C++/Qt di un sistema minimale per "
        "l'amministrazione ed utilizzo tramite interfaccia utente grafica di un (piccolo) "
        "database di contatti professionali ispirato a LinkedIn.</p>" ) );
}

// SLOT
void ClientWindow::updateUserInfoSlot( const QString& value, const QString& field ) {
    if( field == "Name" )
        client->user->setName( value );
    else if( field == "Surname" )
        client->user->setSurname( value );
    else if( field == "Maritial Status" )
        client->user->setMaritialStatus( value );
    else {}

    client->db->saveUsersList();
}
