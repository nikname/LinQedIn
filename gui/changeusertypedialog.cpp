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
ChangeUserTypeDialog::ChangeUserTypeDialog( const QString& un, const QString& t, QWidget *parent ) :
    username( un ),
    type( t ),
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

    if( type == "Basic" )
        basicRadioButton->setChecked( true );
    else if( type == "Executive" )
        executiveRadioButton->setChecked( true );
    else if( type == "Business" )
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
    qDebug() << "ChangeUserTypeDialog::sendDetails";

    if( basicRadioButton->isChecked() && type != "Basic" )
        emit sendDetails( username, "Basic" );
    else if( executiveRadioButton->isChecked() && type != "Executive" )
        emit sendDetails( username, "Executive" );
    else if( businessRadioButton->isChecked() && type != "Business" )
        emit sendDetails( username, "Business" );
    else {}

    this->close();
}
