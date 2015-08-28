#include <QAction>
#include <QBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
#include "adminlogindialog.h"
#include "adminwindow.h"
#include "clientwindow.h"
#include "mainwindow.h"

// NOTE:
// Poichè tutti gli oggetti creati dinamicamente nel costruttore sono figli di un QWidget parent,
// quando questo verrà distrutto, verranno distrutti anche tutti i figli. Per questo motivo quando
// verrà invocata la delete su widget verranno distrutti anche tutti gli oggetti figli. Il parent di
// widget è il widget top-level, quindi quando verrà distrutto quello, anche tutti i figli verranno
// distrutti.

// COSTRUTTORE MainWindow
MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent )
{
    initUI();
    setupUI();

    this->show();
}

// DISTRUTTORE MainWindow
MainWindow::~MainWindow() {}

// METODO MainWIndow::initUI
void MainWindow::initUI() {
    titleLabel = new QLabel( tr( "<h1>LinQedIn</h1>" ) );

    userUsername = new QLineEdit( this );
    userPassword = new QLineEdit( this );
    loginButton = new QPushButton( "Log In" );
    connect( loginButton, SIGNAL( clicked() ), this, SLOT( loginUser() ) );

    openAdminLoginButton = new QPushButton();
    connect( openAdminLoginButton, SIGNAL( clicked() ), this, SLOT( openAdminLoginDialog() ) );
}

// METODO MainWindow::setupUI
void MainWindow::setupUI() {
    createMenuActions();
    createMenus();

    QWidget *centralWidget = new QWidget( this );

    QWidget *topVFiller = new QWidget( centralWidget );
    topVFiller->setMinimumHeight( 50 );
    topVFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    titleLabel->setAlignment( Qt::AlignHCenter );

    userUsername->setPlaceholderText( "Username" );
    userPassword->setPlaceholderText( "Password" );
    userPassword->setEchoMode( QLineEdit::Password );
    userPassword->setInputMethodHints( Qt::ImhHiddenText |
                                       Qt::ImhNoPredictiveText |
                                       Qt::ImhNoAutoUppercase );

    QWidget *userAreaWidget = new QWidget( centralWidget );
    userAreaWidget->setFixedWidth( 300 );

    QVBoxLayout *userAreaLayout = new QVBoxLayout( userAreaWidget );
    userAreaLayout->addWidget( userUsername );
    userAreaLayout->addWidget( userPassword );
    userAreaLayout->addWidget( loginButton );

    QWidget *bottomVFiller = new QWidget( centralWidget );
    bottomVFiller->setMinimumHeight( 50 );
    bottomVFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    openAdminLoginButton->setIcon( QIcon( QPixmap( ":/icons/icon/account-key.png" ) ) );
    openAdminLoginButton->setFixedWidth( 30 );
    openAdminLoginButton->setFixedHeight( 30 );

    QVBoxLayout *layout = new QVBoxLayout( centralWidget );
    layout->addWidget( topVFiller );
    layout->addWidget( titleLabel );
    layout->addSpacing( 50 );
    layout->addWidget( userAreaWidget, 0, Qt::AlignHCenter );
    layout->addWidget( bottomVFiller );
    layout->addWidget( openAdminLoginButton, 0, Qt::AlignRight );

    centralWidget->setStyleSheet(
        "QWidget { background: #069; font-family: Helvetica; }"
        //"QWidget { background: qradialgradient(cx: 0.5, cy: 0.5, fx: 0.5,"
        //  "fy: 0.5, radius: 0.5, stop: 0 white, stop: 1 #069); }"
        "QLabel { color: white; }"
        "QLineEdit { border: 1px solid gray; border-radius: 5px; background: white; }"
        "QPushButton { border: 2px solid #003D5C; border-radius: 5px;"
            "background: #003D5C; color: white; outline: none; }"
        "QPushButton:pressed { border: 2px solid #00527A; background: #00527A; }"
    );

    setCentralWidget( centralWidget );
    setWindowTitle( "LinQedIn" );
    setMinimumSize( 600, 400 );
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

// SLOT MainWindow::loginUser
void MainWindow::loginUser() {
    QString username = userUsername->text();

    // TODO: controllare username e password
    // ClientWindow *clientWindow = new ClientWindow( username );
    ClientWindow *clientWindow = new ClientWindow( username );
    this->close();
}

// SLOT MainWindows::loginAdmin
void MainWindow::loginAdmin() {
    // TODO: controllo password
    AdminWindow *adminWindow = new AdminWindow();

    this->close();
}

// SLOT MainWindow::openAdminLoginDialog
void MainWindow::openAdminLoginDialog() {
    AdminLoginDialog *adminLoginDialog = new AdminLoginDialog( this );
    connect( adminLoginDialog, SIGNAL( adminLoginSignal() ), this, SLOT( loginAdmin() ) );

    adminLoginDialog->exec();
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
