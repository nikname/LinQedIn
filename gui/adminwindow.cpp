#include <QDebug>
#include <QIcon>
#include <QMenuBar>
#include <QMessageBox>
#include <QVBoxLayout>

#include "gui/adduserdialog.h"
#include "gui/adminsearch_widget.h"
#include "gui/adminwindow.h"
#include "gui/mainwindow.h"
#include "gui/userlist_widget.h"
#include "linqedin_admin.h"
#include "smartutente.h"

// COSTRUTTORE AdminWindow
AdminWindow::AdminWindow( QWidget *parent ) :
    QMainWindow( parent ),
    admin( new LinQedInAdmin() )
{
    setupUI();

    this->show();
}

// DISTRUTTORE AdminWindow
AdminWindow::~AdminWindow() {
    delete admin;
}

// METODO AdminWindow::setupUI
void AdminWindow::setupUI() {
    createMenuActions();
    createMenus();

    QWidget *mainWidget = new QWidget( this );

    QHBoxLayout *layout = new QHBoxLayout( mainWidget );

    searchWidget = new AdminSearchWidget( mainWidget );
    searchWidget->setFixedWidth( 200 );

    QWidget *rightPanel = new QWidget( mainWidget );
    QVBoxLayout *rightPanelLayout = new QVBoxLayout( rightPanel );

    userListWidget = new UserListWidget( admin->getUsersList(), mainWidget );
    userListWidget->setMinimumWidth( 600 );
    userListWidget->hideColumn( 6 );

    addUserButton = new QPushButton( mainWidget );
    addUserButton->setFixedSize( 50, 50 );
    addUserButton->setIcon( QIcon( QPixmap( ":/icons/icon/account-plus.png" ) ) );
    addUserButton->setStyleSheet(
        "QPushButton { background: #003D5C; border-radius: 25px; }"
        "QPushButton:pressed { background: #00527A; }"
    );
    connect( addUserButton, SIGNAL( clicked() ), this, SLOT( openAddUserDialog() ) );

    rightPanelLayout->addWidget( userListWidget );
    rightPanelLayout->addWidget( addUserButton, 0, Qt::AlignRight );

    rightPanel->setLayout( rightPanelLayout );

    layout->addWidget( searchWidget );
    layout->addWidget( rightPanel );

    mainWidget->setLayout( layout );
    mainWidget->setStyleSheet( "background: #069" );

    connect( this, SIGNAL( updateUsersListSignal( LinQedInAdmin* ) ),
             userListWidget, SLOT( updateUserListSlot( LinQedInAdmin* ) ) );
    connect( userListWidget, SIGNAL( updateUserListSignal( const QString& ) ),
             this, SLOT( updateListUserRemoved( const QString& ) ) );
    connect( userListWidget, SIGNAL( updateUserListSignal( const QString&, const QString& ) ),
             this, SLOT( updateListUserModified( const QString&, const QString& ) ) );

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
    new MainWindow;

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

// SLOT AdminWindow::addUserSlot( SmartUtente )
void AdminWindow::addUserSlot( const SmartUtente& su ) {
    admin->insertUser( su );
    admin->saveDatabase();
    emit updateUsersListSignal( admin );
}

// SLOT AdminWindow::updateListUserRemoved( QString )
void AdminWindow::updateListUserRemoved( const QString& username ) {
    admin->removeUser( username );
    admin->saveDatabase();
    emit updateUsersListSignal( admin );
}

// SLOT AdminWindow::updateListUserModified( QString, QString )
void AdminWindow::updateListUserModified( const QString& u, const QString& t ) {
    admin->changeSubscriptionType( u, t );
    admin->saveDatabase();
    emit updateUsersListSignal( admin );
}
