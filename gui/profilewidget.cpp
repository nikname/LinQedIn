#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "connectionswidget.h"
#include "editprofiledialog.h"
#include "educationswidget.h"
#include "experienceswidget.h"
#include "profilewidget.h"
#include "smartlavoro.h"
#include "smarttitolo.h"
#include "utente.h"
#include "lavoro.h"
#include "titolo.h"

// COSTRUTTORE ProfileWidget
ProfileWidget::ProfileWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent ),
    user( su )
{
    initUI();
    setupUI();
}

// METODO ProfileWidget::initUI
void ProfileWidget::initUI() {
    profilePicLabel = new QLabel( this );

    profileSummary = new QWidget( this );
    nameSurnameLabel = new QLabel(
                "<h1>" + user->getName() + " " + user->getSurname() + "</h1>", this );

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

    editProfileButton = new QPushButton( this );
    connect( editProfileButton, SIGNAL( clicked() ), this, SLOT( openEditProfileDialog() ) );

    backgroundTabButton = new QPushButton( tr( "Background" ), this );
    connect( backgroundTabButton, SIGNAL( clicked() ), this, SLOT( showBackgroundTab() ) );
    connectionsTabButton = new QPushButton( tr( "Connections" ), this );
    connect( connectionsTabButton, SIGNAL( clicked() ), this, SLOT( showConnectionsTab() ) );
    otherInfoTabButton = new QPushButton( tr( "Other info" ), this );
    connect( otherInfoTabButton, SIGNAL( clicked() ), this, SLOT( showOtherInfoTab() ) );

    tabButtons.append( backgroundTabButton );
    tabButtons.append( connectionsTabButton );
    tabButtons.append( otherInfoTabButton );

    addContactButton = new QPushButton( this );
    connect( addContactButton, SIGNAL( clicked() ), this, SLOT( addContact() ) );
    removeContactButton = new QPushButton( this );
    connect( removeContactButton, SIGNAL( clicked() ), this, SLOT( removeContact() ) );

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
    connect( connectionsTab, SIGNAL( contactToRemoveSignal( SmartUtente ) ),
             this, SLOT( contactToRemoveSlot( SmartUtente ) ) );
    connect( connectionsTab, SIGNAL( showContactSignal( SmartUtente ) ),
             this, SIGNAL( showContactSignal( SmartUtente ) ) );

    otherInfoTab = new QWidget( this );
}

// METODO ProfileWidget::setupUI
void ProfileWidget::setupUI() {
    QWidget *header = new QWidget( this );
    header->setStyleSheet( "background: white" );

    profilePicLabel->setPixmap( QPixmap( ":/icons/icon/account-circle-100.png" ) );
    profilePicLabel->setMargin( 20 );

    nameSurnameLabel->setStyleSheet( "color: rgba(0,0,0,0.87)" );
    lastExperienceLabel->setStyleSheet( "color: rgba(0,0,0,0.54);" );
    lastEducationLabel->setStyleSheet( "color: rgba(0,0,0,0.54);" );

    editProfileButton->setIcon( QIcon( QPixmap( ":/icons/icon/pencil.png" ) ) );
    editProfileButton->setFixedSize( 24, 24 );
    editProfileButton->setStyleSheet(
        "QPushButton { border-radius: 12px; outline: 0; }"
        "QPushButton:pressed { background: rgba(0,0,0,0.12); }"
    );

    QWidget *profileSummaryFiller = new QWidget( profileSummary );
    profileSummaryFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    QVBoxLayout *profileSummaryLayout = new QVBoxLayout( profileSummary );
    profileSummaryLayout->addWidget( editProfileButton, 0, Qt::AlignRight );
    profileSummaryLayout->addWidget( nameSurnameLabel );
    profileSummaryLayout->addWidget( lastExperienceLabel );
    profileSummaryLayout->addWidget( lastEducationLabel );
    profileSummaryLayout->addWidget( connectionsNumber, 0, Qt::AlignRight );
    profileSummaryLayout->addWidget( profileSummaryFiller );

    QHBoxLayout *headerLayout = new QHBoxLayout( header );
    headerLayout->addWidget( profilePicLabel );
    headerLayout->addWidget( profileSummary );

    QWidget *infoTabsWidget= new QWidget( this );

    QWidget *infoTabsButtonsWidget = new QWidget( infoTabsWidget);
    infoTabsButtonsWidget->setStyleSheet( "background: white" );

    setProfileButtonProperties( backgroundTabButton );
    setProfileButtonProperties( connectionsTabButton );
    setProfileButtonProperties( otherInfoTabButton );

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

    setProfileButtonSelected( backgroundTabButton );

    QWidget *buttonsFiller = new QWidget( infoTabsButtonsWidget );
    buttonsFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    QHBoxLayout *infoTabsButtonLayout = new QHBoxLayout( infoTabsButtonsWidget );
    infoTabsButtonLayout->addWidget( backgroundTabButton );
    infoTabsButtonLayout->addWidget( connectionsTabButton );
    infoTabsButtonLayout->addWidget( otherInfoTabButton );
    infoTabsButtonLayout->addWidget( buttonsFiller );
    infoTabsButtonLayout->addWidget( addContactButton );
    infoTabsButtonLayout->addWidget( removeContactButton );

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
    infoTabLayout->addWidget( otherInfoTab );
    infoTabLayout->setMargin( 0 );

    QVBoxLayout *layout = new QVBoxLayout( this );
    layout->addWidget( header );
    layout->addWidget( infoTabsWidget);
}

// METODO ProfileWidget::setProfileButtonProperties( QPushButton* )
void ProfileWidget::setProfileButtonProperties( QPushButton *button ) {
    button->setFixedHeight( 40 );
    button->setStyleSheet(
        "QPushButton { padding: 0 10px; border: 3px solid white; font: bold;"
            "color: rgba(0,0,0,0.54); outline: 0; }"
        "QPushButton:hover { border-bottom-color: #069; }"
    );
}

// METODO ProfileWidget::setProfileButtonSelected( QPushButton* )
void ProfileWidget::setProfileButtonSelected( QPushButton *button ) {
    for( int i = 0; i < tabButtons.size(); i++ ) {
        QPushButton *aux = tabButtons[i];
        if( aux ) {
            if( aux == button ) {
                aux->setStyleSheet(
                    "QPushButton { padding: 0 10px; border: 3px solid white; font: bold;"
                        "color: rgba(0,0,0,0.87); border-bottom-color: #069; outline: 0; }"
                );
            } else {
                aux->setStyleSheet(
                    "QPushButton { padding: 0 10px; border: 3px solid white; font: bold;"
                        "color: rgba(0,0,0,0.54); outline: 0; }"
                    "QPushButton:hover { border-bottom-color: #069; }"
                );
            }
        } else { } // throw ...
    }
}

// METODO ProfileWidget::hideContactToolsButton
void ProfileWidget::hideContactToolsButton() {
    addContactButton->setVisible( false );
    removeContactButton->setVisible( false );
}

// SLOT ProfileWidget::showBackgroundTab()
void ProfileWidget::showBackgroundTab() {
    backgroundTab->setVisible( true );
    setProfileButtonSelected( backgroundTabButton );
    connectionsTab->setVisible( false );
    otherInfoTab->setVisible( false );
}

// SLOT ProfileWidget::showConnectionsTab()
void ProfileWidget::showConnectionsTab() {
    backgroundTab->setVisible( false );
    connectionsTab->setVisible( true );
    setProfileButtonSelected( connectionsTabButton );
    otherInfoTab->setVisible( false );
}
// SLOT ProfileWidget::showOtherInfoTab()
void ProfileWidget::showOtherInfoTab() {
    backgroundTab->setVisible( false );
    connectionsTab->setVisible( false );
    otherInfoTab->setVisible( true );
    setProfileButtonSelected( otherInfoTabButton );
}

// SLOT ProfileWidget::openEditProfileDialog
void ProfileWidget::openEditProfileDialog() {
    EditProfileDialog *editProfileDialog = new EditProfileDialog( this );
    connect( editProfileDialog, SIGNAL( updateProfileInfoSignal( const QString&, const QString& ) ),
             this, SLOT( updateProfileInfoSlot( const QString&, const QString& ) ) );

    editProfileDialog->exec();
}

// SLOT ProfileWidget::updateProfileInfoSlot( QString, QString )
void ProfileWidget::updateProfileInfoSlot( const QString& n, const QString& s ) {
    nameSurnameLabel->setText( "<h1>" + n + " " + s + "</h1>" );

    user->setName( n );
    user->setSurname( s );
}

// SLOT ProfileWidget::jobToAddSlot
void ProfileWidget::jobToAddSlot( const SmartLavoro& sl ) {
    user->addExperience( sl );

    lastExperienceLabel->setText( sl->getTitle() + " at " + sl->getCompanyName() );
}

// SLOT ProfileWidget::jobToRemove
void ProfileWidget::jobToRemoveSlot( const SmartLavoro& sl ) {
    user->removeExperience( sl );

    QVector<SmartLavoro> experiencesList = user->getExperiencesList();
    if( experiencesList.size() == 0 ) {
        lastExperienceLabel->setText( "--" );
    } else {
        SmartLavoro aux = experiencesList.last();
        lastExperienceLabel->setText( aux->getTitle() + " at " + aux->getCompanyName() );
    }
}

// SLOT ProfileWidget::updateLastJobInfoSlot
void ProfileWidget::updateLastJobInfoSlot( const SmartLavoro& sl ) {
    lastExperienceLabel->setText( sl->getTitle() + " at " + sl->getCompanyName() );
}

// SLOT ProfileWidget::titleToAddSlot
void ProfileWidget::titleToAddSlot( const SmartTitolo& st ) {
    user->addEducation( st );

    lastEducationLabel->setText( st->getFieldOfStudy() + " at " + st->getSchool() );
}

// SLOT ProfileWidget::titleToRemoveSlot
void ProfileWidget::titleToRemoveSlot( const SmartTitolo& st ) {
    user->removeEducation( st );

    QVector<SmartTitolo> educationsList = user->getEducationsList();
    if( educationsList.size() == 0 ) {
        lastEducationLabel->setText( "--" );
    } else {
        SmartTitolo aux = educationsList.last();
        lastEducationLabel->setText( aux->getFieldOfStudy() + " at " + aux->getSchool() );
    }
}

// SLOT ProfileWidget::updateLastTitleInfoSlot
void ProfileWidget::updateLastTitleInfoSlot( const SmartTitolo& st ) {
    lastEducationLabel->setText( st->getFieldOfStudy() + " at " + st->getSchool() );
}

// SLOT ProfileWidget::addContact
void ProfileWidget::addContact() {
    emit addContactSignal( user );

    addContactButton->setVisible( false );
    removeContactButton->setVisible( true );
}

// SLOT ProfileWidget::removeContact
void ProfileWidget::removeContact() {
    emit removeContactSignal( user );

    addContactButton->setVisible( true );
    removeContactButton->setVisible( false );
}

// SLOT ProfileWidget::contactToRemoveSlot
void ProfileWidget::contactToRemoveSlot( const SmartUtente& su ) {
    user->removeContact( su );

    emit removeContactSignal( su );

    connectionsNumber->setText(
                QString::number( user->getContactsList().size() ) + tr( " connections" ) );
}
