#include "mainwindow.h"
#include "adminwindow.h"
#include <QMessageBox>

// NOTE:
// Poichè tutti gli oggetti creati dinamicamente nel costruttore sono figli di un QWidget parent,
// quando questo verrà distrutto, verranno distrutti anche tutti i figli. Per questo motivo quando
// verrà invocata la delete su widget verranno distrutti anche tutti gli oggetti figli.

// COSTRUTTORE MainWindow
MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent )
{
    initializeGUI();

    this->show();
}

// DISTRUTTORE MainWindow
MainWindow::~MainWindow() {}

// METODO MainWindow::initializGUI
void MainWindow::initializeGUI() {
    createMenuActions();
    createMenus();

    QWidget *widget = new QWidget;
    setCentralWidget( widget );

    QWidget *topVFiller = new QWidget( widget );
    topVFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    titleLabel = new QLabel( tr( "<h1>LinQedIn</h1>" ) );
    titleLabel->setAlignment( Qt::AlignHCenter );

    QWidget *middleVFiller = new QWidget( widget );
    middleVFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    createUserArea();

    QWidget *bottomVFiller = new QWidget( widget );
    bottomVFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    QFrame *line = new QFrame( widget );
    line->setFrameShape( QFrame::HLine );
    line->setFrameShadow( QFrame::Sunken );

    createAdminArea();

    QVBoxLayout *layout = new QVBoxLayout( widget );
    layout->addWidget( topVFiller );
    layout->addWidget( titleLabel );
    layout->addWidget( middleVFiller );
    layout->addLayout( userArea );
    layout->addWidget( bottomVFiller );
    layout->addWidget( line );
    layout->addLayout( adminArea );

    widget->setLayout( layout );

    widget->setStyleSheet(
        "QWidget { background: #069; font-family: Helvetica; }"
        //"QWidget { background: qradialgradient(cx: 0.5, cy: 0.5, fx: 0.5,"
        //  "fy: 0.5, radius: 0.5, stop: 0 white, stop: 1 #069); }"
        "QLabel { color: white; }"
        "QLineEdit { border: 1px solid gray; border-radius: 5px; background: white; }"
        "QPushButton { border: 2px solid #003D5C; border-radius: 5px;"
            "background: #003D5C; color: white; }"
        "QPushButton:pressed { border: 2px solid #00527A; background: #00527A; }"
    );

    setWindowTitle( "LinQedIn" );
    setMinimumSize( 600, 400 );
    //setMaximumSize( 1000, 600 );
}

// METODO MainWindow::createMenuActions
void MainWindow::createMenuActions() {
    exitAct = new QAction( tr( "Exit" ), this );
    exitAct->setStatusTip( tr( "Esci dall'applicazione" ) );
    connect( exitAct, SIGNAL( triggered() ), this, SLOT( close() ) );

    aboutAct = new QAction( tr( "About" ), this );
    aboutAct->setStatusTip( tr( "Mostra le informazioni dell'applicazione") );
    connect( aboutAct, SIGNAL( triggered() ), this, SLOT( about() ) );
}

// METODO MainWindow::createMenus
void MainWindow::createMenus() {
    menu = menuBar()->addMenu( tr( "&Menu" ) );
    menu->addAction( exitAct );
    helpMenu = menuBar()->addMenu( tr( "&Help" ) );
    helpMenu->addAction( aboutAct );
}

// METODO MainWindow::createUserArea
void MainWindow::createUserArea() {
    userArea = new QVBoxLayout;
    userArea->setAlignment( Qt::AlignCenter );

    userUsername = new QLineEdit;
    userUsername->setPlaceholderText( "Username" );
    userUsername->setFixedWidth( 400 );
    userPassword = new QLineEdit;
    userPassword->setPlaceholderText( "Password" );
    userPassword->setEchoMode( QLineEdit::Password );
    userPassword->setInputMethodHints(
        Qt::ImhHiddenText | Qt::ImhNoPredictiveText | Qt::ImhNoAutoUppercase );
    userPassword->setFixedWidth( 400 );
    loginButton = new QPushButton( "Log In" );
    loginButton->setFixedWidth( 400 ); // inutile in quanto determinato dai precedenti QLineEdit
    connect( loginButton, SIGNAL( clicked() ), this, SLOT( loginUser() ) );

    userArea->addWidget( userUsername );
    userArea->addWidget( userPassword );
    userArea->addWidget( loginButton );
}

// METODO MainWindow::createAdminArea
void MainWindow::createAdminArea() {
    adminArea = new QHBoxLayout;
    adminArea->setContentsMargins( 10, 0, 10, 0 );

    adminLabel = new QLabel( "Accesso amministratore:" );

    adminLogin = new QHBoxLayout;

    adminPassword = new QLineEdit;
    adminPassword->setPlaceholderText( "Password" );
    adminPassword->setFixedWidth( 150 );
    adminLoginButton = new QPushButton( "Log In" );
    adminLoginButton->setFixedWidth( 50 );
    connect( adminLoginButton, SIGNAL( clicked() ), this, SLOT( loginAdmin() ) );

    adminLogin->addWidget( adminPassword );
    adminLogin->addWidget( adminLoginButton );

    adminArea->addWidget( adminLabel );
    adminArea->addLayout( adminLogin );
}

// SLOT MainWindow::loginUser
void MainWindow::loginUser() {

}

// SLOT MainWindows::loginAdmin
void MainWindow::loginAdmin() {
    // TODO: controllo password

    AdminWindow* adminWindow = new AdminWindow;
    this->close();
}

// SLOT MainWindow::about
void MainWindow::about() {
    QMessageBox::about( this, tr("About Menu"), tr(
        "<b>LinQedIn</b>"
        "<p>Progetto per il corso di Programmazione ad Oggetti presso l'Università degli "
        "Studi di Padova.</p>"
        "<p>Lo scopo del progetto era lo sviluppo in C++/Qt di un sistema minimale per "
        "l'amministrazione ed utilizzo tramite interfaccia utente grafica di un (piccolo) "
        "database di contatti professionali ispirato a LinkedIn.</p>" ) );
}
