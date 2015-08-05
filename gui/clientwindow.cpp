#include "gui/clientwindow.h"
#include "gui/mainwindow.h"
#include "linqedin_client.h"
#include <QMessageBox>

// COSTRUTTORE ClientWindow
ClientWindow::ClientWindow( QString username, QWidget *parent ) :
    QMainWindow( parent ),
    client( new LinQedInClient( username ) )
{
    setupUI();

    this->show();
}

// DISTRUTTORE ClientWindow
ClientWindow::~ClientWindow() {
    delete client;
}

// METODO ClientWindow::setupUI
void ClientWindow::setupUI() {
    createMenuActions();
    createMenus();

    QWidget *mainWidget = new QWidget( this );
    QVBoxLayout *mainLayout = new QVBoxLayout( mainWidget );

    menuWidget = new QWidget( mainWidget );
    menuWidget->setFixedHeight( 50 );
    menuWidget->setStyleSheet( "background: #069" );

    QHBoxLayout* menuLayout = new QHBoxLayout( menuWidget );

    linqedinLabel = new QLabel( "<h2>LinQedIn</h2>", menuWidget );

    profileButton = new MenuButton( tr( "Profile" ), menuWidget );
    connectionsButton = new MenuButton( tr( "Connections" ), menuWidget );
    educationsButton = new MenuButton( tr( "Educations" ), menuWidget );
    experiencesButton = new MenuButton( tr( "Experiences" ), menuWidget );
    setButtonSelected( profileButton );

    QWidget *middleFiller = new QWidget( menuWidget );
    middleFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    openSearchButton = new QPushButton( menuWidget );
    openSearchButton->setIcon( QIcon( QPixmap( ":/icons/icon/magnify.png" ) ) );
    openSearchButton->setFixedSize( 50, 50 );
    openSearchButton->setStyleSheet(
        "QPushButton { border-radius: 25px; outline: 0; }"
        "QPushButton:pressed { background: #3385AD; }"
    );
    connect( openSearchButton, SIGNAL( clicked() ), this, SLOT( openSearchBox() ) );

    searchWidget = new QWidget( menuWidget );
    searchWidget->setFixedHeight( 50 );

    QHBoxLayout *searchLayout = new QHBoxLayout( searchWidget );

    closeSearchButton = new QPushButton( searchWidget );
    closeSearchButton->setIcon( QIcon( QPixmap( ":/icons/icon/close.png" ) ) );
    closeSearchButton->setFixedSize( 50, 50 );
    closeSearchButton->setStyleSheet(
        "QPushButton { border-radius: 25px; outline: 0; }"
        "QPushButton:pressed { background: #3385AD; }"
    );
    connect( closeSearchButton, SIGNAL( clicked() ), this, SLOT( closeSearchBox() ) );
    searchText = new QLineEdit( searchWidget );
    searchText->setPlaceholderText( tr( "Search" ) );
    searchText->setStyleSheet(
        "border: 1px solid white;"
        "border-top: none; border-right: none; border-left: none;"
        "padding: 0 10px;"
        "color: white;"
    );
    searchButton = new QPushButton( searchWidget );
    searchButton->setIcon( QIcon( QPixmap( ":/icons/icon/magnify.png" ) ) );
    searchButton->setFixedSize( 50, 50 );
    searchButton->setStyleSheet(
        "QPushButton { border-radius: 25px; outline: 0; }"
        "QPushButton:pressed { background: #3385AD; }"
    );

    searchLayout->addWidget( closeSearchButton, 0, Qt::AlignVCenter );
    searchLayout->addWidget( searchText, 0, Qt::AlignVCenter );
    searchLayout->addWidget( searchButton, 0, Qt::AlignVCenter );
    searchLayout->setMargin( 0 );

    searchWidget->setLayout( searchLayout );
    searchWidget->setVisible( false );

    menuLayout->addWidget( linqedinLabel, 0, Qt::AlignVCenter );
    menuLayout->addSpacing( 30 );
    menuLayout->addWidget( profileButton, 0, Qt::AlignVCenter );
    menuLayout->addWidget( connectionsButton, 0, Qt::AlignVCenter );
    menuLayout->addWidget( educationsButton, 0, Qt::AlignVCenter );
    menuLayout->addWidget( experiencesButton, 0, Qt::AlignVCenter );
    menuLayout->addWidget( middleFiller );
    menuLayout->addWidget( openSearchButton, 0, Qt::AlignVCenter );
    menuLayout->addWidget( searchWidget, 0, Qt::AlignVCenter );
    menuLayout->setMargin( 0 );
    menuLayout->setContentsMargins( 20, 0, 20, 0 );

    menuWidget->setLayout( menuLayout );
    menuWidget->setStyleSheet( "background: #069" );

    contentWidget = new QWidget( mainWidget );

    QVBoxLayout *contentLayout = new QVBoxLayout( contentWidget );
    contentLayout->setContentsMargins( 10, 10, 10, 10 );

    profileWidget = new ProfileWidget( client->user, contentWidget );

    contentLayout->addWidget( profileWidget );

    contentWidget->setLayout( contentLayout );

    mainLayout->addWidget( menuWidget );
    mainLayout->addWidget( contentWidget );
    mainLayout->setMargin( 0 );
    mainLayout->setSpacing( 0 );

    mainWidget->setLayout( mainLayout );
    mainWidget->setStyleSheet( "background: #EEE; color: white;" );

    setCentralWidget( mainWidget );
    setMinimumSize( 800, 600 );

    setWindowTitle( "LinQedIn Client" );
}

// METODO ClientWindow::createMenuActions
void ClientWindow::createMenuActions() {
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

// METODO ClientWindow::createMenus
void ClientWindow::createMenus() {
    menu = menuBar()->addMenu( tr( "&Menu" ) );
    menu->addAction( logoutAct );
    menu->addAction( exitAct );
    helpMenu = menuBar()->addMenu( tr( "&Help" ) );
    helpMenu->addAction( aboutAct );
}

// METODO ClientWindow::setButtonSelected( QPushButton* )
void ClientWindow::setButtonSelected( QPushButton *buttonSelected ) {
    QPushButton* buttons[4] =
        { profileButton, connectionsButton, educationsButton, experiencesButton };
    for( int i = 0; i < 4; i++ ) {
        if( buttonSelected != buttons[i] ) {
            buttons[i]->setStyleSheet(
                "MenuButton {"
                    "padding: 0 10px;"
                    "border: 3px solid #069;"
                    "outline: 0;"
                "}"
                "MenuButton:hover {"
                    "padding: 0 10px;"
                    "border-bottom-color: white;"
                    "outline: 0;"
                "}"
            );
        } else {
            buttonSelected->setStyleSheet(
                "MenuButton {"
                    "padding: 0 10px;"
                    "border: 3px solid #069;"
                    "border-bottom-color: white;"
                    "outline: 0;"
                "}"
            );
        }
    }
}

// SLOT ClientWindow::logout
void ClientWindow::logout() {
    MainWindow *mainWindow = new MainWindow;

    this->close();
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

// SLOT
void ClientWindow::updateUserInfoSlot( const QString& value, const QString& field ) {
    if( field == "Name" )
        client->user->setName( value );
    else if( field == "Surname" )
        client->user->setSurname( value );
    else if( field == "Maritial Status" )
        client->user->setMaritialStatus( value );
    else {}

    client->db->saveUsersList();
}

// SLOT
void ClientWindow::updateContactsSlot( const QString& un ) {
    client->user->removeContact( un );
    emit updateContactsListSignal( client->user );
    client->db->saveUsersList();
}
