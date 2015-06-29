#include "tabprofilo.h"
#include <QVBoxLayout>

// COSTRUTTORE TabProfilo
TabProfilo::TabProfilo( SmartUtente su, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *tabLayout = new QVBoxLayout( this );

    nameLabel = new QLabel( tr( "Name" ), this );
    userNameLabel = new QLabel( su->getName(), this );
    nameLineEdit = new QLineEdit( su->getName(), this );
    nameLineEdit->setVisible( false );

    surnameLabel = new QLabel( tr( "Surname" ), this );
    userSurnameLabel = new QLabel( su->getSurname(), this );
    surnameLineEdit = new QLineEdit( su->getSurname(), this );
    surnameLineEdit->setVisible( false );

    usernameLabel = new QLabel( tr( "Username" ), this );
    userUsernameLabel = new QLabel( su->getUsername(), this );
    usernameLineEdit = new QLineEdit( su->getUsername(), this );
    usernameLineEdit->setEnabled( false );
    usernameLineEdit->setVisible( false );

    accountTypeLabel = new QLabel( tr( "Account Type" ), this );
    userAccountTypeLabel = new QLabel( su->getAccountType(), this );
    accountTypeLineEdit = new QLineEdit( su->getAccountType(), this );
    accountTypeLineEdit->setEnabled( false );
    accountTypeLineEdit->setVisible( false );

    maritialStatusLabel = new QLabel( tr( "Maritial Status" ), this );
    userMaritialStatusLabel = new QLabel( su->getMaritialStatus(), this );
    maritialStatusLineEdit = new QLineEdit( su->getMaritialStatus(), this );
    maritialStatusLineEdit->setVisible( false );

    tabLayout->addWidget( nameLabel );
    tabLayout->addWidget( userNameLabel );
    tabLayout->addWidget( nameLineEdit );
    tabLayout->addWidget( surnameLabel );
    tabLayout->addWidget( userSurnameLabel );
    tabLayout->addWidget( surnameLineEdit );
    tabLayout->addWidget( usernameLabel );
    tabLayout->addWidget( userUsernameLabel );
    tabLayout->addWidget( usernameLineEdit );
    tabLayout->addWidget( accountTypeLabel );
    tabLayout->addWidget( userAccountTypeLabel );
    tabLayout->addWidget( accountTypeLineEdit );
    tabLayout->addWidget( maritialStatusLabel );
    tabLayout->addWidget( userMaritialStatusLabel );
    tabLayout->addWidget( maritialStatusLineEdit );

    setLayout( tabLayout );
}
