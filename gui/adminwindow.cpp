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

    homeButton = new QPushButton( this );
    backButton = new QPushButton( this );

    linqedinLabel = new QLabel( "<h2>LinQedIn</h2>", this );

    userListWidget = new UserListWidget( admin->getUsersList(), this );

    openChangeTypeDialogButton = new QPushButton( this );
    connect( openChangeTypeDialogButton, SIGNAL( clicked() ),
             this, SLOT( openChangeTypeDialog() ) );

    removeUserButton = new QPushButton( this );
    //connect( removeUserButton, SIGNAL( clicked() ), this, SLOT() );

    saveDatabaseButton = new QPushButton( this );
    connect( saveDatabaseButton, SIGNAL( clicked() ), this, SLOT( saveDatabaseStatus() ) );

    addUserButton = new QPushButton( this );
    connect( addUserButton, SIGNAL( clicked() ), this, SLOT( openAddUserDialog() ) );

    openSearchDialogButton = new QPushButton( this );
    connect( openSearchDialogButton, SIGNAL( clicked() ), this, SLOT( openSearchDialog() ) );

    connect( this, SIGNAL( addUserTableSignal( SmartUtente ) ),
             userListWidget, SLOT( addUserTableSlot( SmartUtente ) ) );
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

// SLOT AdminWindow::openChangeTypeDialog
void AdminWindow::openChangeTypeDialog() {

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
        emit addUserTableSignal( su );
    else QMessageBox::information( this, tr( "Duplicate Username" ),
                                     tr( "The username \"%1\" already exists." )
                                     .arg( su->getUsername() ) );
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
