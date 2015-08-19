#include <QDebug>
#include <QIcon>
#include <QMenuBar>
#include <QMessageBox>
#include <QVBoxLayout>

#include "gui/adduserdialog.h"
#include "gui/adminsearchwidget.h"
#include "gui/adminwindow.h"
#include "gui/mainwindow.h"
#include "gui/userlistwidget.h"
#include "linqedin_admin.h"
#include "smartutente.h"
#include "utente.h"

// COSTRUTTORE AdminWindow
AdminWindow::AdminWindow( QWidget *parent ) :
    QMainWindow( parent ),
    admin( new LinQedInAdmin() )
{
    stateChanged = false;

    menu = menuBar()->addMenu( tr( "&Menu" ) );
    helpMenu = menuBar()->addMenu( tr( "&Help" ) );
    logoutAct = new QAction( tr( "Log Out" ), this );
    exitAct = new QAction( tr( "Exit" ), this );
    aboutAct = new QAction( tr( "About" ), this );

    mainWidget = new QWidget( this );

    searchWidget = new AdminSearchWidget( mainWidget );
    userListWidget = new UserListWidget( admin->getUsersList(), mainWidget );
    saveDatabaseButton = new QPushButton( mainWidget );
    addUserButton = new QPushButton( mainWidget );

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

// METODO AdminWindow::setupUI
void AdminWindow::setupUI() {
    createMenuActions();
    createMenus();

    QHBoxLayout *layout = new QHBoxLayout( mainWidget );

    searchWidget->setFixedWidth( 200 );

    QWidget *rightPanel = new QWidget( mainWidget );
    QVBoxLayout *rightPanelLayout = new QVBoxLayout( rightPanel );

    userListWidget->setMinimumWidth( 600 );
    userListWidget->hideColumn( 6 );

    QWidget *buttonsWidget = new QWidget( this );
    QHBoxLayout *buttonsLayout = new QHBoxLayout( buttonsWidget );

    saveDatabaseButton->setFixedSize( 50, 50 );
    saveDatabaseButton->setIcon( QIcon( QPixmap( ":/icons/icon/content-save-all.png" ) ) );
    saveDatabaseButton->setStyleSheet(
        "QPushButton { background: #003D5C; border-radius: 25px; }"
        "QPushButton:pressed { background: #00527A; }"
    );
    connect( saveDatabaseButton, SIGNAL( clicked() ), this, SLOT( saveDatabaseStatus() ) );

    addUserButton->setFixedSize( 50, 50 );
    addUserButton->setIcon( QIcon( QPixmap( ":/icons/icon/account-plus.png" ) ) );
    addUserButton->setStyleSheet(
        "QPushButton { background: #003D5C; border-radius: 25px; }"
        "QPushButton:pressed { background: #00527A; }"
    );
    connect( addUserButton, SIGNAL( clicked() ), this, SLOT( openAddUserDialog() ) );

    QWidget *leftButtonsFiller = new QWidget( buttonsWidget );
    leftButtonsFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Ignored );

    buttonsLayout->addWidget( leftButtonsFiller );
    buttonsLayout->addWidget( saveDatabaseButton );
    buttonsLayout->addWidget( addUserButton );

    buttonsWidget->setLayout( buttonsLayout );

    rightPanelLayout->addWidget( userListWidget );
    rightPanelLayout->addWidget( buttonsWidget );
    rightPanelLayout->setMargin( 0 );

    rightPanel->setLayout( rightPanelLayout );
    rightPanel->setStyleSheet( "background: white" );

    layout->addWidget( searchWidget );
    layout->addWidget( rightPanel );
    layout->setMargin( 0 );

    mainWidget->setLayout( layout );
    mainWidget->setStyleSheet( "background: #069" );

    connect( this, SIGNAL( databaseStatusChangedSignal() ),
             this, SLOT( databaseStatusChangedSlot() ) );

    connect( this, SIGNAL( updateUsersListSignal( LinQedInAdmin*, QString ) ),
             userListWidget, SLOT( updateUserListSlot( LinQedInAdmin*, QString ) ) );
    connect( userListWidget, SIGNAL( updateListUserRemovedSignal( const QString& ) ),
             this, SLOT( updateListUserRemovedSlot( const QString& ) ) );
    connect( userListWidget, SIGNAL( updateListUserTypeSignal( const QString&, const QString& ) ),
             this, SLOT( updateListUserTypeSlot( const QString&, const QString& ) ) );

    setCentralWidget( mainWidget );
    setMinimumHeight( 400 );
    setWindowTitle( "LinQedIn Admin" );
}

// METODO AdminWindow::createMenuActions
void AdminWindow::createMenuActions() {
    logoutAct->setStatusTip( tr( "Log out dall'applicazione"));
    connect( logoutAct, SIGNAL( triggered() ), this, SLOT( logout() ) );

    exitAct->setStatusTip( tr( "Chiudi applicazione" ) );
    connect( exitAct, SIGNAL( triggered() ), this, SLOT( close() ) );

    aboutAct->setStatusTip( tr( "Mostra informazioni sull'applicazione") );
    connect( aboutAct, SIGNAL( triggered() ), this, SLOT( about() ) );
}

// METODO AdminWindow::createMenus
void AdminWindow::createMenus() {
    menu->addAction( logoutAct );
    menu->addAction( exitAct );
    helpMenu->addAction( aboutAct );
}

// SLOT AdminWindow::logout
void AdminWindow::logout() {
    this->close();

    new MainWindow;
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
