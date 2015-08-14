#include <QLabel>
#include <QLineEdit>
#include <QPainter>
#include <QPushButton>
#include <QDebug>
#include <QStyleOption>
#include <QVBoxLayout>
#include "editjobdialog.h"

// COSTRUTTORE EditJobDialog
EditJobDialog::EditJobDialog( QWidget *parent ) :
    QDialog( parent )
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
    titleEdit->setPlaceholderText( tr( "Title" ) );
    setLineEditProperties( titleEdit );
    beginEdit->setPlaceholderText( "Begin Year" );
    setLineEditProperties( beginEdit );
    endEdit->setPlaceholderText( tr( "End Year" ) );
    setLineEditProperties( endEdit );

    QWidget *buttonsWidget = new QWidget( this );

    QWidget *buttonsFiller = new QWidget( buttonsWidget );
    buttonsFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );

    setButtonProperties( rejectButton );
    setButtonProperties( acceptButton );
    acceptButton->setDisabled( true );

    connect( rejectButton, SIGNAL( clicked() ), this, SLOT( reject() ) );
    connect( acceptButton, SIGNAL( clicked() ), this, SLOT( accept() ) );

    QHBoxLayout *buttonLayout = new QHBoxLayout( buttonsWidget );
    buttonLayout->addWidget( buttonsFiller );
    buttonLayout->addWidget( rejectButton );
    buttonLayout->addWidget( acceptButton );
    buttonLayout->setMargin( 0 );

    layout->addWidget( titleLabel );
    layout->addWidget( companyNameEdit );
    layout->addWidget( titleEdit );
    layout->addWidget( beginEdit );
    layout->addWidget( endEdit );
    layout->addSpacing( 10 );
    layout->addWidget( buttonsWidget );
    layout->setMargin( 20 );

    setStyleSheet( "background: white" );
    setWindowFlags( Qt::Dialog | Qt::FramelessWindowHint );
    setFixedWidth( 300 );
}

// METODO EditJobDialog::setButtonProperties( QPushButton * )
void EditJobDialog::setButtonProperties( QPushButton *button ) {
    button->setStyleSheet(
        "QPushButton { font: bold; border: 5px solid white; background: white; color: #069;"
                "outline: none; }"
        "QPushButton:pressed { background: #EEE; border: 5px solid #EEE; }"
    );
}

// METODO EditJobDialog::setLineEditProperties( QLineEdit * )
void EditJobDialog::setLineEditProperties( QLineEdit *lineEdit ) {
    lineEdit->setStyleSheet(
        "QLineEdit { border: 1px solid #069; border-top: none; border-right: none;"
            "border-left: none; color: rgba(0,0,0,0.87); }"
    );
}

// METODO EditJobDialog::paintEvent
void EditJobDialog::paintEvent( QPaintEvent *) {
    QStyleOption opt;
    opt.init( this );
    QPainter p( this );
    style()->drawPrimitive( QStyle::PE_Widget, &opt, &p, this );
}
