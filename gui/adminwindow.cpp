#include <QAction>
#include <QBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>
#include "adduserdialog.h"
#include "adminsearchdialog.h"
#include "adminwindow.h"
#include "loginwindow.h"
#include "userlistwidget.h"
#include "linqedin_admin.h"
#include "utente.h"
#include "utente_basic.h"
#include "utente_business.h"
#include "utente_executive.h"

// COSTRUTTORE AdminWindow
AdminWindow::AdminWindow( QWidget *parent ) :
    LinQedInWindow( parent ),
    statusChanged( false ),
    filterActive( false ),
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

// METODO AdminWindow::closeEvent( QCloseEvent * )
void AdminWindow::closeEvent( QCloseEvent* event ) {
    if( statusChanged ) {
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
    logoutAct = new QAction( tr( "Log Out" ), this );

    userListWidget = new UserListWidget( admin->getUsersList(), this );

    menuWidget = new QWidget( this );

    tableToolsWidget = new QWidget( menuWidget );
    homeButton = new QPushButton( tableToolsWidget );
    linqedinLabel = new QLabel( "<h2>LinQedIn</h2>", tableToolsWidget );
    saveDatabaseButton = new QPushButton( tableToolsWidget );
    connect( saveDatabaseButton, SIGNAL( clicked() ), this, SLOT( saveDatabaseStatus() ) );
    addUserButton = new QPushButton( this );
    connect( addUserButton, SIGNAL( clicked() ), this, SLOT( openAddUserDialog() ) );
    openSearchDialogButton = new QPushButton( this );
    connect( openSearchDialogButton, SIGNAL( clicked() ), this, SLOT( openSearchDialog() ) );

    searchResultsWidget = new QWidget( menuWidget );
    backButton = new QPushButton( tableToolsWidget );
    connect( backButton, SIGNAL( clicked() ), this, SLOT( backToTable() ) );

    userToolsWidget = new QWidget( menuWidget );
    closeUserToolsButton = new QPushButton( userToolsWidget );
    connect( closeUserToolsButton, SIGNAL( clicked() ), this, SLOT( updateMenuToolsButtons() ) );
    connect( closeUserToolsButton, SIGNAL( clicked() ), userListWidget, SLOT( clearSelections() ) );
    openChangeTypeDialogButton = new QPushButton( userToolsWidget );
    connect( openChangeTypeDialogButton, SIGNAL( clicked() ),
             userListWidget, SLOT( openChangeTypeDialog() ) );
    removeUserButton = new QPushButton( userToolsWidget );
    // Rimozione dalla tabella di un utente
    connect( removeUserButton, SIGNAL( clicked() ), userListWidget, SLOT( removeUser() ) );

    // Aggiunta alla tabella del nuovo utente
    connect( this, SIGNAL( addUserSignal( QString, QString, QString, QString ) ),
             userListWidget, SLOT( addUser( QString, QString, QString, QString ) ) );

    // Rimozione dal database di un utente
    connect( userListWidget, SIGNAL( removeUserSignal( QString ) ),
             this, SLOT( removeUserSlot( QString ) ) );

    // Modifica nel database della tipologia dell'account di un utente
    connect( userListWidget, SIGNAL( changeAccountTypeSignal( QString, QString ) ),
             this, SLOT( changeAccountTypeSlot( QString, QString ) ) );

    connect( userListWidget, SIGNAL( selectionChanged( QItemSelection ) ),
            this, SLOT( updateMenuToolsButtons( QItemSelection ) ) );

    connect( this, SIGNAL( restoreTableSignal() ), userListWidget, SLOT( restoreTableSlot() ) );
}

// METODO AdminWindow::setupUI
void AdminWindow::setupUI() {
    createMenuActions();
    createMenus();

    QWidget *centralWidget = new QWidget( this );

    menuWidget->setFixedHeight( 50 );
    menuWidget->setStyleSheet( "background: #069; color: white;" );

    QWidget *buttonsFiller = new QWidget( menuWidget );
    buttonsFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );

    homeButton->setIcon( QIcon( QPixmap( ":/icons/icon/home.png" ) ) );
    setButtonProperties( homeButton );
    openSearchDialogButton->setIcon( QIcon( QPixmap( ":/icons/icon/magnify.png" ) ) );
    setButtonProperties( openSearchDialogButton );
    saveDatabaseButton->setIcon( QIcon( QPixmap( ":/icons/icon/content-save-all.png" ) ) );
    setButtonProperties( saveDatabaseButton );
    addUserButton->setIcon( QIcon( QPixmap( ":/icons/icon/account-plus.png" ) ) );
    setButtonProperties( addUserButton );

    QHBoxLayout *tableToolsLayout = new QHBoxLayout( tableToolsWidget );
    tableToolsLayout->addWidget( homeButton );
    tableToolsLayout->addSpacing( 10 );
    tableToolsLayout->addWidget( linqedinLabel );
    tableToolsLayout->addSpacing( 20 );
    tableToolsLayout->addWidget( buttonsFiller );
    tableToolsLayout->addWidget( saveDatabaseButton );
    tableToolsLayout->addWidget( addUserButton );
    tableToolsLayout->addWidget( openSearchDialogButton );
    tableToolsLayout->setContentsMargins( 0, 0, 0, 0 );

    backButton->setIcon( QIcon( QPixmap( ":/icons/icon/arrow-left" ) ) );
    setButtonProperties( backButton );

    QHBoxLayout *searchResultsLayout = new QHBoxLayout( searchResultsWidget );
    searchResultsLayout->addWidget( backButton, 0, Qt::AlignLeft );
    searchResultsLayout->setContentsMargins( 0, 0, 0, 0 );

    userToolsWidget->setStyleSheet( "background: white" );
    closeUserToolsButton->setIcon( QIcon( QPixmap( ":/icons/icon/close-black.png" ) ) );
    setButtonProperties( closeUserToolsButton, "#EEE" );
    openChangeTypeDialogButton->setIcon( QIcon( QPixmap( ":/icons/icon/account-switch.png" ) ) );
    setButtonProperties( openChangeTypeDialogButton, "#EEE" );
    removeUserButton->setIcon( QIcon( QPixmap( ":/icons/icon/delete.png" ) ) );
    setButtonProperties( removeUserButton, "#EEE" );

    QHBoxLayout *userToolsLayout = new QHBoxLayout( userToolsWidget );
    userToolsLayout->addWidget( closeUserToolsButton );
    userToolsLayout->addWidget( buttonsFiller );
    userToolsLayout->addWidget( openChangeTypeDialogButton );
    userToolsLayout->addWidget( removeUserButton );
    userToolsLayout->setContentsMargins( 0, 0, 0, 0 );

    QHBoxLayout *menuLayout = new QHBoxLayout( menuWidget );
    menuLayout->addWidget( tableToolsWidget );
    menuLayout->addWidget( searchResultsWidget );
    menuLayout->addWidget( userToolsWidget );
    menuLayout->setContentsMargins( 0, 0, 0, 0 );

    searchResultsWidget->setVisible( false );
    userToolsWidget->setVisible( false );
    tableToolsWidget->setVisible( true );

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
    logoutAct->setStatusTip( tr( "Log out dall'applicazione"));
    connect( logoutAct, SIGNAL( triggered() ), this, SLOT( logout() ) );
}

// METODO AdminWindow::createMenus
void AdminWindow::createMenus() {
    menu->insertAction( exitAct, logoutAct );
}

// SLOT AdminWindow::logout
void AdminWindow::logout() {
    this->close();

    new LoginWindow();
}

// SLOT AdminWindow::openAddUserDialog
void AdminWindow::openAddUserDialog() {
    AddUserDialog *addUserDialog = new AddUserDialog( this );
    connect( addUserDialog, SIGNAL( sendUserDetails( QString, QString, QString, QString ) ),
             this, SLOT( addUserSlot( QString, QString, QString, QString ) ) );

    addUserDialog->exec();
}

// SLOT AdminWindow::addUserSlot( QString, QString, QString, QString )
void AdminWindow::addUserSlot( const QString& un, const QString& n,
                               const QString& s, const QString& t )
{
    SmartUtente su;
    if( t == "Basic" ) su = SmartUtente( new UtenteBasic( un, n, s ) );
    if( t == "Executive" ) su = SmartUtente( new UtenteExecutive( un, n, s ) );
    if( t == "Business" ) su = SmartUtente( new UtenteBusiness( un, n, s ) );

    if( admin->insertUser( su ) ) {
        emit addUserSignal( un, n, s, t );
        statusChanged = true;
    } else QMessageBox::information( this, tr( "Duplicate Username" ),
                                     tr( "The username \"%1\" already exists." )
                                     .arg( su->getUsername() ) );
}

// SLOT AdminWindow::removeUserSlot( QString )
void AdminWindow::removeUserSlot( const QString& un ) {
    admin->removeUser( un );
    statusChanged = true;
}

// SLOT AdminWindow::changeAccountTypeSlot( QString, QString )
void AdminWindow::changeAccountTypeSlot( const QString& un, const QString& t ) {
    admin->changeSubscriptionType( un, t );
    statusChanged = true;
}

// SLOT AdminWindow::updateMenuToolsButtons( QItemSelection )
void AdminWindow::updateMenuToolsButtons( const QItemSelection& selection ) {
    QModelIndexList indexes = selection.indexes();

    if( !indexes.isEmpty() ) {
        searchResultsWidget->setVisible( false );
        tableToolsWidget->setVisible( false );
        userToolsWidget->setVisible( true );
    } else {
        userToolsWidget->setVisible( false );
        if( filterActive ) {
            tableToolsWidget->setVisible( false );
            searchResultsWidget->setVisible( true );
        } else {
            searchResultsWidget->setVisible( false );
            tableToolsWidget->setVisible( true );
        }
    }
}

// SLOT AdminWindow::saveDatabaseStatus
void AdminWindow::saveDatabaseStatus() {
    if( statusChanged ) {
        admin->saveDatabase();
        statusChanged = false;
    }
}

// SLOT AdminWindow::openSearchDialog
void AdminWindow::openSearchDialog() {
    AdminSearchDialog *adminSearchDialog = new AdminSearchDialog( this );
    connect( adminSearchDialog, SIGNAL( sendSearchParams( QString, QList<QString>, QList<QString> ) ),
             userListWidget, SLOT( filterTable( QString, QList<QString>, QList<QString> ) ) );
    connect( adminSearchDialog, SIGNAL( sendSearchParams( QString, QList<QString>, QList<QString> ) ),
             this, SLOT( showSearchResultsMenu() ) );

    adminSearchDialog->exec();
}

// SLOT AdminWindow::showSearchResultsMenu
void AdminWindow::showSearchResultsMenu() {
    filterActive = true;
    updateMenuToolsButtons();
}

// SLOT AdminWindow::backToTable
void AdminWindow::backToTable() {
    filterActive = false;
    updateMenuToolsButtons();

    emit restoreTableSignal();
}
