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

    connect( ProfileWidget::experiencesWidget, SIGNAL( jobToAddSignal( SmartLavoro ) ),
             this, SLOT( jobToAddSlot( SmartLavoro ) ) );
    connect( ProfileWidget::experiencesWidget, SIGNAL( jobToRemoveSignal( SmartLavoro ) ),
             this, SLOT( jobToRemoveSlot( SmartLavoro ) ) );
    connect( ProfileWidget::experiencesWidget, SIGNAL( updateLastJobInfoSignal( SmartLavoro ) ),
             this, SLOT( updateLastJobInfoSlot( SmartLavoro ) ) );

    connect( ProfileWidget::educationsWidget, SIGNAL( titleToAddSignal( SmartTitolo ) ),
             this, SLOT( titleToAddSlot( SmartTitolo ) ) );
    connect( ProfileWidget::educationsWidget, SIGNAL( titleToRemoveSignal( SmartTitolo ) ),
             this, SLOT( titleToRemoveSlot( SmartTitolo ) ) );
    connect( ProfileWidget::educationsWidget, SIGNAL( updateLastTitleInfoSignal( SmartTitolo ) ),
             this, SLOT( updateLastTitleInfoSlot( SmartTitolo ) ) );

    connect( ProfileWidget::connectionsTab, SIGNAL( contactToRemoveSignal( SmartUtente ) ),
             this, SLOT( contactToRemoveSlot( SmartUtente ) ) );
    connect( ProfileWidget::connectionsTab, SIGNAL( showContactSignal( SmartUtente ) ),
             this, SIGNAL( showContactSignal( SmartUtente ) ) );
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

    QWidget *profileSummaryFiller = new QWidget( ProfileWidget::profileSummary );
    profileSummaryFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    QVBoxLayout *profileSummaryLayout = new QVBoxLayout( ProfileWidget::profileSummary );
    profileSummaryLayout->addWidget( editProfileButton, 0, Qt::AlignRight );
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

    QWidget *buttonsFiller = new QWidget( infoTabsButtonsWidget );
    buttonsFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    QHBoxLayout *infoTabsButtonLayout = new QHBoxLayout( infoTabsButtonsWidget );
    infoTabsButtonLayout->addWidget( ProfileWidget::backgroundTabButton );
    infoTabsButtonLayout->addWidget( ProfileWidget::connectionsTabButton );
    infoTabsButtonLayout->addWidget( ProfileWidget::otherInfoTabButton );
    infoTabsButtonLayout->addWidget( buttonsFiller );

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

    ProfileWidget::lastExperienceLabel->setText( sl->getTitle() + " at " + sl->getCompanyName() );
}

// SLOT PersonalProfileWidget::jobToRemove
void PersonalProfileWidget::jobToRemoveSlot( const SmartLavoro& sl ) {
    ProfileWidget::user->removeExperience( sl );

    QVector<SmartLavoro> experiencesList = ProfileWidget::user->getExperiencesList();
    if( experiencesList.size() == 0 ) {
        ProfileWidget::lastExperienceLabel->setText( "--" );
    } else {
        SmartLavoro aux = experiencesList.last();
        ProfileWidget::lastExperienceLabel->setText(
                    aux->getTitle() + " at " + aux->getCompanyName() );
    }
}

// SLOT PersonalProfileWidget::updateLastJobInfoSlot
void PersonalProfileWidget::updateLastJobInfoSlot( const SmartLavoro& sl ) {
    ProfileWidget::lastExperienceLabel->setText( sl->getTitle() + " at " + sl->getCompanyName() );
}

// SLOT PersonalProfileWidget::titleToAddSlot
void PersonalProfileWidget::titleToAddSlot( const SmartTitolo& st ) {
    ProfileWidget::user->addEducation( st );

    ProfileWidget::lastEducationLabel->setText( st->getFieldOfStudy() + " at " + st->getSchool() );
}

// SLOT PersonalProfileWidget::titleToRemoveSlot
void PersonalProfileWidget::titleToRemoveSlot( const SmartTitolo& st ) {
    ProfileWidget::user->removeEducation( st );

    QVector<SmartTitolo> educationsList = ProfileWidget::user->getEducationsList();
    if( educationsList.size() == 0 ) {
        ProfileWidget::lastEducationLabel->setText( "--" );
    } else {
        SmartTitolo aux = educationsList.last();
        ProfileWidget::lastEducationLabel->setText(
                    aux->getFieldOfStudy() + " at " + aux->getSchool() );
    }
}

// SLOT PersonalProfileWidget::updateLastTitleInfoSlot
void PersonalProfileWidget::updateLastTitleInfoSlot( const SmartTitolo& st ) {
    ProfileWidget::lastEducationLabel->setText( st->getFieldOfStudy() + " at " + st->getSchool() );
}

// SLOT PersonalProfileWidget::contactToRemoveSlot
void PersonalProfileWidget::contactToRemoveSlot( const SmartUtente& su ) {
    ProfileWidget::user->removeContact( su );

    emit removeContactSignal( su );

    ProfileWidget::connectionsNumber->setText(
                QString::number( user->getContactsList().size() ) + tr( " connections" ) );
}
