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
#include "utente_basic.h"
#include "utente_business.h"
#include "utente_executive.h"

// COSTRUTTORE AdminWindow
AdminWindow::AdminWindow( QWidget *parent ) :
    QMainWindow( parent ),
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
    QMessageBox::StandardButton closeDialog;
    closeDialog = QMessageBox::warning( this, tr( "Database status" ),
        tr( "Save database status before quit?" ), QMessageBox::Yes | QMessageBox::No );
    if( closeDialog == QMessageBox::Yes )
        admin->saveDatabase();

    close();
}

// METODO AdminWindow::initUI
void AdminWindow::initUI() {
    menuWidget = new QWidget( this );

    tableToolsWidget = new QWidget( menuWidget );

    homeButton = new QPushButton( tableToolsWidget );
    backButton = new QPushButton( tableToolsWidget );

    linqedinLabel = new QLabel( "<h2>LinQedIn</h2>", tableToolsWidget );

    saveDatabaseButton = new QPushButton( tableToolsWidget );
    connect( saveDatabaseButton, SIGNAL( clicked() ), this, SLOT( saveDatabaseStatus() ) );
    addUserButton = new QPushButton( this );
    connect( addUserButton, SIGNAL( clicked() ), this, SLOT( openAddUserDialog() ) );
    openSearchDialogButton = new QPushButton( this );
    connect( openSearchDialogButton, SIGNAL( clicked() ), this, SLOT( openSearchDialog() ) );

    userListWidget = new UserListWidget( admin->getUsersList(), this );

    userToolsWidget = new QWidget( menuWidget );

    closeUserToolsButton = new QPushButton( userToolsWidget );
    connect( closeUserToolsButton, SIGNAL( clicked() ), this, SLOT( hideUserToolsButtons() ) );
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
    backButton->setIcon( QIcon( QPixmap( ":/icons/icon/arrow-left" ) ) );
    setButtonProperties( backButton );
    backButton->setVisible( false );

    openSearchDialogButton->setIcon( QIcon( QPixmap( ":/icons/icon/magnify.png" ) ) );
    setButtonProperties( openSearchDialogButton );

    saveDatabaseButton->setIcon( QIcon( QPixmap( ":/icons/icon/content-save-all.png" ) ) );
    setButtonProperties( saveDatabaseButton );

    addUserButton->setIcon( QIcon( QPixmap( ":/icons/icon/account-plus.png" ) ) );
    setButtonProperties( addUserButton );

    QHBoxLayout *tableToolsLayout = new QHBoxLayout( tableToolsWidget );
    tableToolsLayout->addWidget( homeButton );
    tableToolsLayout->addWidget( backButton );
    tableToolsLayout->addSpacing( 10 );
    tableToolsLayout->addWidget( linqedinLabel );
    tableToolsLayout->addSpacing( 20 );
    tableToolsLayout->addWidget( buttonsFiller );
    tableToolsLayout->addWidget( saveDatabaseButton );
    tableToolsLayout->addWidget( addUserButton );
    tableToolsLayout->addWidget( openSearchDialogButton );
    tableToolsLayout->setContentsMargins( 0, 0, 0, 0 );

    userToolsWidget->setStyleSheet( "background: white" );

    closeUserToolsButton->setIcon( QIcon( QPixmap( ":/icons/icon/close-black.png" ) ) );
    setButtonProperties( closeUserToolsButton, "#EEE" );

    openChangeTypeDialogButton->setIcon(
                QIcon( QPixmap( ":/icons/icon/account-switch.png" ) ) );
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
    menuLayout->addWidget( userToolsWidget );
    menuLayout->setContentsMargins( 0, 0, 0, 0 );

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
void AdminWindow::setButtonProperties( QPushButton* button, const QString& pressed_color ) {
    button->setFixedSize( 50, 50 );
    QString style = QString(
        "QPushButton { border-radius: 25px; outline: 0; }"
        "QPushButton:pressed { background: %1; }"
    ).arg( pressed_color );

    button->setStyleSheet( style );
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

// SLOT AdminWindow::openAddUserDialog
void AdminWindow::openAddUserDialog() {
    AddUserDialog *addUserDialog = new AddUserDialog( this );
    connect( addUserDialog, SIGNAL( sendUserDetails( QString, QString, QString, QString ) ),
             this, SLOT( addUserSlot( QString, QString, QString, QString ) ) );

    addUserDialog->exec();
}

// SLOT AdminWindow::addUserSlot
void AdminWindow::addUserSlot( const QString& un, const QString& n,
                               const QString& s, const QString& t )
{
    SmartUtente su;
    if( t == "Basic" ) su = SmartUtente( new UtenteBasic( un, n, s ) );
    if( t == "Executive" ) su = SmartUtente( new UtenteExecutive( un, n, s ) );
    if( t == "Business" ) su = SmartUtente( new UtenteBusiness( un, n, s ) );

    if( admin->insertUser( su ) )
        emit addUserSignal( un, n, s, t );
    else QMessageBox::information( this, tr( "Duplicate Username" ),
                                     tr( "The username \"%1\" already exists." )
                                     .arg( su->getUsername() ) );
}

// SLOT AdminWindow::removeUserSlot
void AdminWindow::removeUserSlot( const QString& un ) {
    admin->removeUser( un );
}

// SLOT AdminWindow::changeAccountTypeSlot
void AdminWindow::changeAccountTypeSlot( const QString& un, const QString& t ) {
    admin->changeSubscriptionType( un, t );
}

// SLOT AdminWindow::updateMenuToolsButtons
void AdminWindow::updateMenuToolsButtons( const QItemSelection& selection ) {
    QModelIndexList indexes = selection.indexes();

    if( !indexes.isEmpty() ) {
        tableToolsWidget->setVisible( false );
        userToolsWidget->setVisible( true );
    } else hideUserToolsButtons();
}

// SLOT AdminWindow::hideUserToolsButtons
void AdminWindow::hideUserToolsButtons() {
    userToolsWidget->setVisible( false );
    tableToolsWidget->setVisible( true );
}

// SLOT AdminWindow::saveDatabaseStatus
void AdminWindow::saveDatabaseStatus() {
    admin->saveDatabase();
}

// SLOT AdminWindow::openSearchDialog
void AdminWindow::openSearchDialog() {
    AdminSearchDialog *adminSearchDialog = new AdminSearchDialog( this );

    adminSearchDialog->exec();
}
