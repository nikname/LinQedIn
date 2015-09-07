#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include "addjobdialog.h"
#include "lavoro.h"

// COSTRUTTORE AddJobDialog
AddJobDialog::AddJobDialog( QWidget *parent ) :
    LinQedInDialog( parent )
{
    initUI();
    setupUI();
}

// METODO AddJobDialog::initUI
void AddJobDialog::initUI() {
    titleLabel = new QLabel( tr( "Add New Job" ) );

    companyNameEdit = new QLineEdit( this );
    connect( companyNameEdit, SIGNAL( textChanged( QString ) ),
             this, SLOT( checkInput( QString ) ) );
    titleEdit = new QLineEdit( this );
    connect( titleEdit, SIGNAL( textChanged( QString ) ),
             this, SLOT( checkInput( QString ) ) );
    beginEdit = new QLineEdit( this );
    connect( beginEdit, SIGNAL( textChanged( QString ) ),
             this, SLOT( checkInput( QString ) ) );
    endEdit = new QLineEdit( this );
    connect( endEdit, SIGNAL( textChanged( QString ) ),
             this, SLOT( checkInput( QString ) ) );

    acceptButton = new QPushButton( "OK", this );
    connect( acceptButton, SIGNAL( clicked() ), this, SLOT( addNewJob() ) );
    rejectButton = new QPushButton( tr( "CANCEL" ), this );
    connect( rejectButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
}

// METODO AddJobDialog::setupUI
void AddJobDialog::setupUI() {
    titleLabel->setStyleSheet( "QLabel { font: bold; }" );

    companyNameEdit->setPlaceholderText( tr( "Company Name" ) );
    setLineEditProperties( companyNameEdit );
    titleEdit->setPlaceholderText( tr( "Title" ) );
    setLineEditProperties( titleEdit );

    QWidget *periodWidget = new QWidget( this );

    beginEdit->setPlaceholderText( "Begin Year" );
    setLineEditProperties( beginEdit );
    endEdit->setPlaceholderText( tr( "End Year" ) );
    setLineEditProperties( endEdit );

    QLabel *separatorLabel = new QLabel( " - ", this );

    QHBoxLayout *periodLayout = new QHBoxLayout( periodWidget );
    periodLayout->addWidget( beginEdit );
    periodLayout->addWidget( separatorLabel );
    periodLayout->addWidget( endEdit );
    periodLayout->setMargin( 0 );

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
    layout->addWidget( companyNameEdit );
    layout->addWidget( titleEdit );
    layout->addWidget( periodWidget );
    layout->addSpacing( 10 );
    layout->addWidget( buttonsWidget );
    layout->setMargin( 20 );

    setStyleSheet( "background: white" );
    setWindowFlags( Qt::Dialog | Qt::FramelessWindowHint );
    setFixedWidth( 300 );
}

// SLOT AddJobDialog::checkInput( QString )
void AddJobDialog::checkInput( const QString& input ) {
    if( companyNameEdit->text().isEmpty() || titleEdit->text().isEmpty() ||
            beginEdit->text().isEmpty() || endEdit->text().isEmpty() )
        setButtonDisabled( acceptButton, true );
    else setButtonEnabled( acceptButton, true );
}

// SLOT AddJobDialog::addNewJob()
void AddJobDialog::addNewJob() {
    QDate b = QDate( beginEdit->text().toInt(), 1, 1 );
    QDate e = QDate( endEdit->text().toInt(), 1, 1 );
    emit addNewJobSignal( companyNameEdit->text(), titleEdit->text(), b, e );

    this->close();
}
