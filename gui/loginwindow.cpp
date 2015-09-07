#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
#include "adminlogindialog.h"
#include "adminwindow.h"
#include "clientwindow.h"
#include "loginwindow.h"

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

// METODO LoginWindow::initUI
void LoginWindow::initUI() {
    titleLabel = new QLabel( tr( "<h1>LinQedIn</h1>" ) );

    userUsername = new QLineEdit( this );
    connect( userUsername, SIGNAL( textChanged( QString ) ), this, SLOT( checkInput( QString ) ) );
    userPassword = new QLineEdit( this );
    connect( userPassword, SIGNAL( textChanged( QString ) ), this, SLOT( checkInput( QString ) ) );
    loginButton = new QPushButton( "Log In" );
    connect( loginButton, SIGNAL( clicked() ), this, SLOT( loginUser() ) );

    openAdminLoginButton = new QPushButton();
    connect( openAdminLoginButton, SIGNAL( clicked() ), this, SLOT( openAdminLoginDialog() ) );
}

// METODO LoginWindow::setupUI
void LoginWindow::setupUI() {
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

    setButtonDisabled( loginButton, true );

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
    setButtonEnabled( openAdminLoginButton, true );

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
    );

    setCentralWidget( centralWidget );
    setWindowTitle( "LinQedIn" );
    setMinimumSize( 600, 400 );
}

// METODO LoginWindow::createMenuActions
void LoginWindow::createMenuActions() {}

// METODO LoginWindow::createMenus
void LoginWindow::createMenus() {}

// METODO LoginWindow::setButtonEnabledProperties( QPushButton * )
void LoginWindow::setButtonEnabledProperties( QPushButton *button ) {
    button->setStyleSheet(
        "QPushButton { border: 2px solid rgb(0,61,92); border-radius: 5px;"
            "background: rgb(0,61,92); color: white; outline: none; }"
        "QPushButton:pressed { border: 2px solid #00527A; background: #00527A; }"
    );
}

// METODO LoginWindow::setButtonDisabledProperties( QPushButton * )
void LoginWindow::setButtonDisabledProperties( QPushButton *button ) {
    button->setStyleSheet(
        "QPushButton { border: 2px solid rgba(0,61,92,0.70); border-radius: 5px;"
            "background: rgba(0,61,92,0.70); color: rgba(255,255,255,0.30); outline: none; }"
    );
}

// METODO LoginWindow::setButtonDisabled( QPushButton *, bool )
void LoginWindow::setButtonDisabled( QPushButton *button, bool state ) {
    button->setDisabled( state );
    if( state )
        setButtonDisabledProperties( button );
    else setButtonEnabledProperties( button );
}

// METODO LoginWindow::setButtonEnabled( QPushButton *, bool )
void LoginWindow::setButtonEnabled( QPushButton *button, bool state ) {
    button->setEnabled( state );
    if( !state )
        setButtonDisabledProperties( button );
    else setButtonEnabledProperties( button );
}

// SLOT LoginWindow::checkInput( QString )
void LoginWindow::checkInput( const QString& input ) {
    Q_UNUSED( input )

    if( userUsername->text().trimmed().isEmpty() || userPassword->text().trimmed().isEmpty() )
        setButtonDisabled( loginButton, true );
    else setButtonEnabled( loginButton, true );
}

// SLOT LoginWindow::loginUser
void LoginWindow::loginUser() {
    QString username = userUsername->text();

    // TODO: controllare username e password
    new ClientWindow( username );
    this->close();
}

// SLOT LoginWindows::loginAdmin
void LoginWindow::loginAdmin() {
    // TODO: controllo password
    new AdminWindow();
    this->close();
}

// SLOT LoginWindow::openAdminLoginDialog
void LoginWindow::openAdminLoginDialog() {
    AdminLoginDialog *adminLoginDialog = new AdminLoginDialog( this );
    connect( adminLoginDialog, SIGNAL( adminLoginSignal() ), this, SLOT( loginAdmin() ) );

    adminLoginDialog->exec();
}
