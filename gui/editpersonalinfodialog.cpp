#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include "editpersonalinfodialog.h"

// COSTRUTTORE EditPersonalInfoDialog
EditPersonalInfoDialog::EditPersonalInfoDialog( QWidget *parent ) :
    LinQedInDialog( parent )
{
    initUI();
    setupUI();
}

// METODO EditPersonalInfoDialog::initUI
void EditPersonalInfoDialog::initUI() {
    titleLabel = new QLabel( tr( "Edit Personal Info" ) );

    birthdayLabel = new QLabel( tr( "Birthday" ), this );
    dayEdit = new QLineEdit( this );
    connect( dayEdit, SIGNAL( textChanged( QString ) ), this, SLOT( checkInput( QString ) ) );
    monthEdit = new QLineEdit( this );
    connect( monthEdit, SIGNAL( textChanged( QString ) ), this, SLOT( checkInput( QString ) ) );
    yearEdit = new QLineEdit( this );
    connect( yearEdit, SIGNAL( textChanged( QString ) ), this, SLOT( checkInput( QString ) ) );

    maritialStatusEdit = new QLineEdit( this );
    connect( maritialStatusEdit, SIGNAL( textChanged( QString ) ),
             this, SLOT( checkInput( QString ) ) );

    acceptButton = new QPushButton( "OK", this );
    connect( acceptButton, SIGNAL( clicked() ), this, SLOT( accept() ) );
    rejectButton = new QPushButton( tr( "CANCEL" ), this );
    connect( rejectButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
}

// METODO EditPersonalInfoDialog::setupUI
void EditPersonalInfoDialog::setupUI() {
    titleLabel->setStyleSheet( "QLabel { font: bold; }" );

    setTitleLabelProperties( birthdayLabel );

    maritialStatusEdit->setPlaceholderText( tr( "Maritial Status" ) );
    setLineEditProperties( maritialStatusEdit );

    QWidget *birthdayWidget = new QWidget( this );

    dayEdit->setPlaceholderText( tr( "Day" ) );
    setLineEditProperties( dayEdit );
    monthEdit->setPlaceholderText( tr( "Month" ) );
    setLineEditProperties( monthEdit );
    yearEdit->setPlaceholderText( tr( "Year" ) );
    setLineEditProperties( yearEdit );

    QLabel *separatorLabel1 = new QLabel( " - ", this );
    QLabel *separatorLabel2 = new QLabel( " - ", this );

    QHBoxLayout *birthdayLayout = new QHBoxLayout( birthdayWidget );
    birthdayLayout->addWidget( dayEdit );
    birthdayLayout->addWidget( separatorLabel1 );
    birthdayLayout->addWidget( monthEdit );
    birthdayLayout->addWidget( separatorLabel2 );
    birthdayLayout->addWidget( yearEdit );
    birthdayLayout->setMargin( 0 );

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
    layout->addSpacing( 10 );
    layout->addWidget( birthdayLabel );
    layout->addWidget( birthdayWidget );
    layout->addSpacing( 10 );
    layout->addWidget( maritialStatusEdit );
    layout->addSpacing( 10 );
    layout->addWidget( buttonsWidget );
    layout->setMargin( 20 );

    setStyleSheet( "background: white" );
    setWindowFlags( Qt::Dialog | Qt::FramelessWindowHint );
    setFixedWidth( 300 );
}

// SLOT EditPersonalInfoDialog::checkInput( QString )
void EditPersonalInfoDialog::checkInput( const QString& input ) {
    if( ( dayEdit->text().isEmpty() &&
          monthEdit->text().isEmpty() &&
          yearEdit->text().isEmpty() ) ||
        ( !dayEdit->text().isEmpty() &&
          !monthEdit->text().isEmpty() &&
          !yearEdit->text().isEmpty() ) )
        setButtonEnabled( acceptButton, true );
    else setButtonDisabled( acceptButton, true );
}
