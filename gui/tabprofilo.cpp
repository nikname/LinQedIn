#include "tabprofilo.h"
#include <QVBoxLayout>

// COSTRUTTORE TabProfilo
TabProfilo::TabProfilo( SmartUtente su, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *tabLayout = new QVBoxLayout( this );

    QWidget *nameWidget = new QWidget( this );

    QHBoxLayout *nameLayout = new QHBoxLayout( nameWidget );

    nameLabel = new QLabel( tr( "Name" ), this );
    nameLabel->setFixedSize( 150, 30 );
    userNameLabel = new QLabel( su->getName(), this );
    nameLineEdit = new QLineEdit( su->getName(), this );
    nameLineEdit->setVisible( false );

    nameLayout->addWidget( nameLabel );
    nameLayout->addWidget( userNameLabel );
    nameLayout->addWidget( nameLineEdit );

    nameWidget->setLayout( nameLayout );

    QWidget *surnameWidget = new QWidget( this );

    QHBoxLayout *surnameLayout = new QHBoxLayout( surnameWidget );

    surnameLabel = new QLabel( tr( "Surname" ), this );
    surnameLabel->setFixedSize( 150, 30 );
    userSurnameLabel = new QLabel( su->getSurname(), this );
    surnameLineEdit = new QLineEdit( su->getSurname(), this );
    surnameLineEdit->setVisible( false );

    surnameLayout->addWidget( surnameLabel );
    surnameLayout->addWidget( userSurnameLabel );
    surnameLayout->addWidget( surnameLineEdit );

    surnameWidget->setLayout( surnameLayout );

    QWidget *usernameWidget = new QWidget( this );

    QHBoxLayout *usernameLayout = new QHBoxLayout( usernameWidget );

    usernameLabel = new QLabel( tr( "Username" ), this );
    usernameLabel->setFixedSize( 150, 30 );
    userUsernameLabel = new QLabel( su->getUsername(), this );
    usernameLineEdit = new QLineEdit( su->getUsername(), this );
    usernameLineEdit->setEnabled( false );
    usernameLineEdit->setVisible( false );

    usernameLayout->addWidget( usernameLabel );
    usernameLayout->addWidget( userUsernameLabel );
    usernameLayout->addWidget( usernameLineEdit );

    usernameWidget->setLayout( usernameLayout );

    QWidget *accountTypeWidget = new QWidget( this );

    QHBoxLayout *accountTypeLayout = new QHBoxLayout( accountTypeWidget );

    accountTypeLabel = new QLabel( tr( "Account Type" ), this );
    accountTypeLabel->setFixedSize( 150, 30 );
    userAccountTypeLabel = new QLabel( su->getAccountType(), this );
    accountTypeLineEdit = new QLineEdit( su->getAccountType(), this );
    accountTypeLineEdit->setEnabled( false );
    accountTypeLineEdit->setVisible( false );

    accountTypeLayout->addWidget( accountTypeLabel );
    accountTypeLayout->addWidget( userAccountTypeLabel );
    accountTypeLayout->addWidget( accountTypeLineEdit );

    accountTypeWidget->setLayout( accountTypeLayout );

    QWidget *maritialStatusWidget = new QWidget( this );

    QHBoxLayout *maritialStatusLayout = new QHBoxLayout( maritialStatusWidget );

    maritialStatusLabel = new QLabel( tr( "Maritial Status" ), this );
    maritialStatusLabel->setFixedSize( 150, 30 );
    userMaritialStatusLabel = new QLabel( su->getMaritialStatus(), this );
    maritialStatusLineEdit = new QLineEdit( su->getMaritialStatus(), this );
    maritialStatusLineEdit->setVisible( false );

    maritialStatusLayout->addWidget( maritialStatusLabel );
    maritialStatusLayout->addWidget( userMaritialStatusLabel );
    maritialStatusLayout->addWidget( maritialStatusLineEdit );

    maritialStatusWidget->setLayout( maritialStatusLayout );

    QWidget *middleFiller = new QWidget( this );
    middleFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    editButton = new QPushButton( tr( "Edit" ) );
    editButton->setStyleSheet(
        "QPushButton { border: 2px solid #003D5C; border-radius: 5px;"
            "background: #003D5C; color: white; }"
        "QPushButton:pressed { border: 2px solid #00527A; background: #00527A; }"
    );
    connect( editButton, SIGNAL( clicked() ), this, SLOT( editInfo() ) );

    saveButton = new QPushButton( tr( "Save" ) );
    saveButton->setVisible( false );
    saveButton->setStyleSheet(
        "QPushButton { border: 2px solid #003D5C; border-radius: 5px;"
            "background: #003D5C; color: white; }"
        "QPushButton:pressed { border: 2px solid #00527A; background: #00527A; }"
    );
    connect( saveButton, SIGNAL( clicked() ), this, SLOT( saveInfo() ) );

    tabLayout->addWidget( nameWidget );
    tabLayout->addWidget( surnameWidget );
    tabLayout->addWidget( usernameWidget );
    tabLayout->addWidget( accountTypeWidget );
    tabLayout->addWidget( maritialStatusWidget );
    tabLayout->addWidget( middleFiller );
    tabLayout->addWidget( editButton, 0, Qt::AlignRight );
    tabLayout->addWidget( saveButton, 0, Qt::AlignRight );

    setLayout( tabLayout );
}

// SLOT TabProfilo::editInfo()
void TabProfilo::editInfo() {
    userNameLabel->setVisible( false );
    userSurnameLabel->setVisible( false );
    userUsernameLabel->setVisible( false );
    userAccountTypeLabel->setVisible( false );
    userMaritialStatusLabel->setVisible( false );

    nameLineEdit->setVisible( true );
    surnameLineEdit->setVisible( true );
    usernameLineEdit->setVisible( true );
    accountTypeLineEdit->setVisible( true );
    maritialStatusLineEdit->setVisible( true );

    editButton->setVisible( false );
    saveButton->setVisible( true );
}

// SLOT TabProfilo::saveInfo()
void TabProfilo::saveInfo() {
    if( userNameLabel->text() != nameLineEdit->text() ) {
        userNameLabel->setText( nameLineEdit->text() );
        emit updateUserInfoSignal( nameLineEdit->text(), "Name" );
    }
    if( userSurnameLabel->text() != surnameLineEdit->text() ) {
        userSurnameLabel->setText( surnameLineEdit->text() );
        emit updateUserInfoSignal( surnameLineEdit->text(), "Surname" );
    }
    if( userMaritialStatusLabel->text() != maritialStatusLineEdit->text() ) {
        userMaritialStatusLabel->setText( maritialStatusLineEdit->text() );
        emit updateUserInfoSignal( maritialStatusLineEdit->text(), "Maritial Status" );
    }

    userNameLabel->setVisible( true );
    userSurnameLabel->setVisible( true );
    userUsernameLabel->setVisible( true );
    userAccountTypeLabel->setVisible( true );
    userMaritialStatusLabel->setVisible( true );

    nameLineEdit->setVisible( false );
    surnameLineEdit->setVisible( false );
    usernameLineEdit->setVisible( false );
    accountTypeLineEdit->setVisible( false );
    maritialStatusLineEdit->setVisible( false );

    editButton->setVisible( true );
    saveButton->setVisible( false );
}
