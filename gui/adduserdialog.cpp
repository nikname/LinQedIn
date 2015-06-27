#include "adduserdialog.h"
#include "adminwindow.h"
#include <QVBoxLayout>
#include "utente_basic.h"
#include "utente_express.h"
#include "utente_business.h"

// COSTRUTTORE AddUserDialog
AddUserDialog::AddUserDialog( QWidget *parent ) :
    QDialog( parent ),
    buttonBox( new QDialogButtonBox( this ) )
{
    setupUI();
}

// METODO AddUserDialog::setupUI
void AddUserDialog::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout( this );

    username = new QLineEdit( this );
    name = new QLineEdit( this );
    surname = new QLineEdit( this );

    buttonGroup = new QGroupBox( tr( "Account Type" ), this );

    QVBoxLayout *buttonGroupLayout = new QVBoxLayout( buttonGroup );

    basicRadioButton = new QRadioButton( "Basic", buttonGroup );
    expressRadioButton = new QRadioButton( "Express", buttonGroup );
    businessRadioButton = new QRadioButton( "Business", buttonGroup );

    buttonGroupLayout->addWidget( basicRadioButton );
    buttonGroupLayout->addWidget( expressRadioButton );
    buttonGroupLayout->addWidget( businessRadioButton );

    buttonGroup->setLayout( buttonGroupLayout );

    buttonBox->setOrientation( Qt::Horizontal );
    buttonBox->setStandardButtons( QDialogButtonBox::Cancel | QDialogButtonBox::Ok );
    connect( buttonBox, SIGNAL( rejected() ), this, SLOT( reject() ) );
    connect( buttonBox, SIGNAL( accepted() ), this, SLOT( emitAddUserSignal() ) );

    layout->addWidget( username );
    layout->addWidget( name );
    layout->addWidget( surname );
    layout->addWidget( buttonGroup );
    layout->addWidget( buttonBox, 0, Qt::AlignBottom );

    setLayout( layout );
    setWindowTitle( "Add User" );
    resize( 300, 200 );
}

void AddUserDialog::emitAddUserSignal() {
    Utente *u;
    if( basicRadioButton->isChecked() )
        u = new UtenteBasic( username->text(), name->text(), surname->text() );
    else if( expressRadioButton->isChecked() )
        u = new UtenteExpress( username->text(), name->text(), surname->text() );
    else u = new UtenteBusiness( username->text(), name->text(), surname->text() );
    emit addUserSignal( SmartUtente( u ) );
    this->close();
}


