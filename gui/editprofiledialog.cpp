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
    QDialog( parent )
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

    setButtonProperties( rejectButton );
    setButtonProperties( acceptButton );
    acceptButton->setDisabled( true );

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

// METODO EditProfileDialog::setButtonProperties( QPushButton * )
void EditProfileDialog::setButtonProperties( QPushButton *button ) {
    button->setStyleSheet(
        "QPushButton { font: bold; border: 5px solid white; background: white; color: #069;"
                "outline: none; }"
        "QPushButton:pressed { background: #EEE; border: 5px solid #EEE; }"
    );
}

// METODO EditProfileDialog::setLineEditProperties( QLineEdit * )
void EditProfileDialog::setLineEditProperties( QLineEdit *lineEdit ) {
    lineEdit->setStyleSheet(
        "QLineEdit { border: 1px solid #069; border-top: none; border-right: none;"
            "border-left: none; color: rgba(0,0,0,0.87); }"
    );
}

// METODO EditProfileDialog::paintEvent
void EditProfileDialog::paintEvent( QPaintEvent *) {
    QStyleOption opt;
    opt.init( this );
    QPainter p( this );
    style()->drawPrimitive( QStyle::PE_Widget, &opt, &p, this );
}

// SLOT EditProfileDialog::checkInput( QString )
void EditProfileDialog::checkInput( const QString& input ) {
    if( input.isEmpty() )
        acceptButton->setDisabled( true );
    else acceptButton->setDisabled( false );
}

// SLOT EditProfileDialog::updateProfileInfo()
void EditProfileDialog::updateProfileInfo() {
    emit updateProfileInfoSignal( nameEdit->text(), surnameEdit->text() );

    this->close();
}
