#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include "editjobdialog.h"

// COSTRUTTORE EditJobDialog
EditJobDialog::EditJobDialog( QWidget *parent ) :
    LinQedInDialog( parent )
{
    initUI();
    setupUI();
}

// METODO EditJobDialog::initUI
void EditJobDialog::initUI() {
    titleLabel = new QLabel( tr( "Edit Job Info" ) );

    companyNameEdit = new QLineEdit( this );
    titleEdit = new QLineEdit( this );
    beginEdit = new QLineEdit( this );
    endEdit = new QLineEdit( this );

    acceptButton = new QPushButton( "OK", this );
    rejectButton = new QPushButton( tr( "CANCEL" ), this );
}

// METODO EditJobDialog::setupUI
void EditJobDialog::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout( this );

    titleLabel->setStyleSheet( "QLabel { font: bold; }" );

    companyNameEdit->setPlaceholderText( tr( "Company Name" ) );
    setLineEditProperties( companyNameEdit );
    connect( companyNameEdit, SIGNAL( textChanged( QString ) ),
             this, SLOT( checkInput( QString ) ) );
    titleEdit->setPlaceholderText( tr( "Title" ) );
    setLineEditProperties( titleEdit );
    connect( titleEdit, SIGNAL( textChanged( QString ) ), this, SLOT( checkInput( QString ) ) );

    QWidget *periodWidget = new QWidget( this );

    beginEdit->setPlaceholderText( "Begin Year" );
    setLineEditProperties( beginEdit );
    connect( beginEdit, SIGNAL( textChanged( QString ) ), this, SLOT( checkInput( QString ) ) );
    endEdit->setPlaceholderText( tr( "End Year" ) );
    setLineEditProperties( endEdit );
    connect( endEdit, SIGNAL( textChanged( QString ) ), this, SLOT( checkInput( QString ) ) );

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

    connect( rejectButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
    connect( acceptButton, SIGNAL( clicked() ), this, SLOT( updateJobInfo() ) );

    QHBoxLayout *buttonLayout = new QHBoxLayout( buttonsWidget );
    buttonLayout->addWidget( buttonsFiller );
    buttonLayout->addWidget( rejectButton );
    buttonLayout->addWidget( acceptButton );
    buttonLayout->setMargin( 0 );

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

// SLOT EditJobDialog::checkInput( QString )
void EditJobDialog::checkInput( const QString& input ) {
    if( companyNameEdit->text().isEmpty() || titleEdit->text().isEmpty() ||
            beginEdit->text().isEmpty() || endEdit->text().isEmpty() )
        setButtonDisabled( acceptButton, true );
    else setButtonEnabled( acceptButton, true );
}

// SLOT EditJobDialog::updateJobInfo
void EditJobDialog::updateJobInfo() {
    emit updateJobInfoSignal( companyNameEdit->text(), titleEdit->text(),
                              beginEdit->text().toInt(), endEdit->text().toInt() );

    this->close();
}
