#include <QDate>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include "edittitledialog.h"

// COSTRUTTORE EditTitleDialog
EditTitleDialog::EditTitleDialog( QWidget *parent ) :
    LinQedInDialog( parent )
{
    initUI();
    setupUI();
}

// METODO EditTitleDialog::initUI
void EditTitleDialog::initUI() {
    titleLabel = new QLabel( tr( "Edit Title Info" ) );

    schoolEdit = new QLineEdit( this );
    dayAttendedEdit = new QLineEdit( this );
    monthAttendedEdit = new QLineEdit( this );
    yearAttendedEdit = new QLineEdit( this );
    fieldOfStudyEdit = new QLineEdit( this );

    acceptButton = new QPushButton( "OK", this );
    rejectButton = new QPushButton( tr( "CANCEL" ), this );
}

// METODO EditTitleDialog::setupUI
void EditTitleDialog::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout( this );

    titleLabel->setStyleSheet( "QLabel { font: bold; }" );

    schoolEdit->setPlaceholderText( tr( "School" ) );
    setLineEditProperties( schoolEdit );
    connect( schoolEdit, SIGNAL( textChanged( QString ) ), this, SLOT( checkInput( QString ) ) );
    dayAttendedEdit->setPlaceholderText( tr( "Day" ) );
    setLineEditProperties( dayAttendedEdit );
    connect( dayAttendedEdit, SIGNAL( textChanged( QString ) ),
             this, SLOT( checkInput( QString ) ) );

    QWidget *dateAttendedWidget = new QWidget( this );

    monthAttendedEdit->setPlaceholderText( tr( "Month" ) );
    setLineEditProperties( monthAttendedEdit );
    connect( monthAttendedEdit, SIGNAL( textChanged( QString ) ),
             this, SLOT( checkInput( QString ) ) );
    yearAttendedEdit->setPlaceholderText( tr( "Year" ) );
    setLineEditProperties( yearAttendedEdit );
    connect( yearAttendedEdit, SIGNAL( textChanged( QString ) ),
             this, SLOT( checkInput( QString ) ) );
    fieldOfStudyEdit->setPlaceholderText( tr( "Field of Study" ) );
    setLineEditProperties( fieldOfStudyEdit );
    connect( fieldOfStudyEdit, SIGNAL( textChanged( QString ) ),
             this, SLOT( checkInput( QString ) ) );

    QLabel *separatorLabel = new QLabel( " - ", this );

    QHBoxLayout *dateAttendedLayout = new QHBoxLayout( dateAttendedWidget );
    dateAttendedLayout->addWidget( dayAttendedEdit );
    dateAttendedLayout->addWidget( separatorLabel );
    dateAttendedLayout->addWidget( monthAttendedEdit );
    dateAttendedLayout->addWidget( separatorLabel );
    dateAttendedLayout->addWidget( yearAttendedEdit );
    dateAttendedLayout->setMargin( 0 );

    QWidget *buttonsWidget = new QWidget( this );

    QWidget *buttonsFiller = new QWidget( buttonsWidget );
    buttonsFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );

    setButtonEnabled( rejectButton, true );
    setButtonDisabled( acceptButton, true );

    connect( rejectButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
    connect( acceptButton, SIGNAL( clicked() ), this, SLOT( updateTitleInfo() ) );

    QHBoxLayout *buttonLayout = new QHBoxLayout( buttonsWidget );
    buttonLayout->addWidget( buttonsFiller );
    buttonLayout->addWidget( rejectButton );
    buttonLayout->addWidget( acceptButton );
    buttonLayout->setMargin( 0 );

    layout->addWidget( titleLabel );
    layout->addWidget( schoolEdit );
    layout->addWidget( dateAttendedWidget );
    layout->addWidget( fieldOfStudyEdit );
    layout->addSpacing( 10 );
    layout->addWidget( buttonsWidget );
    layout->setMargin( 20 );

    setStyleSheet( "background: white" );
    setWindowFlags( Qt::Dialog | Qt::FramelessWindowHint );
    setFixedWidth( 300 );
}

// SLOT EditTitleDialog::checkInput( QString )
void EditTitleDialog::checkInput( const QString& input ) {
    if( schoolEdit->text().isEmpty() || fieldOfStudyEdit->text().isEmpty() )
        setButtonDisabled( acceptButton, true );
    else setButtonEnabled( acceptButton, true );
}

// SLOT EditTitleDialog::updateTitleInfo
void EditTitleDialog::updateTitleInfo() {
    QDate a = QDate( dayAttendedEdit->text().toInt(),
                     monthAttendedEdit->text().toInt(),
                     yearAttendedEdit->text().toInt() );
    emit updateTitleInfoSignal( schoolEdit->text(), a, fieldOfStudyEdit->text() );

    this->close();
}

