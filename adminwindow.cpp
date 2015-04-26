#include "adminwindow.h"
#include "linqedin_admin.h"
#include <QMessageBox>
#include <QVBoxLayout>

// NOTE:
// Poichè tutti gli oggetti creati dinamicamente nel costruttore sono figli di un QWidget parent,
// quando questo verrà distrutto, verranno distrutti anche tutti i figli. Per questo motivo quando
// verrà invocata la delete su widget verranno distrutti anche tutti gli oggetti figli. Il parent di
// widget è il widget top-level, quindi quando verrà distrutto quello, anche tutti i figli verranno
// distrutti.

// COSTRUTTORE AdminWindow
AdminWindow::AdminWindow( QWidget *parent ) :
    QMainWindow( parent )
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
    QHBoxLayout *mainLayout = new QHBoxLayout;

    searchWidget = new AdminSearchWidget( mainWidget );
    searchWidget->setFixedWidth( 200 );

    userListWidget = new UserListWidget( adminClient, mainWidget );
    userListWidget->setMinimumWidth( 600 );

    mainLayout->addWidget( searchWidget );
    mainLayout->addWidget( userListWidget );

    mainWidget->setLayout( mainLayout );
    mainWidget->setStyleSheet(
        "background: #069;"
    );

    setCentralWidget( mainWidget );

    setWindowTitle( "LinQedIn Admin" );
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
