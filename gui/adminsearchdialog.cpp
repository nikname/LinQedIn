#include <QBoxLayout>
#include <QCheckBox>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
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
    connect( searchEdit, SIGNAL( textChanged( QString ) ), this, SLOT( checkInput( QString ) ) );

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

    typeLabel->setStyleSheet( "QLabel { font: bold; }" );
    typeCheckboxBasic->setChecked( true );
    typeCheckboxExecutive->setChecked( true );
    typeCheckboxBusiness->setChecked( true );

    QVBoxLayout *typeCheckboxLayout = new QVBoxLayout( typeCheckboxWidget );
    typeCheckboxLayout->addWidget( typeLabel );
    typeCheckboxLayout->addWidget( typeCheckboxBasic );
    typeCheckboxLayout->addWidget( typeCheckboxExecutive );
    typeCheckboxLayout->addWidget( typeCheckboxBusiness );
    typeCheckboxLayout->setSpacing( 0 );

    fieldLabel->setStyleSheet( "QLabel { font: bold; }" );

    fieldCheckboxUsername->setChecked( true );
    fieldCheckboxName->setChecked( true );
    fieldCheckboxSurname->setChecked( true );

    QVBoxLayout *fieldCheckboxLayout = new QVBoxLayout( fieldCheckboxWidget );
    fieldCheckboxLayout->addWidget( fieldLabel );
    fieldCheckboxLayout->addWidget( fieldCheckboxUsername );
    fieldCheckboxLayout->addWidget( fieldCheckboxName );
    fieldCheckboxLayout->addWidget( fieldCheckboxSurname );
    fieldCheckboxLayout->setSpacing( 0 );

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
    layout->addSpacing( 10 );
    layout->addWidget( typeCheckboxWidget );
    layout->addWidget( fieldCheckboxWidget );
    layout->addSpacing( 10 );
    layout->addWidget( buttonsWidget );
    layout->setMargin( 20 );

    setStyleSheet( "background: white" );
    setWindowFlags( Qt::Dialog | Qt::FramelessWindowHint );
    setFixedWidth( 300 );
}

// METODO AdminSearchDialog::paintEvent
void AdminSearchDialog::paintEvent( QPaintEvent *) {
    QStyleOption opt;
    opt.init( this );
    QPainter p( this );
    style()->drawPrimitive( QStyle::PE_Widget, &opt, &p, this );
}

// SLOT AdminSearchDialog::checkInput
void AdminSearchDialog::checkInput( const QString& input ) {
    Q_UNUSED( input )

    if( searchEdit->text().isEmpty() )
        setButtonDisabled( acceptButton, true );
    else setButtonEnabled( acceptButton, true );
}

// SLOT AdminSearchDialog::searchUsers
void AdminSearchDialog::searchUsers() {
    QList<QString> types;
    if( typeCheckboxBasic->isChecked() ) types.append( "Basic" );
    if( typeCheckboxExecutive->isChecked() ) types.append( "Executive" );
    if( typeCheckboxBusiness->isChecked() ) types.append( "Business" );

    QList<QString> fields;
    if( fieldCheckboxUsername->isChecked() ) fields.append( "Username" );
    if( fieldCheckboxName->isChecked() ) fields.append( "Name" );
    if( fieldCheckboxSurname->isChecked() ) fields.append( "Surname" );

    emit sendSearchParams( searchEdit->text(), types, fields );

    this->close();
}
