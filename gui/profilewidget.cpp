#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "connectionswidget.h"
#include "educationswidget.h"
#include "experienceswidget.h"
#include "profilewidget.h"
#include "smartlavoro.h"
#include "smarttitolo.h"
#include "utente.h"

// COSTRUTTORE ProfileWidget
ProfileWidget::ProfileWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent )
{
    initUI( su );
    setupUI();
}

// METODO ProfileWidget::initUI
void ProfileWidget::initUI( const SmartUtente& su ) {
    profilePicLabel = new QLabel( this );

    profileSummary = new QWidget( this );
    nameSurnameLabel = new QLabel( "<h1>" + su->getName() + " " + su->getSurname() + "</h1>", this );

    QVector<SmartLavoro> experiencesList = su->getExperiencesList();
    if( experiencesList.size() == 0 )
        lastExperienceLabel = new QLabel( "--", this );
    else {
        SmartLavoro aux = experiencesList.last();
        lastExperienceLabel = new QLabel( aux->getTitle() + " at " + aux->getCompanyName(), this );
    }

    QVector<SmartTitolo> educationsList = su->getEducationsList();
    if( educationsList.size() == 0 )
        lastEducationLabel = new QLabel( "--", this );
    else {
        SmartTitolo aux = educationsList.last();
        lastEducationLabel = new QLabel( aux->getFieldOfStudy() + " at " + aux->getSchool(), this );
    }

    QVector<SmartUtente> contactsList = su->getContactsList();
    connectionsNumber = new QLabel(
                QString::number( contactsList.size() ) + tr( " connections" ), this );

    editProfileButton = new QPushButton( this );

    backgroundTabButton = new QPushButton( tr( "Background" ), this );
    connectionsTabButton = new QPushButton( tr( "Connections" ), this );
    otherInfoTabButton = new QPushButton( tr( "Other info" ), this );

    addContactButton = new QPushButton( this );
    removeContactButton = new QPushButton( this );

    backgroundTab = new QWidget( this );

    experiencesLabel = new QLabel( tr( "Experiences" ), backgroundTab );
    experiencesWidget = new ExperiencesWidget( su, backgroundTab );

    educationsLabel = new QLabel( tr( "Educations" ), backgroundTab );
    educationsWidget = new EducationsWidget( su, backgroundTab );

    connectionsTab = new ConnectionsWidget( su, this );

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
    connect( backgroundTabButton, SIGNAL( clicked() ), this, SLOT( showBackgroundTab() ) );
    setProfileButtonProperties( connectionsTabButton );
    connect( connectionsTabButton, SIGNAL( clicked() ), this, SLOT( showConnectionsTab() ) );
    setProfileButtonProperties( otherInfoTabButton );
    connect( otherInfoTabButton, SIGNAL( clicked() ), this, SLOT( showOtherInfoTab() ) );

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
    removeContactButton->setVisible( false );

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
void ProfileWidget::setProfileButtonSelected( QPushButton *buttonSelected ) {
    QPushButton* buttons[3] = { backgroundTabButton, connectionsTabButton, otherInfoTabButton };
    for( int i = 0; i < 3; i++ ) {
        if( buttonSelected != buttons[i] ) {
            buttons[i]->setStyleSheet(
                "QPushButton { padding: 0 10px; border: 3px solid white; font: bold;"
                    "color: rgba(0,0,0,0.54); outline: 0; }"
                "QPushButton:hover { border-bottom-color: #069; }"
            );
        } else {
            buttonSelected->setStyleSheet(
                "QPushButton { padding: 0 10px; border: 3px solid white; font: bold;"
                    "color: rgba(0,0,0,0.87); border-bottom-color: #069; outline: 0; }"
            );
        }
    }
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
