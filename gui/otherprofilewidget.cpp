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
    QVector<SmartLavoro> experiencesList = user->getExperiencesList();
    if( experiencesList.size() == 0 )
        lastExperienceLabel = new QLabel( "--", this );
    else {
        SmartLavoro aux = experiencesList.last();
        lastExperienceLabel = new QLabel( aux->getTitle() + " at " + aux->getCompanyName(), this );
    }

    QVector<SmartTitolo> educationsList = user->getEducationsList();
    if( educationsList.size() == 0 )
        lastEducationLabel = new QLabel( "--", this );
    else {
        SmartTitolo aux = educationsList.last();
        lastEducationLabel = new QLabel( aux->getFieldOfStudy() + " at " + aux->getSchool(), this );
    }

    QVector<SmartUtente> contactsList = user->getContactsList();
    connectionsNumber = new QLabel(
                QString::number( contactsList.size() ) + tr( " connections" ), this );

    backgroundTabButton = new QPushButton( tr( "Background" ), this );
    connect( backgroundTabButton, SIGNAL( clicked() ), this, SLOT( showBackgroundTab() ) );
    connectionsTabButton = new QPushButton( tr( "Connections" ), this );
    connect( connectionsTabButton, SIGNAL( clicked() ), this, SLOT( showConnectionsTab() ) );
    connect( otherInfoTabButton, SIGNAL( clicked() ), this, SLOT( showOtherInfoTab() ) );

    ProfileWidget::tabButtons.append( backgroundTabButton );
    ProfileWidget::tabButtons.append( connectionsTabButton );

    addContactButton = new QPushButton( this );
    connect( addContactButton, SIGNAL( clicked() ), this, SLOT( addContact() ) );
    removeContactButton = new QPushButton( this );
    connect( removeContactButton, SIGNAL( clicked() ), this, SLOT( removeContact() ) );

    backgroundTab = new QWidget( this );

    experiencesLabel = new QLabel( tr( "Experiences" ), backgroundTab );
    experiencesWidget = new ExperiencesWidget( user, backgroundTab );

    educationsLabel = new QLabel( tr( "Educations" ), backgroundTab );
    educationsWidget = new EducationsWidget( user, backgroundTab );

    connectionsTab = new ConnectionsWidget( user, this );
    connect( connectionsTab, SIGNAL( showContactSignal( SmartUtente ) ),
             this, SIGNAL( showContactSignal( SmartUtente ) ) );
}

// METODO OtherProfileWidget::setupUI
void OtherProfileWidget::setupUI( bool c ) {
    QWidget *header = new QWidget( this );
    header->setStyleSheet( "background: white" );

    nameSurnameLabel->setStyleSheet( "color: rgba(0,0,0,0.87)" );
    lastExperienceLabel->setStyleSheet( "color: rgba(0,0,0,0.54);" );
    lastEducationLabel->setStyleSheet( "color: rgba(0,0,0,0.54);" );

    QWidget *profileSummaryFiller = new QWidget( ProfileWidget::profileSummary );
    profileSummaryFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    QVBoxLayout *profileSummaryLayout = new QVBoxLayout( ProfileWidget::profileSummary );
    profileSummaryLayout->addWidget( ProfileWidget::nameSurnameLabel );
    profileSummaryLayout->addWidget( lastExperienceLabel );
    profileSummaryLayout->addWidget( lastEducationLabel );
    profileSummaryLayout->addWidget( connectionsNumber, 0, Qt::AlignRight );
    profileSummaryLayout->addWidget( profileSummaryFiller );

    QHBoxLayout *headerLayout = new QHBoxLayout( header );
    headerLayout->addWidget( ProfileWidget::profilePicLabel );
    headerLayout->addWidget( ProfileWidget::profileSummary );

    QWidget *infoTabsWidget= new QWidget( this );

    QWidget *infoTabsButtonsWidget = new QWidget( infoTabsWidget );
    infoTabsButtonsWidget->setStyleSheet( "background: white" );

    setProfileButtonProperties( backgroundTabButton );
    setProfileButtonProperties( connectionsTabButton );

    setProfileButtonSelected( backgroundTabButton );

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
    infoTabsButtonLayout->addWidget( backgroundTabButton );
    infoTabsButtonLayout->addWidget( connectionsTabButton );
    infoTabsButtonLayout->addWidget( otherInfoTabButton );
    infoTabsButtonLayout->addWidget( buttonsFiller );
    infoTabsButtonLayout->addWidget( addContactButton );
    infoTabsButtonLayout->addWidget( removeContactButton );

    experiencesLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); padding-left: 10px; }" );
    educationsLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); padding-left: 10px; }" );

    connectionsTab->hideToolsButtons();
    experiencesWidget->hideToolsButtons();
    educationsWidget->hideToolsButtons();

    QVBoxLayout *backgroundTabLayout = new QVBoxLayout( backgroundTab );
    backgroundTabLayout->addWidget( experiencesLabel );
    backgroundTabLayout->addWidget( experiencesWidget );
    backgroundTabLayout->addWidget( educationsLabel );
    backgroundTabLayout->addWidget( educationsWidget );
    backgroundTabLayout->setMargin( 0 );

    connectionsTab->setVisible( false );
    otherInfoTab->setVisible( false );

    QVBoxLayout *infoTabLayout = new QVBoxLayout( infoTabsWidget );
    infoTabLayout->addWidget( infoTabsButtonsWidget );
    infoTabLayout->addWidget( backgroundTab );
    infoTabLayout->addWidget( connectionsTab );
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

// SLOT OtherProfileWidget::showBackgroundTab()
void OtherProfileWidget::showBackgroundTab() {
    backgroundTab->setVisible( true );
    setProfileButtonSelected( backgroundTabButton );
    connectionsTab->setVisible( false );
    ProfileWidget::otherInfoTab->setVisible( false );
}

// SLOT OtherProfileWidget::showConnectionsTab()
void OtherProfileWidget::showConnectionsTab() {
    backgroundTab->setVisible( false );
    connectionsTab->setVisible( true );
    setProfileButtonSelected( connectionsTabButton );
    ProfileWidget::otherInfoTab->setVisible( false );
}

// SLOT OtherProfileWidget::showOtherInfoTab()
void OtherProfileWidget::showOtherInfoTab() {
    backgroundTab->setVisible( false );
    connectionsTab->setVisible( false );
    ProfileWidget::otherInfoTab->setVisible( true );
    setProfileButtonSelected( ProfileWidget::otherInfoTabButton );
}
