#include <QDebug>
#include <QIcon>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include "adduserdialog.h"
#include "adminsearchdialog.h"
#include "adminwindow.h"
#include "mainwindow.h"
#include "userlistwidget.h"
#include "linqedin_admin.h"
#include "utente.h"

// COSTRUTTORE AdminWindow
AdminWindow::AdminWindow( QWidget *parent ) :
    QMainWindow( parent ),
    admin( new LinQedInAdmin() ),
    stateChanged( false )
{
    initUI();
    setupUI();

    this->show();
}

// DISTRUTTORE AdminWindow
AdminWindow::~AdminWindow() {
    delete admin;
}

// METODO AdminWindow::closeEvent
void AdminWindow::closeEvent( QCloseEvent* event ) {
    if( stateChanged ) {
        QMessageBox::StandardButton closeDialog;
        closeDialog = QMessageBox::warning( this, tr( "Database status" ),
            tr( "Save database status before quit?" ), QMessageBox::Yes | QMessageBox::No );
        if( closeDialog == QMessageBox::Yes )
            admin->saveDatabase();
    }
    close();
}

// METODO AdminWindow::initUI
void AdminWindow::initUI() {
    userListWidget = new UserListWidget( admin->getUsersList(), this );
    userListWidget->hideColumn( 6 ); // ***

    connect( this, SIGNAL( updateUsersListSignal( LinQedInAdmin*, QString ) ),
             userListWidget, SLOT( updateUserListSlot( LinQedInAdmin*, QString ) ) );
    connect( userListWidget, SIGNAL( updateListUserRemovedSignal( const QString& ) ),
             this, SLOT( updateListUserRemovedSlot( const QString& ) ) );
    connect( userListWidget, SIGNAL( updateListUserTypeSignal( const QString&, const QString& ) ),
             this, SLOT( updateListUserTypeSlot( const QString&, const QString& ) ) );

    openSearchDialogButton = new QPushButton( this );
    connect( openSearchDialogButton, SIGNAL( clicked() ), this, SLOT( openSearchDialog() ) );

    saveDatabaseButton = new QPushButton( this );
    connect( saveDatabaseButton, SIGNAL( clicked() ), this, SLOT( saveDatabaseStatus() ) );

    addUserButton = new QPushButton( this );
    connect( addUserButton, SIGNAL( clicked() ), this, SLOT( openAddUserDialog() ) );

    connect( this, SIGNAL( databaseStatusChangedSignal() ),
             this, SLOT( databaseStatusChangedSlot() ) );
}

// METODO AdminWindow::setupUI
void AdminWindow::setupUI() {
    createMenuActions();
    createMenus();

    QWidget *centralWidget = new QWidget( this );

    QWidget *buttonsWidget = new QWidget( this );

    openSearchDialogButton->setFixedSize( 50, 50 );
    openSearchDialogButton->setIcon( QIcon( QPixmap( ":/icons/icon/magnify.png" ) ) );
    openSearchDialogButton->setStyleSheet(
        "QPushButton { background: #003D5C; border-radius: 25px; }"
        "QPushButton:pressed { background: #00527A; }"
    );

    saveDatabaseButton->setFixedSize( 50, 50 );
    saveDatabaseButton->setIcon( QIcon( QPixmap( ":/icons/icon/content-save-all.png" ) ) );
    saveDatabaseButton->setStyleSheet(
        "QPushButton { background: #003D5C; border-radius: 25px; }"
        "QPushButton:pressed { background: #00527A; }"
    );

    addUserButton->setFixedSize( 50, 50 );
    addUserButton->setIcon( QIcon( QPixmap( ":/icons/icon/account-plus.png" ) ) );
    addUserButton->setStyleSheet(
        "QPushButton { background: #003D5C; border-radius: 25px; }"
        "QPushButton:pressed { background: #00527A; }"
    );

    QWidget *buttonsFiller = new QWidget( buttonsWidget );
    buttonsFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );

    QHBoxLayout *buttonsLayout = new QHBoxLayout( buttonsWidget );
    buttonsLayout->addWidget( openSearchDialogButton );
    buttonsLayout->addWidget( buttonsFiller );
    buttonsLayout->addWidget( saveDatabaseButton );
    buttonsLayout->addWidget( addUserButton );

    QVBoxLayout *layout = new QVBoxLayout( centralWidget );
    layout->addWidget( userListWidget );
    layout->addWidget( buttonsWidget );
    layout->setMargin( 0 );
    layout->setSpacing( 0 );

    setCentralWidget( centralWidget );
    setMinimumSize( 600, 400 );
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
    this->close();

    new MainWindow();
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

// SLOT AdminWindow::openSearchDialog
void AdminWindow::openSearchDialog() {
    AdminSearchDialog *adminSearchDialog = new AdminSearchDialog( this );

    adminSearchDialog->exec();
}

// SLOT AdminWindow::openAddUserDialog
void AdminWindow::openAddUserDialog() {
    AddUserDialog *addUserDialog = new AddUserDialog;
    connect( addUserDialog, SIGNAL( userToAddSignal( const SmartUtente& ) ),
             this, SLOT( userToAddSlot( const SmartUtente& ) ) );
    addUserDialog->exec();
}

// SLOT AdminWindow::saveDatabaseStatus
void AdminWindow::saveDatabaseStatus() {
    if( stateChanged ) {
        admin->saveDatabase();
        stateChanged = false;
        setWindowTitle( windowTitle().remove( 0, 1 ) );
    }
}

// SLOT AdminWindow::userToAddSlot( SmartUtente )
void AdminWindow::userToAddSlot( const SmartUtente& su ) {
    admin->insertUser( su );
    emit updateUsersListSignal( admin, su->getUsername() );
    emit databaseStatusChangedSignal();
}

// SLOT AdminWindow::updateListUserRemovedSlot( QString )
void AdminWindow::updateListUserRemovedSlot( const QString& username ) {
    admin->removeUser( username );
    emit databaseStatusChangedSignal();
}

// SLOT AdminWindow::updateListUserTypeSlot( QString, QString )
void AdminWindow::updateListUserTypeSlot( const QString& u, const QString& t ) {
    admin->changeSubscriptionType( u, t );
    emit updateUsersListSignal( admin, u );
    emit databaseStatusChangedSignal();
}

// SLOT AdminWindow::databaseStatusChangedSlot()
void AdminWindow::databaseStatusChangedSlot() {
    if( !stateChanged ) {
        stateChanged = true;
        setWindowTitle( "*" + windowTitle() );
    }
}
