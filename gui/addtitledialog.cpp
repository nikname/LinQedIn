#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include "addtitledialog.h"
#include "titolo.h"

// COSTRUTTORE AddTitleDialog
AddTitleDialog::AddTitleDialog( QWidget *parent ) :
    LinQedInDialog( parent )
{
    initUI();
    setupUI();
}

// METODO AddTitleDialog::initUI
void AddTitleDialog::initUI() {
    titleLabel = new QLabel( tr( "Add New Title" ) );

    schoolEdit = new QLineEdit( this );
    connect( schoolEdit, SIGNAL( textChanged( QString ) ),
             this, SLOT( checkInput( QString ) ) );
    dayAttendedEdit = new QLineEdit( this );
    connect( dayAttendedEdit, SIGNAL( textChanged( QString ) ),
             this, SLOT( checkInput( QString ) ) );
    monthAttendedEdit = new QLineEdit( this );
    connect( monthAttendedEdit, SIGNAL( textChanged( QString ) ),
             this, SLOT( checkInput( QString ) ) );
    yearAttendedEdit = new QLineEdit( this );
    connect( yearAttendedEdit, SIGNAL( textChanged( QString ) ),
             this, SLOT( checkInput( QString ) ) );
    fieldOfStudyEdit = new QLineEdit( this );
    connect( fieldOfStudyEdit, SIGNAL( textChanged( QString ) ),
             this, SLOT( checkInput( QString ) ) );

    acceptButton = new QPushButton( "OK", this );
    connect( acceptButton, SIGNAL( clicked() ), this, SLOT( addNewTitle() ) );
    rejectButton = new QPushButton( tr( "CANCEL" ), this );
    connect( rejectButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
}

// METODO AddTitleDialog::setupUI
void AddTitleDialog::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout( this );

    titleLabel->setStyleSheet( "QLabel { font: bold; }" );

    schoolEdit->setPlaceholderText( tr( "School" ) );
    setLineEditProperties( schoolEdit );

    QWidget *dateAttendedWidget = new QWidget( this );

    dayAttendedEdit->setPlaceholderText( tr( "Day" ) );
    setLineEditProperties( dayAttendedEdit );
    monthAttendedEdit->setPlaceholderText( tr( "Month" ) );
    setLineEditProperties( monthAttendedEdit );
    yearAttendedEdit->setPlaceholderText( tr( "Year" ) );
    setLineEditProperties( yearAttendedEdit );

    QLabel *separatorLabel1 = new QLabel( " - ", this );
    QLabel *separatorLabel2 = new QLabel( " - ", this );

    QHBoxLayout *dateAttendedLayout = new QHBoxLayout( dateAttendedWidget );
    dateAttendedLayout->addWidget( dayAttendedEdit );
    dateAttendedLayout->addWidget( separatorLabel1 );
    dateAttendedLayout->addWidget( monthAttendedEdit );
    dateAttendedLayout->addWidget( separatorLabel2 );
    dateAttendedLayout->addWidget( yearAttendedEdit );
    dateAttendedLayout->setMargin( 0 );

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

    fieldOfStudyEdit->setPlaceholderText( tr( "Field of Study" ) );
    setLineEditProperties( fieldOfStudyEdit );

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

// SLOT AddTitleDialog::checkInput( QString )
void AddTitleDialog::checkInput( const QString& input ) {
    if( schoolEdit->text().isEmpty() || dayAttendedEdit->text().isEmpty() ||
            monthAttendedEdit->text().isEmpty() || yearAttendedEdit->text().isEmpty() ||
            fieldOfStudyEdit->text().isEmpty() )
        setButtonDisabled( acceptButton, true );
    else setButtonEnabled( acceptButton, true );
}

// SLOT AddTitleDialog::addNewTitle()
void AddTitleDialog::addNewTitle() {
    emit addNewTitleSignal( schoolEdit->text(), dayAttendedEdit->text().toInt(),
                          monthAttendedEdit->text().toInt(), yearAttendedEdit->text().toInt(),
                          fieldOfStudyEdit->text() );

    this->close();
}
