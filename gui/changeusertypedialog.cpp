#include "changeusertypedialog.h"
#include <QVBoxLayout>
#include <QDebug>

// COSTRUTTORE ChangeUserTypeDialog
ChangeUserTypeDialog::ChangeUserTypeDialog( const QString& u, const QString& t, QWidget *parent ) :
    username( u ),
    type( t ),
    QDialog( parent ),
    buttonBox( new QDialogButtonBox( this ) )
{
    setupUI();
    qDebug() << "[info] Done!";

    if( type == "Basic" )
        basicRadioButton->setChecked( true );
    else if( type == "Express" )
        expressRadioButton->setChecked( true );
    else if( type == "Business" )
        businessRadioButton->setChecked( true );
    else {}
}

// METODO ChangeUserTypeDialog::setupUI
void ChangeUserTypeDialog::setupUI() {
    qDebug() << "[info] Setup UI...";
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

    buttonBox->setOrientation( Qt::Horizontal );
    buttonBox->setStandardButtons( QDialogButtonBox::Cancel | QDialogButtonBox::Ok );
    qDebug() << "[info] Connecting SINGALs and SLOTs...";
    connect( buttonBox, SIGNAL( rejected() ), this, SLOT( reject() ) );
    connect( buttonBox, SIGNAL( accepted() ), this, SLOT( emitChangeAccountTypeSignal() ) );

    layout->addWidget( buttonGroup );
    layout->addWidget( buttonBox, 0, Qt::AlignBottom );

    setLayout( layout );
    setWindowTitle( "Change Accunt Type" );
    resize( 300, 200 );
}

// SLOT
void ChangeUserTypeDialog::emitChangeAccountTypeSignal() {
    if( basicRadioButton->isChecked() )
        emit changeAccountTypeSignal( username, "Basic" );
    else if( expressRadioButton->isChecked() )
        emit changeAccountTypeSignal( username, "Express" );
    else if( businessRadioButton->isChecked() )
        emit changeAccountTypeSignal( username, "Business" );
    else {}
    this->close();
}
