#include <QLabel>
#include <QLineEdit>
#include <QPainter>
#include <QPushButton>
#include <QDebug>
#include <QStyleOption>
#include <QVBoxLayout>
#include "editprofiledialog.h"

// COSTRUTTORE EditProfileDialog
EditProfileDialog::EditProfileDialog( QWidget *parent ) :
    EditDialog( parent )
{
    initUI();
    setupUI();
}

// METODO EditProfileDialog::initUI
void EditProfileDialog::initUI() {
    titleLabel = new QLabel( tr( "Edit Profile Info" ) );

    nameEdit = new QLineEdit( this );
    surnameEdit = new QLineEdit( this );

    acceptButton = new QPushButton( "OK", this );
    rejectButton = new QPushButton( tr( "CANCEL" ), this );
}

// METODO EditProfileDialog::setupUI
void EditProfileDialog::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout( this );

    titleLabel->setStyleSheet( "QLabel { font: bold; }" );

    nameEdit->setPlaceholderText( tr( "Name" ) );
    setLineEditProperties( nameEdit );
    connect( nameEdit, SIGNAL( textChanged( QString ) ), this, SLOT( checkInput( QString ) ) );
    surnameEdit->setPlaceholderText( tr( "Surname" ) );
    setLineEditProperties( surnameEdit );
    connect( surnameEdit, SIGNAL( textChanged( QString ) ), this, SLOT( checkInput( QString ) ) );

    QWidget *buttonsWidget = new QWidget( this );

    QWidget *buttonsFiller = new QWidget( buttonsWidget );
    buttonsFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );

    setButtonEnabled( rejectButton, true );
    setButtonDisabled( acceptButton, true );

    connect( rejectButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
    connect( acceptButton, SIGNAL( clicked() ), this, SLOT( updateProfileInfo() ) );

    QHBoxLayout *buttonLayout = new QHBoxLayout( buttonsWidget );
    buttonLayout->addWidget( buttonsFiller );
    buttonLayout->addWidget( rejectButton );
    buttonLayout->addWidget( acceptButton );
    buttonLayout->setMargin( 0 );

    layout->addWidget( titleLabel );
    layout->addWidget( nameEdit );
    layout->addWidget( surnameEdit );
    layout->addSpacing( 10 );
    layout->addWidget( buttonsWidget );
    layout->setMargin( 20 );

    setStyleSheet( "background: white" );
    setWindowFlags( Qt::Dialog | Qt::FramelessWindowHint );
    setFixedWidth( 300 );
}

// SLOT EditProfileDialog::checkInput( QString )
void EditProfileDialog::checkInput( const QString& input ) {
    if( nameEdit->text().isEmpty() || surnameEdit->text().isEmpty() )
        setButtonDisabled( acceptButton, true );
    else setButtonEnabled( acceptButton, true );
}

// SLOT EditProfileDialog::updateProfileInfo()
void EditProfileDialog::updateProfileInfo() {
    emit updateProfileInfoSignal( nameEdit->text(), surnameEdit->text() );

    this->close();
}
