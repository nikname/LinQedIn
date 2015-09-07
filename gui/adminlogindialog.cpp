#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include "adminlogindialog.h"

// COSTRUTTORE AdminLoginDialog
AdminLoginDialog::AdminLoginDialog( QWidget *parent ) :
    LinQedInDialog( parent )
{
    initUI();
    setupUI();
}

// METODO AdminLoginDialog::initUI
void AdminLoginDialog::initUI() {
    titleLabel = new QLabel( tr( "Admin Login" ) );

    passwordEdit = new QLineEdit( this );
    connect( passwordEdit, SIGNAL( textChanged( QString ) ), this, SLOT( checkInput( QString ) ) );

    acceptButton = new QPushButton( "OK", this );
    connect( acceptButton, SIGNAL( clicked() ), this, SLOT( checkPassword() ) );
    rejectButton = new QPushButton( tr( "CANCEL" ), this );
    connect( rejectButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
}

// METODO AdminLoginDialog::setupUI
void AdminLoginDialog::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout( this );

    titleLabel->setStyleSheet( "QLabel { font: bold; }" );

    passwordEdit->setPlaceholderText( tr( "Password" ) );
    setLineEditProperties( passwordEdit );

    QWidget *buttonsWidget = new QWidget( this );

    QWidget *buttonsFiller = new QWidget( buttonsWidget );
    buttonsFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );

    setButtonEnabled( rejectButton, true );
    setButtonDisabled( acceptButton, true );

    QHBoxLayout *buttonLayout = new QHBoxLayout( buttonsWidget );
    buttonLayout->addWidget( buttonsFiller );
    buttonLayout->addWidget( rejectButton );
    buttonLayout->addWidget( acceptButton );
    buttonLayout->setMargin( 0 );

    layout->addWidget( titleLabel );
    layout->addWidget( passwordEdit );
    layout->addSpacing( 10 );
    layout->addWidget( buttonsWidget );
    layout->setMargin( 20 );

    setStyleSheet( "background: white" );
    setWindowFlags( Qt::Dialog | Qt::FramelessWindowHint );
    setFixedWidth( 300 );
}

// SLOT AdminLoginDialog::checkInput( QString )
void AdminLoginDialog::checkInput( const QString& input ) {
    Q_UNUSED( input )

    if( passwordEdit->text().isEmpty() )
        setButtonDisabled( acceptButton, true );
    else setButtonEnabled( acceptButton, true );
}

// SLOT AdminLoginDialog::checkPassword
void AdminLoginDialog::checkPassword() {
    // TODO: controllo password

    this->close();
    emit adminLoginSignal();
}
