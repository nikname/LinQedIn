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

    topBarWidget = new QWidget( mainWidget );
    topBarWidget->setFixedHeight( 50 );
    topBarWidget->setStyleSheet( "background: #069" );

    QHBoxLayout *topBarLayout = new QHBoxLayout( topBarWidget );

    linqedinLabel = new QLabel( "<h2>LinQedIn</h2>", topBarWidget );

    menuWidget = new QWidget( topBarWidget );
    menuWidget->setFixedHeight( 50 );

    QHBoxLayout* menuLayout = new QHBoxLayout( menuWidget );

    profileButton = new MenuButton( tr( "Profile" ), menuWidget );
    connectionsButton = new MenuButton( tr( "Connections" ), menuWidget );
    educationsButton = new MenuButton( tr( "Educations" ), menuWidget );
    experiencesButton = new MenuButton( tr( "Experiences" ), menuWidget );
    setButtonSelected( profileButton );

    QWidget *middleFiller = new QWidget( menuWidget );
    middleFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    openSearchButton = new QPushButton( menuWidget );
    openSearchButton->setIcon( QIcon( QPixmap( ":/icons/icon/magnify-white.png" ) ) );
    openSearchButton->setFlat( true );

    menuLayout->addWidget( profileButton, 0, Qt::AlignVCenter );
    menuLayout->addWidget( connectionsButton, 0, Qt::AlignVCenter );
    menuLayout->addWidget( educationsButton, 0, Qt::AlignVCenter );
    menuLayout->addWidget( experiencesButton, 0, Qt::AlignVCenter );
    menuLayout->addWidget( middleFiller );
    menuLayout->addWidget( openSearchButton, 0, Qt::AlignVCenter );
    menuLayout->setMargin( 0 );

    menuWidget->setLayout( menuLayout );
    menuWidget->setStyleSheet( "background: #069" );
    //menuWidget->setVisible( false );

    searchWidget = new QWidget( topBarWidget );
    searchWidget->setFixedHeight( 50 );

    QHBoxLayout *searchLayout = new QHBoxLayout( searchWidget );

    closeSearch = new QPushButton( searchWidget );
    closeSearch->setIcon( QIcon( QPixmap( ":/icons/icon/close.png" ) ) );
    closeSearch->setFlat( true );
    searchText = new QLineEdit( searchWidget );
    searchText->setPlaceholderText( tr( "Search" ) );
    searchText->setStyleSheet(
        "border: 1px solid black;"
        "border-top: none; border-right: none; border-left: none;"
        "padding: 0 10px;"
        "color: black;"
    );
    searchButton = new QPushButton( searchWidget );
    searchButton->setIcon( QIcon( QPixmap( ":/icons/icon/magnify-black.png" ) ) );
    searchButton->setFlat( true );

    searchLayout->addWidget( closeSearch, 0, Qt::AlignVCenter );
    searchLayout->addWidget( searchText, 0, Qt::AlignVCenter );
    searchLayout->addWidget( searchButton, 0, Qt::AlignVCenter );

    searchWidget->setLayout( searchLayout );
    searchWidget->setStyleSheet( "background: white" );
    //searchWidget->setVisible( false );

    topBarLayout->addWidget( linqedinLabel, 0, Qt::AlignVCenter );
    topBarLayout->addSpacing( 30 );
    topBarLayout->addWidget( menuWidget );
    topBarLayout->addWidget( searchWidget );
    topBarLayout->setContentsMargins( 20, 0, 20, 0 );

    topBarWidget->setLayout( topBarLayout );

    contentWidget = new QWidget( mainWidget );
    contentWidget->setStyleSheet( "background: white" );

    mainLayout->addWidget( topBarWidget );
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
                "QPushButton {"
                    "padding: 0 10px;"
                    "border: 3px solid #069;"
                    "outline: 0;"
                "}"
                "QPushButton:hover {"
                    "padding: 0 10px;"
                    "border-bottom-color: white;"
                    "outline: 0;"
                "}"
            );
        } else {
            buttonSelected->setStyleSheet(
                "QPushButton {"
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
