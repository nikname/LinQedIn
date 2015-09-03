#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>
#include "editprofiledialog.h"
#include "lavoro.h"
#include "personalprofilewidget.h"
#include "titolo.h"
#include "utente.h"
#include "connectionswidget.h"
#include "educationswidget.h"
#include "experienceswidget.h"

// COSTRUTTORE PersonalProfileWidget
PersonalProfileWidget::PersonalProfileWidget( const SmartUtente& su, QWidget *parent ) :
    ProfileWidget( su, parent )
{
    initUI();
    setupUI();
}

// METODO PersonalProfileWidget::initUI
void PersonalProfileWidget::initUI() {
    editProfileButton = new QPushButton( this );
    connect( editProfileButton, SIGNAL( clicked() ), this, SLOT( openEditProfileDialog() ) );

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
    connect( ProfileWidget::otherInfoTabButton, SIGNAL( clicked() ),
             this, SLOT( showOtherInfoTab() ) );

    ProfileWidget::tabButtons.append( backgroundTabButton );
    ProfileWidget::tabButtons.append( connectionsTabButton );

    backgroundTab = new QWidget( this );

    experiencesLabel = new QLabel( tr( "Experiences" ), backgroundTab );
    experiencesWidget = new ExperiencesWidget( user, backgroundTab );
    connect( experiencesWidget, SIGNAL( jobToAddSignal( SmartLavoro ) ),
             this, SLOT( jobToAddSlot( SmartLavoro ) ) );
    connect( experiencesWidget, SIGNAL( jobToRemoveSignal( SmartLavoro ) ),
             this, SLOT( jobToRemoveSlot( SmartLavoro ) ) );
    connect( experiencesWidget, SIGNAL( updateLastJobInfoSignal( SmartLavoro ) ),
             this, SLOT( updateLastJobInfoSlot( SmartLavoro ) ) );

    educationsLabel = new QLabel( tr( "Educations" ), backgroundTab );
    educationsWidget = new EducationsWidget( user, backgroundTab );
    connect( educationsWidget, SIGNAL( titleToAddSignal( SmartTitolo ) ),
             this, SLOT( titleToAddSlot( SmartTitolo ) ) );
    connect( educationsWidget, SIGNAL( titleToRemoveSignal( SmartTitolo ) ),
             this, SLOT( titleToRemoveSlot( SmartTitolo ) ) );
    connect( educationsWidget, SIGNAL( updateLastTitleInfoSignal( SmartTitolo ) ),
             this, SLOT( updateLastTitleInfoSlot( SmartTitolo ) ) );

    connectionsTab = new ConnectionsWidget( user, this );
    connect( connectionsTab, SIGNAL( showContactSignal( SmartUtente ) ),
             this, SIGNAL( showContactSignal( SmartUtente ) ) );
    connect( connectionsTab, SIGNAL( contactToRemoveSignal( SmartUtente ) ),
             this, SLOT( contactToRemoveSlot( SmartUtente ) ) );
}

// METODO PersonalProfileWidget::setupUI
void PersonalProfileWidget::setupUI() {
    QWidget *header = new QWidget( this );
    header->setStyleSheet( "background: white" );

    editProfileButton->setIcon( QIcon( QPixmap( ":/icons/icon/pencil.png" ) ) );
    editProfileButton->setFixedSize( 24, 24 );
    editProfileButton->setStyleSheet(
        "QPushButton { border-radius: 12px; outline: 0; }"
        "QPushButton:pressed { background: rgba(0,0,0,0.12); }"
    );

    nameSurnameLabel->setStyleSheet( "color: rgba(0,0,0,0.87)" );
    lastExperienceLabel->setStyleSheet( "color: rgba(0,0,0,0.54);" );
    lastEducationLabel->setStyleSheet( "color: rgba(0,0,0,0.54);" );

    QWidget *profileSummaryFiller = new QWidget( ProfileWidget::profileSummary );
    profileSummaryFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    QVBoxLayout *profileSummaryLayout = new QVBoxLayout( ProfileWidget::profileSummary );
    profileSummaryLayout->addWidget( editProfileButton, 0, Qt::AlignRight );
    profileSummaryLayout->addWidget( ProfileWidget::nameSurnameLabel );
    profileSummaryLayout->addWidget( lastExperienceLabel );
    profileSummaryLayout->addWidget( lastEducationLabel );
    profileSummaryLayout->addWidget( connectionsNumber, 0, Qt::AlignRight );
    profileSummaryLayout->addWidget( profileSummaryFiller );

    QHBoxLayout *headerLayout = new QHBoxLayout( header );
    headerLayout->addWidget( profilePicLabel );
    headerLayout->addWidget( profileSummary );

    QWidget *infoTabsWidget= new QWidget( this );

    QWidget *infoTabsButtonsWidget = new QWidget( infoTabsWidget );
    infoTabsButtonsWidget->setStyleSheet( "background: white" );

    setProfileButtonProperties( backgroundTabButton );
    setProfileButtonProperties( connectionsTabButton );

    setProfileButtonSelected( backgroundTabButton );

    QWidget *buttonsFiller = new QWidget( infoTabsButtonsWidget );
    buttonsFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    QHBoxLayout *infoTabsButtonLayout = new QHBoxLayout( infoTabsButtonsWidget );
    infoTabsButtonLayout->addWidget( backgroundTabButton );
    infoTabsButtonLayout->addWidget( connectionsTabButton );
    infoTabsButtonLayout->addWidget( otherInfoTabButton );
    infoTabsButtonLayout->addWidget( buttonsFiller );

    experiencesLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); padding-left: 10px; }" );
    educationsLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); padding-left: 10px; }" );

    QVBoxLayout *backgroundTabLayout = new QVBoxLayout( backgroundTab );
    backgroundTabLayout->addWidget( experiencesLabel );
    backgroundTabLayout->addWidget( experiencesWidget );
    backgroundTabLayout->addWidget( educationsLabel );
    backgroundTabLayout->addWidget( educationsWidget );
    backgroundTabLayout->setMargin( 0 );

    connectionsTab->setVisible( false );
    otherInfoTab->setVisible( false );

    QVBoxLayout *infoTabLayout = new QVBoxLayout( infoTabsWidget);
    infoTabLayout->addWidget( infoTabsButtonsWidget );
    infoTabLayout->addWidget( backgroundTab );
    infoTabLayout->addWidget( connectionsTab );
    infoTabLayout->addWidget( ProfileWidget::otherInfoTab );
    infoTabLayout->setMargin( 0 );

    QVBoxLayout *layout = new QVBoxLayout( this );
    layout->addWidget( header );
    layout->addWidget( infoTabsWidget);
}

// SLOT PersonalProfileWidget::showBackgroundTab()
void PersonalProfileWidget::showBackgroundTab() {
    backgroundTab->setVisible( true );
    setProfileButtonSelected( backgroundTabButton );
    connectionsTab->setVisible( false );
    ProfileWidget::otherInfoTab->setVisible( false );
}

// SLOT PersonalProfileWidget::showConnectionsTab()
void PersonalProfileWidget::showConnectionsTab() {
    backgroundTab->setVisible( false );
    connectionsTab->setVisible( true );
    setProfileButtonSelected( connectionsTabButton );
    ProfileWidget::otherInfoTab->setVisible( false );
}

// SLOT PersonalProfileWidget::showOtherInfoTab()
void PersonalProfileWidget::showOtherInfoTab() {
    backgroundTab->setVisible( false );
    connectionsTab->setVisible( false );
    ProfileWidget::otherInfoTab->setVisible( true );
    setProfileButtonSelected( ProfileWidget::otherInfoTabButton );
}

// SLOT PersonalProfileWidget::openEditProfileDialog
void PersonalProfileWidget::openEditProfileDialog() {
    EditProfileDialog *editProfileDialog = new EditProfileDialog( this );
    connect( editProfileDialog, SIGNAL( updateProfileInfoSignal( const QString&, const QString& ) ),
             this, SLOT( updateProfileInfoSlot( const QString&, const QString& ) ) );

    editProfileDialog->exec();
}

// SLOT PersonalProfileWidget::updateProfileInfoSlot( QString, QString )
void PersonalProfileWidget::updateProfileInfoSlot( const QString& n, const QString& s ) {
    ProfileWidget::nameSurnameLabel->setText( "<h1>" + n + " " + s + "</h1>" );

    ProfileWidget::user->setName( n );
    ProfileWidget::user->setSurname( s );
}

// SLOT PersonalProfileWidget::jobToAddSlot
void PersonalProfileWidget::jobToAddSlot( const SmartLavoro& sl ) {
    ProfileWidget::user->addExperience( sl );

    lastExperienceLabel->setText( sl->getTitle() + " at " + sl->getCompanyName() );
}

// SLOT PersonalProfileWidget::jobToRemove
void PersonalProfileWidget::jobToRemoveSlot( const SmartLavoro& sl ) {
    ProfileWidget::user->removeExperience( sl );

    QVector<SmartLavoro> experiencesList = ProfileWidget::user->getExperiencesList();
    if( experiencesList.size() == 0 ) {
        lastExperienceLabel->setText( "--" );
    } else {
        SmartLavoro aux = experiencesList.last();
        lastExperienceLabel->setText( aux->getTitle() + " at " + aux->getCompanyName() );
    }
}

// SLOT PersonalProfileWidget::updateLastJobInfoSlot
void PersonalProfileWidget::updateLastJobInfoSlot( const SmartLavoro& sl ) {
    lastExperienceLabel->setText( sl->getTitle() + " at " + sl->getCompanyName() );
}

// SLOT PersonalProfileWidget::titleToAddSlot
void PersonalProfileWidget::titleToAddSlot( const SmartTitolo& st ) {
    ProfileWidget::user->addEducation( st );

    lastEducationLabel->setText( st->getFieldOfStudy() + " at " + st->getSchool() );
}

// SLOT PersonalProfileWidget::titleToRemoveSlot
void PersonalProfileWidget::titleToRemoveSlot( const SmartTitolo& st ) {
    ProfileWidget::user->removeEducation( st );

    QVector<SmartTitolo> educationsList = ProfileWidget::user->getEducationsList();
    if( educationsList.size() == 0 ) {
        lastEducationLabel->setText( "--" );
    } else {
        SmartTitolo aux = educationsList.last();
        lastEducationLabel->setText( aux->getFieldOfStudy() + " at " + aux->getSchool() );
    }
}

// SLOT PersonalProfileWidget::updateLastTitleInfoSlot
void PersonalProfileWidget::updateLastTitleInfoSlot( const SmartTitolo& st ) {
    lastEducationLabel->setText( st->getFieldOfStudy() + " at " + st->getSchool() );
}

// SLOT PersonalProfileWidget::contactToRemoveSlot
void PersonalProfileWidget::contactToRemoveSlot( const SmartUtente& su ) {
    ProfileWidget::user->removeContact( su );

    emit removeContactSignal( su );

    connectionsNumber->setText(
                QString::number( user->getContactsList().size() ) + tr( " connections" ) );
}
