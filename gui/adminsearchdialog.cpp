#include <QBoxLayout>
#include <QCheckBox>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "adminsearchdialog.h"

// COSTRUTTORE AdminSearchDialog
AdminSearchDialog::AdminSearchDialog( QWidget *parent ) :
    LinQedInDialog( parent )
{
    initUI();
    setupUI();
}

// METODO AdminSearchDialog::initUI
void AdminSearchDialog::initUI() {
    titleLabel = new QLabel( tr( "Search User" ), this );

    searchEdit = new QLineEdit( this );

    typeCheckboxWidget = new QWidget( this );
    typeLabel = new QLabel( tr( "Type" ), typeCheckboxWidget );
    typeCheckboxBasic = new QCheckBox( "Basic", typeCheckboxWidget );
    typeCheckboxExecutive = new QCheckBox( "Executive", typeCheckboxWidget );
    typeCheckboxBusiness = new QCheckBox( "Business", typeCheckboxWidget );

    fieldCheckboxWidget = new QWidget( this );
    fieldLabel = new QLabel( tr( "Field" ), fieldCheckboxWidget );
    fieldCheckboxUsername = new QCheckBox( tr( "Username" ), fieldCheckboxWidget );
    fieldCheckboxName = new QCheckBox( tr( "Name" ), fieldCheckboxWidget );
    fieldCheckboxSurname = new QCheckBox( tr( "Surname" ), fieldCheckboxWidget );

    rejectButton = new QPushButton( "CANCEL", this );
    connect( rejectButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
    acceptButton = new QPushButton( "SEARCH", this );
    connect( acceptButton, SIGNAL( clicked() ), this, SLOT( searchUsers() ) );
}

// METODO AdminSearchDialog::setupUI
void AdminSearchDialog::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout( this );

    titleLabel->setStyleSheet( "QLabel { font: bold; }" );

    searchEdit->setPlaceholderText( tr( "Search" ) );
    setLineEditProperties( searchEdit );

    typeCheckboxBasic->setChecked( true );
    typeCheckboxExecutive->setChecked( true );
    typeCheckboxBusiness->setChecked( true );

    QVBoxLayout *typeCheckboxLayout = new QVBoxLayout( typeCheckboxWidget );
    typeCheckboxLayout->addWidget( typeLabel );
    typeCheckboxLayout->addWidget( typeCheckboxBasic );
    typeCheckboxLayout->addWidget( typeCheckboxExecutive );
    typeCheckboxLayout->addWidget( typeCheckboxBusiness );

    fieldCheckboxUsername->setChecked( true );

    QVBoxLayout *fieldCheckboxLayout = new QVBoxLayout( fieldCheckboxWidget );
    fieldCheckboxLayout->addWidget( fieldLabel );
    fieldCheckboxLayout->addWidget( fieldCheckboxUsername );
    fieldCheckboxLayout->addWidget( fieldCheckboxName );
    fieldCheckboxLayout->addWidget( fieldCheckboxSurname );

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
    layout->addWidget( searchEdit );
    layout->addWidget( typeCheckboxWidget );
    layout->addWidget( fieldCheckboxWidget );
    layout->addSpacing( 10 );
    layout->addWidget( buttonsWidget );
    layout->addSpacing( 20 );

    setStyleSheet( "background: white" );
    setWindowFlags( Qt::Dialog | Qt::FramelessWindowHint );
    setFixedWidth( 300 );
}

// SLOT AdminSearchDialog::checkInput
void AdminSearchDialog::checkInput( const QString& input ) {
    if( searchEdit->text().isEmpty() )
        setButtonDisabled( acceptButton, true );
    else setButtonEnabled( acceptButton, true );
}
