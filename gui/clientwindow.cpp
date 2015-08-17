#include <QAction>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QMessageBox>
#include <QPushButton>
#include <QScrollArea>
#include "clientwindow.h"
#include "linqedin_client.h"
#include "mainwindow.h"
#include "profilewidget.h"

// COSTRUTTORE ClientWindow
ClientWindow::ClientWindow( QString username, QWidget *parent ) :
    QMainWindow( parent ),
    client( new LinQedInClient( username ) )
{
    initUI();
    setupUI();

    this->show();
}

// DISTRUTTORE ClientWindow
ClientWindow::~ClientWindow() {
    delete client;
}

// METODO ClientWindow::closeEvent( QCloseEvent* )
void ClientWindow::closeEvent( QCloseEvent *event ) {
    client->saveUserInfo();

    close();
}

// METODO ClientWindow::initUI
void ClientWindow::initUI() {
    menu = menuBar()->addMenu( tr( "&Menu" ) );
    logoutAct = new QAction( tr( "Log Out" ), this );
    exitAct = new QAction( tr( "Exit" ), this );
    helpMenu = menuBar()->addMenu( tr( "&Help" ) );
    aboutAct = new QAction( tr( "About" ), this );

    homeButton = new QPushButton( this );
    backButton = new QPushButton( this );

    linqedinLabel = new QLabel( "<h2>LinQedIn</h2>", this );

    profileButton = new QPushButton( tr( "Profile" ), this );
    connect( profileButton, SIGNAL( clicked() ), this, SLOT( showProfile() ) );

    sectionButtons.append( profileButton );

    openSearchButton = new QPushButton( this );
    connect( openSearchButton, SIGNAL( clicked() ), this, SLOT( openSearchBox() ) );

    closeSearchButton = new QPushButton( this );
    connect( closeSearchButton, SIGNAL( clicked() ), this, SLOT( closeSearchBox() ) );
    searchText = new QLineEdit( this );
    searchButton = new QPushButton( this );
    connect( searchButton, SIGNAL( clicked() ), this, SLOT( searchUsers() ) );

    profileWidget = new ProfileWidget( client->user, this );
}

// METODO ClientWindow::setupUI
void ClientWindow::setupUI() {
    createMenuActions();
    createMenus();

    QWidget *centralWidget = new QWidget( this );
    centralWidget->setStyleSheet( "background: #EEE" );

    QWidget *menuWidget = new QWidget( this );
    menuWidget->setFixedHeight( 50 );
    menuWidget->setStyleSheet( "background: #069; color: white;" );

    homeButton->setIcon( QIcon( QPixmap( ":/icons/icon/home.png" ) ) );
    setButtonProperties( homeButton );
    backButton->setIcon( QIcon( QPixmap( ":/icons/icon/arrow-left" ) ) );
    setButtonProperties( backButton );
    backButton->setVisible( false );

    setMenuButtonProperties( profileButton );

    setMenuButtonSelected( profileButton );

    QWidget *middleFiller = new QWidget( menuWidget );
    middleFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    openSearchButton->setIcon( QIcon( QPixmap( ":/icons/icon/magnify.png" ) ) );
    setButtonProperties( openSearchButton );

    searchWidget = new QWidget( this );
    searchWidget->setFixedHeight( 50 );
    searchWidget->setVisible( false );

    closeSearchButton->setIcon( QIcon( QPixmap( ":/icons/icon/close.png" ) ) );
    setButtonProperties( closeSearchButton );

    searchText->setPlaceholderText( tr( "Search" ) );
    searchText->setStyleSheet(
        "QLineEdit { border: 1px solid white; border-top: none; border-right: none;"
            "border-left: none; padding: 0 10px; color: white; }"
    );

    searchButton->setIcon( QIcon( QPixmap( ":/icons/icon/magnify.png" ) ) );
    setButtonProperties( searchButton );

    QHBoxLayout *searchLayout = new QHBoxLayout( searchWidget );
    searchLayout->addWidget( closeSearchButton );
    searchLayout->addWidget( searchText );
    searchLayout->addWidget( searchButton );
    searchLayout->setMargin( 0 );

    QHBoxLayout* menuLayout = new QHBoxLayout( menuWidget );
    menuLayout->addWidget( homeButton );
    menuLayout->addWidget( backButton );
    menuLayout->addSpacing( 10 );
    menuLayout->addWidget( linqedinLabel );
    menuLayout->addSpacing( 20 );
    menuLayout->addWidget( profileButton );
    menuLayout->addWidget( middleFiller );
    menuLayout->addWidget( openSearchButton );
    menuLayout->addWidget( searchWidget );
    menuLayout->setContentsMargins( 0, 0, 0, 0 );

    QScrollArea *scrollArea = new QScrollArea( centralWidget );

    QWidget *contentWidget = new QWidget( scrollArea );

    QWidget *contentFiller = new QWidget( contentWidget );
    contentFiller->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Expanding );

    QVBoxLayout *contentLayout = new QVBoxLayout( contentWidget );
    contentLayout->addWidget( profileWidget );
    contentLayout->addWidget( contentFiller );

    scrollArea->setWidget( contentWidget );
    scrollArea->setWidgetResizable( true );
    scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );

    QVBoxLayout *centralLayout = new QVBoxLayout( centralWidget );
    centralLayout->addWidget( menuWidget );
    centralLayout->addWidget( scrollArea );
    centralLayout->setMargin( 0 );
    centralLayout->setSpacing( 0 );

    setStyleSheet(
        "QScrollBar:vertical { padding-left: 2px; width: 6px; }"
        "QScrollBar::handle:vertical { background: rgba(0,0,0,0.38); border-radius: 2px;"
            "min-height: 10px; }"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { border: none; }"
        "QScrollBar:horizontal { padding-top: 2px; height: 6px; }"
        "QScrollBar::handle:horizontal { background: rgba(0,0,0,0.38); border-radius: 2px;"
            "min-height: 10px; }"
        "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal { border: none; }"
    );

    setCentralWidget( centralWidget );
    setWindowTitle( "LinQedIn Client" );
}

// METODO ClientWindow::createMenuActions
void ClientWindow::createMenuActions() {
    logoutAct->setStatusTip( tr( "Log out dall'applicazione"));
    connect( logoutAct, SIGNAL( triggered() ), this, SLOT( logout() ) );

    exitAct->setStatusTip( tr( "Chiudi applicazione" ) );
    connect( exitAct, SIGNAL( triggered() ), this, SLOT( close() ) );

    aboutAct->setStatusTip( tr( "Mostra informazioni sull'applicazione") );
    connect( aboutAct, SIGNAL( triggered() ), this, SLOT( about() ) );
}

// METODO ClientWindow::createMenus
void ClientWindow::createMenus() {
    menu->addAction( logoutAct );
    menu->addAction( exitAct );
    helpMenu->addAction( aboutAct );
}

// METODO ClientWindow::setMenuButtonsProperties
void ClientWindow::setMenuButtonProperties( QPushButton *button ) {
    button->setFixedHeight( 50 );
    button->setStyleSheet(
        "QPushButton { padding: 0 10px; border: 3px solid #069; font: bold; outline: 0; }"
        "QPushButton:hover { border-bottom-color: white; }"
        "QPushButton:pressed { border-bottom-color: white; background: #3385AD; }"
    );
}

// METODO ClientWindow::setMenuButtonSelected
void ClientWindow::setMenuButtonSelected( QPushButton *button ) {
    for( int i = 0; i < sectionButtons.size(); i++ ) {
        QPushButton *aux = sectionButtons[i];
        if( aux ) {
            if( aux == button ) {
                aux->setStyleSheet(
                    "QPushButton { padding: 0 10px; border: 3px solid #069; font: bold; outline: 0;"
                        "border-bottom-color: white; }"
                    "QPushButton:pressed { background: #3385AD; }"
                );
            } else {
                aux->setStyleSheet(
                    "QPushButton { padding: 0 10px; border: 3px solid #069; font: bold;"
                        "outline: 0; }"
                    "QPushButton:hover { border-bottom-color: white; }"
                    "QPushButton:pressed { border-bottom-color: white; background: #3385AD; }"
                );
            }
        } else { } // throw ...
    }
}

// METODO ClientWindow::setButtonProperties( QPushButton* )
void ClientWindow::setButtonProperties( QPushButton* button ) {
    button->setFixedSize( 50, 50 );
    button->setStyleSheet(
        "QPushButton { border-radius: 25px; outline: 0; }"
        "QPushButton:pressed { background: #3385AD; }"
    );
}

// SLOT ClientWindow::logout
void ClientWindow::logout() {
    this->close();

    new MainWindow;
}

// SLOT ClientWindow::about
void ClientWindow::about() {
    QMessageBox::about( this, tr("About Menu"), tr(
        "<b>LinQedIn</b>"
        "<p>Progetto per il corso di Programmazione ad Oggetti presso l'Università degli "
        "Studi di Padova.</p>"
        "<p>Lo scopo del progetto era lo sviluppo in C++/Qt di un sistema minimale per "
        "l'amministrazione ed utilizzo tramite interfaccia utente grafica di un (piccolo) "
        "database di contatti professionali ispirato a LinkedIn.</p>" ) );
}

// SLOT ClientWindow::openSearchBox()
void ClientWindow::openSearchBox() {
    openSearchButton->setVisible( false );
    searchWidget->setVisible( true );
}

// SLOT ClientWindow::closeSearchBox()
void ClientWindow::closeSearchBox() {
    searchWidget->setVisible( false );
    openSearchButton->setVisible( true );
}

// SLOT ClientWindow::showProfile()
void ClientWindow::showProfile() {
    profileWidget->setVisible( true );
    setMenuButtonSelected( profileButton );
}

// SLOT ClientWindow::searchUsers
void ClientWindow::searchUsers() {

}

// SLOT
void ClientWindow::updateContactsSlot( const QString& un ) {
    if( client->db->contains( un ) ) {
        client->user->removeContact( client->db->find( un ) );
        emit updateContactsListSignal( client->user );
        client->db->saveUsersList();
    }
}

