#include <QDialogButtonBox>
#include <QGroupBox>
#include <QLineEdit>
#include <QMessageBox>
#include <QRadioButton>
#include <QVBoxLayout>

#include "adduserdialog.h"
#include "adminwindow.h"
#include "smartutente.h"
#include "utente_basic.h"
#include "utente_business.h"
#include "utente_express.h"

// COSTRUTTORE AddUserDialog
AddUserDialog::AddUserDialog( QWidget *parent ) :
    QDialog( parent )
{
    username = new QLineEdit( this );
    name = new QLineEdit( this );
    surname = new QLineEdit( this );

    buttonGroup = new QGroupBox( tr( "Account Type" ), this );
    basicRadioButton = new QRadioButton( "Basic", buttonGroup );
    expressRadioButton = new QRadioButton( "Express", buttonGroup );
    businessRadioButton = new QRadioButton( "Business", buttonGroup );

    buttonBox = new QDialogButtonBox( this );

    setupUI();
}

// METODO AddUserDialog::setupUI
void AddUserDialog::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout( this );

    username->setPlaceholderText( tr( "Username" ) );
    name->setPlaceholderText( tr( "Name" ) );
    surname->setPlaceholderText( tr( "Surname" ) );

    QVBoxLayout *buttonGroupLayout = new QVBoxLayout( buttonGroup );

    basicRadioButton->setChecked( true );

    buttonGroupLayout->addWidget( basicRadioButton );
    buttonGroupLayout->addWidget( expressRadioButton );
    buttonGroupLayout->addWidget( businessRadioButton );

    buttonGroup->setLayout( buttonGroupLayout );

    buttonBox->setOrientation( Qt::Horizontal );
    buttonBox->setStandardButtons( QDialogButtonBox::Cancel | QDialogButtonBox::Ok );
    connect( buttonBox, SIGNAL( rejected() ), this, SLOT( reject() ) );
    connect( buttonBox, SIGNAL( accepted() ), this, SLOT( addUser() ) );

    layout->addWidget( username );
    layout->addWidget( name );
    layout->addWidget( surname );
    layout->addWidget( buttonGroup );
    layout->addWidget( buttonBox, 0, Qt::AlignBottom );

    setLayout( layout );
    setWindowTitle( tr( "Add User" ) );
    resize( 300, 200 );
}

void AddUserDialog::addUser() {
    Utente *u = 0;
    if( basicRadioButton->isChecked() )
        u = new UtenteBasic( username->text(), name->text(), surname->text() );
    else if( expressRadioButton->isChecked() )
        u = new UtenteExpress( username->text(), name->text(), surname->text() );
    else if( businessRadioButton->isChecked() )
        u = new UtenteBusiness( username->text(), name->text(), surname->text() );
    else qDebug() << "[error] No account type selected!";

    if( u )
        emit userToAddSignal( SmartUtente( u ) );

    this->close();
}


