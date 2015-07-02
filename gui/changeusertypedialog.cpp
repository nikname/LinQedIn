#include <QDebug>
#include <QDialogButtonBox>
#include <QGroupBox>
#include <QRadioButton>
#include <QVBoxLayout>

#include "changeusertypedialog.h"

// COSTRUTTORE ChangeUserTypeDialog
ChangeUserTypeDialog::ChangeUserTypeDialog( const QString& u, const QString& t, QWidget *parent ) :
    username( u ),
    type( t ),
    QDialog( parent )
{
    setupUI();

    if( type == "Basic" ) basicRadioButton->setChecked( true );
    else if( type == "Express" ) expressRadioButton->setChecked( true );
    else if( type == "Business" ) businessRadioButton->setChecked( true );
    else {}
}

// METODO ChangeUserTypeDialog::setupUI
void ChangeUserTypeDialog::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout( this );

    buttonGroup = new QGroupBox( tr( "Account Type" ), this );

    QVBoxLayout *buttonGroupLayout = new QVBoxLayout( buttonGroup );

    basicRadioButton = new QRadioButton( "Basic", buttonGroup );
    expressRadioButton = new QRadioButton( "Express", buttonGroup );
    businessRadioButton = new QRadioButton( "Business", buttonGroup );

    buttonGroupLayout->addWidget( basicRadioButton );
    buttonGroupLayout->addWidget( expressRadioButton );
    buttonGroupLayout->addWidget( businessRadioButton );

    buttonGroup->setLayout( buttonGroupLayout );

    buttonBox = new QDialogButtonBox( this );
    buttonBox->setOrientation( Qt::Horizontal );
    buttonBox->setStandardButtons( QDialogButtonBox::Cancel | QDialogButtonBox::Ok );
    connect( buttonBox, SIGNAL( rejected() ), this, SLOT( reject() ) );
    connect( buttonBox, SIGNAL( accepted() ), this, SLOT( changeUserType() ) );

    layout->addWidget( buttonGroup );
    layout->addWidget( buttonBox, 0, Qt::AlignBottom );

    setLayout( layout );
    setWindowTitle( "Change Accunt Type" );
    resize( 300, 200 );
}

// SLOT
void ChangeUserTypeDialog::changeUserType() {
    if( basicRadioButton->isChecked() && type != "Basic" )
        emit changeUserTypeSignal( username, "Basic" );
    else if( expressRadioButton->isChecked() && type != "Express" )
        emit changeUserTypeSignal( username, "Express" );
    else if( businessRadioButton->isChecked() && type != "Business" )
        emit changeUserTypeSignal( username, "Business" );
    else {}
    this->close();
}
