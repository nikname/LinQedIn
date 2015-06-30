#include "gui/adminwindow.h"
#include "gui/mainwindow.h"
#include "../linqedin_admin.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QIcon>
#include <QDebug>

// NOTE:
// Poichè tutti gli oggetti creati dinamicamente nel costruttore sono figli di un QWidget parent,
// quando questo verrà distrutto, verranno distrutti anche tutti i figli. Per questo motivo quando
// verrà invocata la delete su widget verranno distrutti anche tutti gli oggetti figli. Il parent di
// widget è il widget top-level, quindi quando verrà distrutto quello, anche tutti i figli verranno
// distrutti.

// COSTRUTTORE AdminWindow
AdminWindow::AdminWindow( QWidget *parent ) :
    QMainWindow( parent ),
    admin( new LinQedInAdmin() )
{
    initializeGUI();

    this->show();
}

// DISTRUTTORE AdminWindow
AdminWindow::~AdminWindow() {
    delete admin;
}

// METODO AdminWindow::initializeGUI
void AdminWindow::initializeGUI() {
    createMenuActions();
    createMenus();

    QWidget *mainWidget = new QWidget;
    QHBoxLayout *mainLayout = new QHBoxLayout;

    searchWidget = new AdminSearchWidget( mainWidget );
    searchWidget->setFixedWidth( 200 );

    QWidget *rightPanel = new QWidget;
    QVBoxLayout *rightPanelLayout = new QVBoxLayout;

    userListWidget = new UserListWidget( admin->getUsersList(), mainWidget );
    userListWidget->setMinimumWidth( 600 );
    userListWidget->hideColumn( 6 );

    addUserButton = new QPushButton;
    addUserButton->setFixedHeight( 50 );
    addUserButton->setFixedWidth( 50 );
    addUserButton->setIcon( QIcon( QPixmap( ":/icons/icon/account-plus.png" ) ) );
    addUserButton->setStyleSheet(
        "QPushButton { background: #003D5C; border-radius: 25px; }"
        "QPushButton:pressed { background: #00527A; }"
    );
    connect( addUserButton, SIGNAL( clicked() ), this, SLOT( openAddUserDialog() ) );

    rightPanelLayout->addWidget( userListWidget );
    rightPanelLayout->addWidget( addUserButton, 0, Qt::AlignRight );

    rightPanel->setLayout( rightPanelLayout );

    mainLayout->addWidget( searchWidget );
    mainLayout->addWidget( rightPanel );

    mainWidget->setLayout( mainLayout );
    mainWidget->setStyleSheet( "background: #069" );

    connect( this, SIGNAL( updateUserListSignal( LinQedInAdmin* ) ),
             userListWidget, SLOT( updateUserListSlot( LinQedInAdmin* ) ) );
    connect( userListWidget, SIGNAL( updateUserListSignal( const QString& ) ),
             this, SLOT( emitUpdateUserListSignal( const QString& ) ) );
    connect( userListWidget, SIGNAL( updateUserListSignal( const QString&, const QString& ) ),
             this, SLOT( emitUpdateUserListSignal( const QString&, const QString& ) ) );

    setCentralWidget( mainWidget );
    setMinimumHeight( 400 );

    setWindowTitle( "LinQedIn Admin" );
}

// METODO AdminWindow::createMenuActions
void AdminWindow::createMenuActions() {
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

// METODO AdminWindow::createMenus
void AdminWindow::createMenus() {
    menu = menuBar()->addMenu( tr( "&Menu" ) );
    menu->addAction( logoutAct );
    menu->addAction( exitAct );
    helpMenu = menuBar()->addMenu( tr( "&Help" ) );
    helpMenu->addAction( aboutAct );
}

// SLOT AdminWindow::logout
void AdminWindow::logout() {
    MainWindow *mainWindow = new MainWindow;

    this->close();
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

// SLOT AdminWindow::openAddUserDialog
void AdminWindow::openAddUserDialog() {
    AddUserDialog *addUserDialog = new AddUserDialog;
    connect( addUserDialog, SIGNAL( addUserSignal( const SmartUtente& ) ),
             this, SLOT( addUserSlot( const SmartUtente& ) ) );
    addUserDialog->exec();
}

// SLOT AdminWindow::addUserSlot
void AdminWindow::addUserSlot( const SmartUtente& su ) {
    admin->insertUser( su );
    admin->saveDatabase();
    emit updateUserListSignal( admin );
}

// SLOT AdminWindow::emitAddUserSignal
void AdminWindow::emitUpdateUserListSignal( const QString& username ) {
    admin->removeUser( username );
    admin->saveDatabase();
    emit updateUserListSignal( admin );
}

// SLOT
void AdminWindow::emitUpdateUserListSignal( const QString& u, const QString& t ) {
    admin->changeSubscriptionType( u, t );
    admin->saveDatabase();
    emit updateUserListSignal( admin );
}
