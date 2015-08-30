#include <QDebug>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>
#include "changeusertypedialog.h"
#include "utente_basic.h"
#include "utente_business.h"
#include "utente_executive.h"

// COSTRUTTORE ChangeUserTypeDialog
ChangeUserTypeDialog::ChangeUserTypeDialog( const SmartUtente& u, QWidget *parent ) :
    user( u ),
    LinQedInDialog( parent )
{
    initUI();
    setupUI();
}

// METODO ChangeUserTypeDialog::initUI
void ChangeUserTypeDialog::initUI() {
    titleLabel = new QLabel( tr( "Change Account Type" ) );

    buttonGroup = new QGroupBox( this );
    basicRadioButton = new QRadioButton( "Basic", buttonGroup );
    executiveRadioButton = new QRadioButton( "Executive", buttonGroup );
    businessRadioButton = new QRadioButton( "Business", buttonGroup );

    acceptButton = new QPushButton( "OK", this );
    connect( acceptButton, SIGNAL( clicked() ), this, SLOT( changeUserType() ) );
    rejectButton = new QPushButton( tr( "CANCEL" ), this );
    connect( rejectButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
}

// METODO ChangeUserTypeDialog::setupUI
void ChangeUserTypeDialog::setupUI() {
    titleLabel->setStyleSheet( "QLabel { font: bold; }" );

    if( dynamic_cast<UtenteBasic *>( &*user ) )
        basicRadioButton->setChecked( true );
    else if( dynamic_cast<UtenteExecutive *>( &*user ) )
        executiveRadioButton->setChecked( true );
    else if( dynamic_cast<UtenteBusiness *>( &*user ) )
        businessRadioButton->setChecked( true );

    QVBoxLayout *buttonGroupLayout = new QVBoxLayout( buttonGroup );
    buttonGroupLayout->addWidget( basicRadioButton );
    buttonGroupLayout->addWidget( executiveRadioButton );
    buttonGroupLayout->addWidget( businessRadioButton );

    QWidget *buttonsWidget = new QWidget( this );

    QWidget *buttonsFiller = new QWidget( buttonsWidget );
    buttonsFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );

    setButtonEnabled( rejectButton, true );
    setButtonEnabled( acceptButton, true );

    QHBoxLayout *buttonLayout = new QHBoxLayout( buttonsWidget );
    buttonLayout->addWidget( buttonsFiller );
    buttonLayout->addWidget( rejectButton );
    buttonLayout->addWidget( acceptButton );
    buttonLayout->setMargin( 0 );

    QVBoxLayout *layout = new QVBoxLayout( this );
    layout->addWidget( titleLabel );
    layout->addWidget( buttonGroup );
    layout->addSpacing( 10 );
    layout->addWidget( buttonsWidget );
    layout->setMargin( 20 );

    setStyleSheet( "background: white" );
    setWindowFlags( Qt::Dialog | Qt::FramelessWindowHint );
    setFixedWidth( 300 );
}

// SLOT ChangeUserTypeDialog::changeUserType
void ChangeUserTypeDialog::changeUserType() {
    if( basicRadioButton->isChecked() && !dynamic_cast<UtenteBasic *>( &*user ) )
        emit changeUserTypeSignal( user->getUsername(), "Basic" );
    else if( executiveRadioButton->isChecked() && !dynamic_cast<UtenteBusiness *>( &*user ) )
        emit changeUserTypeSignal( user->getUsername(), "Executive" );
    else if( businessRadioButton->isChecked() && !dynamic_cast<UtenteExecutive *>( &*user ) )
        emit changeUserTypeSignal( user->getUsername(), "Business" );
    else {}

    this->close();
}
