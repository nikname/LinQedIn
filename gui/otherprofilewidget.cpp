#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>
#include "editprofiledialog.h"
#include "lavoro.h"
#include "otherprofilewidget.h"
#include "titolo.h"
#include "utente.h"
#include "connectionswidget.h"
#include "educationswidget.h"
#include "experienceswidget.h"

// COSTRUTTORE OtherProfileWidget
OtherProfileWidget::OtherProfileWidget( const SmartUtente& su, bool c, QWidget *parent) :
    ProfileWidget( su, parent )
{
    initUI();
    setupUI( c );
}

// METODO OtherProfileWidget::initUI
void OtherProfileWidget::initUI() {
    ProfileWidget::initUI();

    addContactButton = new QPushButton( this );
    connect( addContactButton, SIGNAL( clicked() ), this, SLOT( addContact() ) );
    removeContactButton = new QPushButton( this );
    connect( removeContactButton, SIGNAL( clicked() ), this, SLOT( removeContact() ) );

    connect( ProfileWidget::connectionsTab, SIGNAL( showContactSignal( SmartUtente ) ),
             this, SIGNAL( showContactSignal( SmartUtente ) ) );
}

// METODO OtherProfileWidget::setupUI
void OtherProfileWidget::setupUI( bool c ) {
    ProfileWidget::setupUI();

    QWidget *header = new QWidget( this );
    header->setStyleSheet( "background: white" );

    QWidget *profileSummaryFiller = new QWidget( ProfileWidget::profileSummary );
    profileSummaryFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    QVBoxLayout *profileSummaryLayout = new QVBoxLayout( ProfileWidget::profileSummary );
    profileSummaryLayout->addWidget( ProfileWidget::nameSurnameLabel );
    profileSummaryLayout->addWidget( ProfileWidget::lastExperienceLabel );
    profileSummaryLayout->addWidget( ProfileWidget::lastEducationLabel );
    profileSummaryLayout->addWidget( ProfileWidget::connectionsNumber, 0, Qt::AlignRight );
    profileSummaryLayout->addWidget( profileSummaryFiller );

    QHBoxLayout *headerLayout = new QHBoxLayout( header );
    headerLayout->addWidget( ProfileWidget::profilePicLabel );
    headerLayout->addWidget( ProfileWidget::profileSummary );

    QWidget *infoTabsWidget= new QWidget( this );

    QWidget *infoTabsButtonsWidget = new QWidget( infoTabsWidget );
    infoTabsButtonsWidget->setStyleSheet( "background: white" );

    addContactButton->setFixedSize( 50, 50 );
    addContactButton->setIcon( QIcon( QPixmap( ":/icons/icon/account-plus.png" ) ) );
    addContactButton->setStyleSheet(
        "QPushButton { background: #003D5C; border-radius: 25px; outline: none; }"
        "QPushButton:pressed { background: #3385AD; outline: none; }"
    );

    removeContactButton->setFixedSize( 50, 50 );
    removeContactButton->setIcon( QIcon( QPixmap( ":/icons/icon/account-remove-white.png" ) ) );
    removeContactButton->setStyleSheet(
        "QPushButton { background: #FF1744; border-radius: 25px; outline: none; }"
        "QPushButton:pressed { background: #FF5252; outline: none; }"
    );

    QWidget *buttonsFiller = new QWidget( infoTabsButtonsWidget );
    buttonsFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    if( c ) addContactButton->setVisible( false );
    else removeContactButton->setVisible( false );

    QHBoxLayout *infoTabsButtonLayout = new QHBoxLayout( infoTabsButtonsWidget );
    infoTabsButtonLayout->addWidget( ProfileWidget::backgroundTabButton );
    infoTabsButtonLayout->addWidget( ProfileWidget::connectionsTabButton );
    infoTabsButtonLayout->addWidget( ProfileWidget::otherInfoTabButton );
    infoTabsButtonLayout->addWidget( buttonsFiller );
    infoTabsButtonLayout->addWidget( addContactButton );
    infoTabsButtonLayout->addWidget( removeContactButton );

    experiencesLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); padding-left: 10px; }" );
    educationsLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); padding-left: 10px; }" );

    QVBoxLayout *backgroundTabLayout = new QVBoxLayout( ProfileWidget::backgroundTab );
    backgroundTabLayout->addWidget( ProfileWidget::experiencesLabel );
    backgroundTabLayout->addWidget( ProfileWidget::experiencesWidget );
    backgroundTabLayout->addWidget( ProfileWidget::educationsLabel );
    backgroundTabLayout->addWidget( ProfileWidget::educationsWidget );
    backgroundTabLayout->setMargin( 0 );

    connectionsTab->setVisible( false );
    otherInfoTab->setVisible( false );

    QVBoxLayout *infoTabLayout = new QVBoxLayout( infoTabsWidget);
    infoTabLayout->addWidget( infoTabsButtonsWidget );
    infoTabLayout->addWidget( ProfileWidget::backgroundTab );
    infoTabLayout->addWidget( ProfileWidget::connectionsTab );
    infoTabLayout->addWidget( ProfileWidget::otherInfoTab );
    infoTabLayout->setMargin( 0 );

    QVBoxLayout *layout = new QVBoxLayout( this );
    layout->addWidget( header );
    layout->addWidget( infoTabsWidget);
}

// SLOT OtherProfileWidget::addContact
void OtherProfileWidget::addContact() {
    emit addContactSignal( user );

    addContactButton->setVisible( false );
    removeContactButton->setVisible( true );
}

// SLOT OtherProfileWidget::removeContact
void OtherProfileWidget::removeContact() {
    emit removeContactSignal( user );

    addContactButton->setVisible( true );
    removeContactButton->setVisible( false );
}
