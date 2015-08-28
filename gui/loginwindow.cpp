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
#include "loginwindow.h"

// NOTE:
// Poichè tutti gli oggetti creati dinamicamente nel costruttore sono figli di un QWidget parent,
// quando questo verrà distrutto, verranno distrutti anche tutti i figli. Per questo motivo quando
// verrà invocata la delete su widget verranno distrutti anche tutti gli oggetti figli. Il parent di
// widget è il widget top-level, quindi quando verrà distrutto quello, anche tutti i figli verranno
// distrutti.

// COSTRUTTORE LoginWindow
LoginWindow::LoginWindow( QWidget *parent ) :
    LinQedInWindow( parent )
{
    initUI();
    setupUI();

    this->show();
}

// DISTRUTTORE LoginWindow
LoginWindow::~LoginWindow() {}

// METODO LoginWindow::initializGUI
void LoginWindow::initUI() {
    titleLabel = new QLabel( tr( "<h1>LinQedIn</h1>" ) );

    userUsername = new QLineEdit( this );
    userPassword = new QLineEdit( this );
    loginButton = new QPushButton( "Log In" );
    connect( loginButton, SIGNAL( clicked() ), this, SLOT( loginUser() ) );

    openAdminLoginButton = new QPushButton();
    connect( openAdminLoginButton, SIGNAL( clicked() ), this, SLOT( openAdminLoginDialog() ) );
}

// METODO LoginWindow::setupUI
void LoginWindow::setupUI() {
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
        //"QWidget#centralWidget { background: qradialgradient(cx: 0.5, cy: 0.5, fx: 0.5,"
        //  "fy: 0.5, radius: 0.5, stop: 0 white, stop: 1 #069); }"
        "QLabel { color: white; }"
        "QLineEdit { border: 1px solid gray; border-radius: 5px; background: white; }"
        "QPushButton { border: 2px solid #003D5C; border-radius: 5px;"
            "background: #003D5C; color: white; outline: none; }"
        "QPushButton:pressed { border: 2px solid #00527A; background: #00527A; }"
    );

    setMinimumSize( 600, 400 );
    setCentralWidget( centralWidget );
    setWindowTitle( "LinQedIn" );
}

// SLOT LoginWindow::loginUser
void LoginWindow::loginUser() {
    QString username = userUsername->text();

    // TODO: controllare username e password
    ClientWindow *clientWindow = new ClientWindow( username );

    this->close();
}

// SLOT LoginWindows::loginAdmin
void LoginWindow::loginAdmin() {
    // TODO: controllo password
    AdminWindow *adminWindow = new AdminWindow();

    this->close();
}

// SLOT LoginWindow::openAdminLoginDialog
void LoginWindow::openAdminLoginDialog() {
    AdminLoginDialog *adminLoginDialog = new AdminLoginDialog( this );
    connect( adminLoginDialog, SIGNAL( adminLoginSignal() ), this, SLOT( loginAdmin() ) );

    adminLoginDialog->exec();
}
