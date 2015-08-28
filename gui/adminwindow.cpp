#include <QDebug>
#include <QIcon>
#include <QLabel>
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
    menuWidget = new QWidget( this );

    homeButton = new QPushButton( this );
    backButton = new QPushButton( this );

    linqedinLabel = new QLabel( "<h2>LinQedIn</h2>", this );

    userListWidget = new UserListWidget( admin->getUsersList(), this );

    openSearchDialogButton = new QPushButton( this );
    connect( openSearchDialogButton, SIGNAL( clicked() ), this, SLOT( openSearchDialog() ) );

    saveDatabaseButton = new QPushButton( this );
    connect( saveDatabaseButton, SIGNAL( clicked() ), this, SLOT( saveDatabaseStatus() ) );

    addUserButton = new QPushButton( this );
    connect( addUserButton, SIGNAL( clicked() ), this, SLOT( openAddUserDialog() ) );

    connect( this, SIGNAL( updateUsersListSignal( LinQedInAdmin*, QString ) ),
             userListWidget, SLOT( updateUserListSlot( LinQedInAdmin*, QString ) ) );
    connect( userListWidget, SIGNAL( updateListUserRemovedSignal( const QString& ) ),
             this, SLOT( updateListUserRemovedSlot( const QString& ) ) );
    connect( userListWidget, SIGNAL( updateListUserTypeSignal( const QString&, const QString& ) ),
             this, SLOT( updateListUserTypeSlot( const QString&, const QString& ) ) );

    connect( this, SIGNAL( databaseStatusChangedSignal() ),
             this, SLOT( databaseStatusChangedSlot() ) );
}

// METODO AdminWindow::setupUI
void AdminWindow::setupUI() {
    createMenuActions();
    createMenus();

    QWidget *centralWidget = new QWidget( this );

    menuWidget->setFixedHeight( 50 );
    menuWidget->setStyleSheet( "background: #069; color: white;" );

    homeButton->setIcon( QIcon( QPixmap( ":/icons/icon/home.png" ) ) );
    setButtonProperties( homeButton );
    backButton->setIcon( QIcon( QPixmap( ":/icons/icon/arrow-left" ) ) );
    setButtonProperties( backButton );
    backButton->setVisible( false );

    QWidget *middleFiller = new QWidget( menuWidget );
    middleFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    openSearchDialogButton->setIcon( QIcon( QPixmap( ":/icons/icon/magnify.png" ) ) );
    setButtonProperties( openSearchDialogButton );

    saveDatabaseButton->setIcon( QIcon( QPixmap( ":/icons/icon/content-save-all.png" ) ) );
    setButtonProperties( saveDatabaseButton );

    addUserButton->setIcon( QIcon( QPixmap( ":/icons/icon/account-plus.png" ) ) );
    setButtonProperties( addUserButton );

    QWidget *buttonsFiller = new QWidget( menuWidget );
    buttonsFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );

    QHBoxLayout *menuLayout = new QHBoxLayout( menuWidget );
    menuLayout->addWidget( homeButton );
    menuLayout->addWidget( backButton );
    menuLayout->addSpacing( 10 );
    menuLayout->addWidget( linqedinLabel );
    menuLayout->addSpacing( 20 );
    menuLayout->addWidget( buttonsFiller );
    menuLayout->addWidget( saveDatabaseButton );
    menuLayout->addWidget( addUserButton );
    menuLayout->addWidget( openSearchDialogButton );
    menuLayout->setContentsMargins( 0, 0, 0, 0 );

    QVBoxLayout *layout = new QVBoxLayout( centralWidget );
    layout->addWidget( menuWidget );
    layout->addWidget( userListWidget );
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

// METODO AdminWindow::setButtonProperties( QPushButton* )
void AdminWindow::setButtonProperties( QPushButton* button ) {
    button->setFixedSize( 50, 50 );
    button->setStyleSheet(
        "QPushButton { border-radius: 25px; outline: 0; }"
        "QPushButton:pressed { background: #3385AD; }"
    );
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
