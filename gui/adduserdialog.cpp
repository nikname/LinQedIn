#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>
#include "adduserdialog.h"
#include "adminwindow.h"
#include "utente_basic.h"
#include "utente_business.h"
#include "utente_executive.h"

// COSTRUTTORE AddUserDialog
AddUserDialog::AddUserDialog( QWidget *parent ) :
    LinQedInDialog( parent )
{
    initUI();
    setupUI();
}

// METODO AddUserDialog::initUI
void AddUserDialog::initUI() {
    titleLabel = new QLabel( tr( "Add New User" ) );

    usernameEdit = new QLineEdit( this );
    connect( usernameEdit, SIGNAL( textChanged( QString ) ), this, SLOT( checkInput( QString ) ) );
    nameEdit = new QLineEdit( this );
    connect( nameEdit, SIGNAL( textChanged( QString ) ), this, SLOT( checkInput( QString ) ) );
    surnameEdit = new QLineEdit( this );
    connect( surnameEdit, SIGNAL( textChanged( QString ) ), this, SLOT( checkInput( QString ) ) );

    buttonGroup = new QGroupBox( this );
    basicRadioButton = new QRadioButton( "Basic", buttonGroup );
    executiveRadioButton = new QRadioButton( "Executive", buttonGroup );
    businessRadioButton = new QRadioButton( "Business", buttonGroup );

    acceptButton = new QPushButton( "OK", this );
    connect( acceptButton, SIGNAL( clicked() ), this, SLOT( addUser() ) );
    rejectButton = new QPushButton( tr( "CANCEL" ), this );
    connect( rejectButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
}

// METODO AddUserDialog::setupUI
void AddUserDialog::setupUI() {
    titleLabel->setStyleSheet( "QLabel { font: bold; }" );

    usernameEdit->setPlaceholderText( tr( "Username" ) );
    setLineEditProperties( usernameEdit );
    nameEdit->setPlaceholderText( tr( "Name" ) );
    setLineEditProperties( nameEdit );
    surnameEdit->setPlaceholderText( tr( "Surname" ) );
    setLineEditProperties( surnameEdit );

    basicRadioButton->setChecked( true );

    QVBoxLayout *buttonGroupLayout = new QVBoxLayout( buttonGroup );
    buttonGroupLayout->addWidget( basicRadioButton );
    buttonGroupLayout->addWidget( executiveRadioButton );
    buttonGroupLayout->addWidget( businessRadioButton );

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

    QVBoxLayout *layout = new QVBoxLayout( this );
    layout->addWidget( titleLabel );
    layout->addWidget( usernameEdit );
    layout->addWidget( nameEdit );
    layout->addWidget( surnameEdit );
    layout->addWidget( buttonGroup );
    layout->addSpacing( 10 );
    layout->addWidget( buttonsWidget );
    layout->setMargin( 20 );

    setStyleSheet( "background: white" );
    setWindowFlags( Qt::Dialog | Qt::FramelessWindowHint );
    setFixedWidth( 300 );
}

// SLOT AddUserDialog::checkInput( QString )
void AddUserDialog::checkInput( const QString& input ) {
    if( usernameEdit->text().isEmpty() ||
            nameEdit->text().isEmpty() ||
            surnameEdit->text().isEmpty() )
        setButtonDisabled( acceptButton, true );
    else setButtonEnabled( acceptButton, true );
}

void AddUserDialog::addUser() {
    Utente *u = 0;
    if( basicRadioButton->isChecked() )
        u = new UtenteBasic( usernameEdit->text(), nameEdit->text(), surnameEdit->text() );
    else if( executiveRadioButton->isChecked() )
        u = new UtenteExecutive( usernameEdit->text(), nameEdit->text(), surnameEdit->text() );
    else if( businessRadioButton->isChecked() )
        u = new UtenteBusiness( usernameEdit->text(), nameEdit->text(), surnameEdit->text() );
    else qDebug() << "[error] No account type selected!";

    if( u )
        emit userToAddSignal( SmartUtente( u ) );

    this->close();
}


