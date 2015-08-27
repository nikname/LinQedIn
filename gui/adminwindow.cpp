#include <QDebug>
#include <QIcon>
#include <QMessageBox>
#include <QVBoxLayout>
#include "adduserdialog.h"
#include "adminsearchwidget.h"
#include "adminwindow.h"
#include "userlistwidget.h"
#include "linqedin_admin.h"
#include "utente.h"

// COSTRUTTORE AdminWindow
AdminWindow::AdminWindow( QWidget *parent ) :
    LinQedInWindow( parent ),
    stateChanged( false ),
    admin( new LinQedInAdmin() )
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
    searchWidget = new AdminSearchWidget( this );
    userListWidget = new UserListWidget( admin->getUsersList(), this );
    saveDatabaseButton = new QPushButton( this );
    connect( saveDatabaseButton, SIGNAL( clicked() ), this, SLOT( saveDatabaseStatus() ) );
    addUserButton = new QPushButton( this );
    connect( addUserButton, SIGNAL( clicked() ), this, SLOT( openAddUserDialog() ) );
}

// METODO AdminWindow::setupUI
void AdminWindow::setupUI() {
    QWidget *centralWidget = new QWidget( this );
    centralWidget->setStyleSheet( "background: #069" );

    searchWidget->setFixedWidth( 200 );

    userListWidget->setMinimumWidth( 600 );
    userListWidget->hideColumn( 6 );

    QWidget *buttonsWidget = new QWidget( this );

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

    QWidget *leftButtonsFiller = new QWidget( buttonsWidget );
    leftButtonsFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Ignored );

    QHBoxLayout *buttonsLayout = new QHBoxLayout( buttonsWidget );
    buttonsLayout->addWidget( leftButtonsFiller );
    buttonsLayout->addWidget( saveDatabaseButton );
    buttonsLayout->addWidget( addUserButton );

    QWidget *usersListPanel = new QWidget( centralWidget );
    usersListPanel->setStyleSheet( "background: white" );

    QVBoxLayout *usersListPanelLayout = new QVBoxLayout( usersListPanel );
    usersListPanelLayout->addWidget( userListWidget );
    usersListPanelLayout->addWidget( buttonsWidget );
    usersListPanelLayout->setMargin( 0 );

    QHBoxLayout *layout = new QHBoxLayout( centralWidget );
    layout->addWidget( searchWidget );
    layout->addWidget( usersListPanel );
    layout->setMargin( 0 );

    connect( this, SIGNAL( databaseStatusChangedSignal() ),
             this, SLOT( databaseStatusChangedSlot() ) );

    connect( this, SIGNAL( updateUsersListSignal( LinQedInAdmin*, QString ) ),
             userListWidget, SLOT( updateUserListSlot( LinQedInAdmin*, QString ) ) );
    connect( userListWidget, SIGNAL( updateListUserRemovedSignal( const QString& ) ),
             this, SLOT( updateListUserRemovedSlot( const QString& ) ) );
    connect( userListWidget, SIGNAL( updateListUserTypeSignal( const QString&, const QString& ) ),
             this, SLOT( updateListUserTypeSlot( const QString&, const QString& ) ) );

    setCentralWidget( centralWidget );
    setMinimumHeight( 400 );
    setWindowTitle( "LinQedIn Admin" );
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
