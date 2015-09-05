#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>
#include "editprofiledialog.h"
#include "lavoro.h"
#include "otherprofilewidget.h"
#include "otherinfowidget.h"
#include "titolo.h"
#include "utente.h"
#include "connectionswidget.h"
#include "educationswidget.h"
#include "experienceswidget.h"

// COSTRUTTORE OtherProfileWidget
OtherProfileWidget::OtherProfileWidget( const SmartUtente& su, QList<QString> i,
                                        bool c, QWidget *parent) :
    ProfileWidget( su, parent )
{
    initUI( i );
    setupUI( c );
}

// METODO OtherProfileWidget::initUI
void OtherProfileWidget::initUI( QList<QString> i ) {
    if( i.contains( "experiences" ) ) {
        QVector<SmartLavoro> experiencesList = user->getExperiencesList();
        if( experiencesList.size() == 0 )
            lastExperienceLabel = new QLabel( "--", this );
        else {
            SmartLavoro aux = experiencesList.last();
            lastExperienceLabel = new QLabel( aux->getTitle() + " at " + aux->getCompanyName(), this );
        }
    } else {
        lastExperienceLabel = 0;
    }

    if( i.contains( "educations" ) ) {
        QVector<SmartTitolo> educationsList = user->getEducationsList();
        if( educationsList.size() == 0 )
            lastEducationLabel = new QLabel( "--", this );
        else {
            SmartTitolo aux = educationsList.last();
            lastEducationLabel = new QLabel( aux->getFieldOfStudy() + " at " + aux->getSchool(), this );
        }
    } else {
        lastEducationLabel = 0;
    }

    if( i.contains( "contacts" ) ) {
        QVector<SmartUtente> contactsList = user->getContactsList();
        connectionsNumber = new QLabel(
                    QString::number( contactsList.size() ) + tr( " connections" ), this );

        connectionsTabButton = new QPushButton( tr( "Connections" ), this );
        connect( connectionsTabButton, SIGNAL( clicked() ), this, SLOT( showConnectionsTab() ) );

        connectionsTab = new ConnectionsWidget( user, this );
        connect( connectionsTab, SIGNAL( showContactSignal( SmartUtente ) ),
                 this, SIGNAL( showContactSignal( SmartUtente ) ) );

        ProfileWidget::tabButtons.append( connectionsTabButton );
    } else {
        connectionsNumber = 0;
        connectionsTabButton = 0;
        connectionsTab = 0;
    }

    if( i.contains( "educations" ) || i.contains( "experiences" ) ) {
        backgroundTabButton = new QPushButton( tr( "Background" ), this );
        connect( backgroundTabButton, SIGNAL( clicked() ), this, SLOT( showBackgroundTab() ) );

        ProfileWidget::tabButtons.append( backgroundTabButton );

        backgroundTab = new QWidget( this );

        if( i.contains( "experiences" ) ) {
            experiencesLabel = new QLabel( tr( "Experiences" ), backgroundTab );
            experiencesWidget = new ExperiencesWidget( user, backgroundTab );
        } else {
            experiencesLabel = 0;
            experiencesWidget = 0;
        }

        if( i.contains( "educations" ) ) {
            educationsLabel = new QLabel( tr( "Educations" ), backgroundTab );
            educationsWidget = new EducationsWidget( user, backgroundTab );
        } else {
            educationsLabel = 0;
            educationsWidget = 0;
        }
    } else {
        backgroundTabButton = 0;
        backgroundTab = 0;
        experiencesLabel = 0;
        experiencesWidget = 0;
        educationsLabel = 0;
        educationsWidget = 0;
    }

    connect( ProfileWidget::otherInfoTabButton, SIGNAL( clicked() ),
             this, SLOT( showOtherInfoTab() ) );

    addContactButton = new QPushButton( this );
    connect( addContactButton, SIGNAL( clicked() ), this, SLOT( addContact() ) );
    removeContactButton = new QPushButton( this );
    connect( removeContactButton, SIGNAL( clicked() ), this, SLOT( removeContact() ) );
}

// METODO OtherProfileWidget::setupUI
void OtherProfileWidget::setupUI( bool c ) {
    QWidget *header = new QWidget( this );
    header->setStyleSheet( "background: white" );

    nameSurnameLabel->setStyleSheet( "color: rgba(0,0,0,0.87)" );
    if( lastExperienceLabel ) lastExperienceLabel->setStyleSheet( "color: rgba(0,0,0,0.54);" );
    if( lastEducationLabel ) lastEducationLabel->setStyleSheet( "color: rgba(0,0,0,0.54);" );

    QWidget *profileSummaryFiller = new QWidget( ProfileWidget::profileSummary );
    profileSummaryFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    QVBoxLayout *profileSummaryLayout = new QVBoxLayout( ProfileWidget::profileSummary );
    profileSummaryLayout->addWidget( ProfileWidget::nameSurnameLabel );
    if( lastExperienceLabel ) profileSummaryLayout->addWidget( lastExperienceLabel );
    if( lastEducationLabel ) profileSummaryLayout->addWidget( lastEducationLabel );
    if( connectionsNumber ) profileSummaryLayout->addWidget( connectionsNumber, 0, Qt::AlignRight );
    profileSummaryLayout->addWidget( profileSummaryFiller );

    QHBoxLayout *headerLayout = new QHBoxLayout( header );
    headerLayout->addWidget( ProfileWidget::profilePicLabel );
    headerLayout->addWidget( ProfileWidget::profileSummary );

    QWidget *infoTabsWidget= new QWidget( this );

    QWidget *infoTabsButtonsWidget = new QWidget( infoTabsWidget );
    infoTabsButtonsWidget->setStyleSheet( "background: white" );

    if( backgroundTabButton ) {
        setProfileButtonProperties( backgroundTabButton );
        setProfileButtonSelected( backgroundTabButton );
    }
    if( connectionsTabButton ) setProfileButtonProperties( connectionsTabButton );

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
    if( backgroundTabButton ) infoTabsButtonLayout->addWidget( backgroundTabButton );
    if( connectionsTabButton ) infoTabsButtonLayout->addWidget( connectionsTabButton );
    infoTabsButtonLayout->addWidget( otherInfoTabButton );
    infoTabsButtonLayout->addWidget( buttonsFiller );
    infoTabsButtonLayout->addWidget( addContactButton );
    infoTabsButtonLayout->addWidget( removeContactButton );

    if( experiencesLabel )
        experiencesLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); padding-left: 10px; }" );
    if( educationsLabel )
        educationsLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); padding-left: 10px; }" );

    if( connectionsTab ) connectionsTab->hideToolsButtons();
    if( experiencesWidget ) experiencesWidget->hideToolsButtons();
    if( educationsWidget ) educationsWidget->hideToolsButtons();
    ProfileWidget::otherInfoTab->hideToolsButtons();

    if( backgroundTab ) {
        QVBoxLayout *backgroundTabLayout = new QVBoxLayout( backgroundTab );
        if( experiencesLabel ) backgroundTabLayout->addWidget( experiencesLabel );
        if( experiencesWidget ) backgroundTabLayout->addWidget( experiencesWidget );
        if( educationsLabel ) backgroundTabLayout->addWidget( educationsLabel );
        if( educationsWidget ) backgroundTabLayout->addWidget( educationsWidget );
        backgroundTabLayout->setMargin( 0 );
    }

    if( connectionsTab ) connectionsTab->setVisible( false );
    if( backgroundTab ) otherInfoTab->setVisible( false );

    QVBoxLayout *infoTabLayout = new QVBoxLayout( infoTabsWidget );
    infoTabLayout->addWidget( infoTabsButtonsWidget );
    if( backgroundTab ) infoTabLayout->addWidget( backgroundTab );
    if( connectionsTab ) infoTabLayout->addWidget( connectionsTab );
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
    if( backgroundTab ) backgroundTab->setVisible( true );
    if( backgroundTabButton ) setProfileButtonSelected( backgroundTabButton );
    if( connectionsTab ) connectionsTab->setVisible( false );
    ProfileWidget::otherInfoTab->setVisible( false );
}

// SLOT OtherProfileWidget::showConnectionsTab()
void OtherProfileWidget::showConnectionsTab() {
    if( backgroundTab ) backgroundTab->setVisible( false );
    if( connectionsTab ) connectionsTab->setVisible( true );
    if( connectionsTabButton ) setProfileButtonSelected( connectionsTabButton );
    ProfileWidget::otherInfoTab->setVisible( false );
}

// SLOT OtherProfileWidget::showOtherInfoTab()
void OtherProfileWidget::showOtherInfoTab() {
    if( backgroundTab ) backgroundTab->setVisible( false );
    if( connectionsTab ) connectionsTab->setVisible( false );
    ProfileWidget::otherInfoTab->setVisible( true );
    setProfileButtonSelected( ProfileWidget::otherInfoTabButton );
}
