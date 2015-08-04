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
    profileButton = createMenuButton( tr( "Profile" ), menuWidget );
    connectionsButton = createMenuButton( tr( "Connections" ), menuWidget );
    educationsButton = createMenuButton( tr( "Educations" ), menuWidget );
    experiencesButton = createMenuButton( tr( "Experiences" ), menuWidget );
    setButtonSelected( profileButton );

    QWidget *middleFiller = new QWidget( menuWidget );
    middleFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    searchButton = new QPushButton( menuWidget );
    searchButton->setIcon( QIcon( QPixmap( ":/icons/icon/account-search.png" ) ) );
    searchButton->setFlat( true );

    menuLayout->addWidget( linqedinLabel, 0, Qt::AlignVCenter );
    menuLayout->addSpacing( 30 );
    menuLayout->addWidget( profileButton, 0, Qt::AlignVCenter );
    menuLayout->addWidget( connectionsButton, 0, Qt::AlignVCenter );
    menuLayout->addWidget( educationsButton, 0, Qt::AlignVCenter );
    menuLayout->addWidget( experiencesButton, 0, Qt::AlignVCenter );
    menuLayout->addWidget( middleFiller );
    menuLayout->addWidget( searchButton, 0, Qt::AlignVCenter );
    menuLayout->setContentsMargins( 20, 0, 20, 0 );

    contentWidget = new QWidget( mainWidget );
    contentWidget->setStyleSheet( "background: white" );

    mainLayout->addWidget( menuWidget );
    mainLayout->addWidget( contentWidget );
    mainLayout->setMargin( 0 );
    mainLayout->setSpacing( 0 );

    mainWidget->setLayout( mainLayout );
    mainWidget->setStyleSheet( "background: #EEE; color: white;" );

    setCentralWidget( mainWidget );
    setMinimumSize( 600, 400 );

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

// METODO ClientWindow::createMenuButton( QString, QWidget* )
QPushButton* ClientWindow::createMenuButton( QString label, QWidget *parent ) {
    QPushButton *button = new QPushButton( label, parent );
    button->setFixedHeight( 50 );
    button->setStyleSheet(
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
    return button;
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
