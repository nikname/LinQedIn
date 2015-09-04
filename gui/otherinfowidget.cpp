#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>
#include <QGridLayout>
#include "editpersonalinfodialog.h"
#include "otherinfowidget.h"
#include "utente.h"

// COSTRUTTORE OtherProfileWidget
OtherInfoWidget::OtherInfoWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent )
{
    initUI( su );
    setupUI();
}

// METODO OtherProfileWidget::initUI
void OtherInfoWidget::initUI( const SmartUtente& su ) {
    personalInfoLabel = new QLabel( tr( "Personal Info" ), this );

    editPersonalInfoButton = new QPushButton( this );
    connect( editPersonalInfoButton, SIGNAL( clicked() ),
             this, SLOT( openEditPersonalInfoDialog() ) );

    birthdayLabel = new QLabel( tr( "Birthday" ), this );
    userBirthday = new QLabel( su->getBirthday().toString( "dd/MM/yyyy" ), this );
    maritialStatusLabel = new QLabel( tr( "Maritial Status" ), this );
    userMaritialStatus = new QLabel( su->getMaritialStatus(), this );

    accountInfoLabel = new QLabel( tr( "Account Info" ), this );

    usernameLabel = new QLabel( tr( "Username" ), this );
    userUsername = new QLabel( su->getUsername(), this );
    accountTypeLabel = new QLabel( tr( "Account Type" ), this );
    userAccountType = new QLabel( su->getAccountType(), this );
}

// METODO OtherProfileWidget::setupUI
void OtherInfoWidget::setupUI() {
    QWidget *personalInfoLabelWidget = new QWidget( this );

    setSectionLabelProperties( personalInfoLabel );

    editPersonalInfoButton->setIcon( QIcon( QPixmap( ":/icons/icon/pencil.png" ) ) );
    setToolButtonProperties( editPersonalInfoButton );

    QHBoxLayout *personalInfoLabelLayout = new QHBoxLayout( personalInfoLabelWidget );
    personalInfoLabelLayout->addWidget( personalInfoLabel );
    personalInfoLabelLayout->addWidget( editPersonalInfoButton );
    personalInfoLabelLayout->setMargin( 0 );

    QWidget *personalInfoWidget = new QWidget( this );
    personalInfoWidget->setStyleSheet( "background: white" );

    setTitleLabelProperties( birthdayLabel );
    setTitleLabelProperties( maritialStatusLabel );

    QGridLayout *personalInfoLayout = new QGridLayout( personalInfoWidget );
    personalInfoLayout->addWidget( birthdayLabel, 0, 0 );
    personalInfoLayout->addWidget( userBirthday, 0, 1, 1, 3 );
    personalInfoLayout->addWidget( maritialStatusLabel, 1, 0 );
    personalInfoLayout->addWidget( userMaritialStatus, 1, 1, 1, 3 );

    setSectionLabelProperties( accountInfoLabel );

    QWidget *accountInfoWidget = new QWidget( this );
    accountInfoWidget->setStyleSheet( "background: white" );

    setTitleLabelProperties( usernameLabel );
    setTitleLabelProperties( accountTypeLabel );

    QGridLayout *accountInfoLayout = new QGridLayout( accountInfoWidget );
    accountInfoLayout->addWidget( usernameLabel, 0, 0 );
    accountInfoLayout->addWidget( userUsername, 0, 1, 1, 3 );
    accountInfoLayout->addWidget( accountTypeLabel, 1, 0 );
    accountInfoLayout->addWidget( userAccountType, 1, 1, 1, 3 );

    QVBoxLayout *layout = new QVBoxLayout( this );
    layout->addWidget( personalInfoLabelWidget );
    layout->addWidget( personalInfoWidget );
    layout->addWidget( accountInfoLabel );
    layout->addWidget( accountInfoWidget );
    layout->setMargin( 0 );
}

// METODO OtherInfoWidget::setToolButtonProperties
void OtherInfoWidget::setToolButtonProperties( QPushButton *button ) {
    button->setFixedSize( 24, 24 );
    button->setStyleSheet(
        "QPushButton { border-radius: 12px; outline: 0; }"
        "QPushButton:pressed { background: rgba(0,0,0,0.12); }"
    );
}

// METODO OtherInfoWidget::setSectionLabelProperties
void OtherInfoWidget::setSectionLabelProperties( QLabel *label ) {
    label->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); padding-left: 10px; }" );
}

// METODO OtherInfoWidget::setTitleLabelProperties
void OtherInfoWidget::setTitleLabelProperties( QLabel *label ) {
    label->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); padding-left: 10px; font: 12px; }" );
}

// METODO OtherInfoWidget::hideToolsButtons
void OtherInfoWidget::hideToolsButtons() {
    editPersonalInfoButton->setVisible( false );
}

// SLOT OtherInfoWidget::openEditPersonalInfoDialog
void OtherInfoWidget::openEditPersonalInfoDialog() {
    EditPersonalInfoDialog *editPersonalInfoDialog = new EditPersonalInfoDialog( this );
    connect( editPersonalInfoDialog, SIGNAL( sendDetails( QDate, QString ) ),
             this, SIGNAL( updatePersonalInfoSignal( QDate, QString ) ) );
    connect( editPersonalInfoDialog, SIGNAL( sendDetails( QDate, QString ) ),
             this, SLOT( updatePersonalInfo( QDate, QString ) ) );

    editPersonalInfoDialog->exec();
}

// SLOT OtherInfoWidget::updatePersonalInfo
void OtherInfoWidget::updatePersonalInfo( const QDate& b, const QString& ms ) {
    userBirthday->setText( b.toString( "yyyy/MM/dd" ) );
    userMaritialStatus->setText( ms );
}
