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
    header = new QWidget( this );

    profilePicWidget = new QWidget( header );
    profilePicLabel = new QLabel( profilePicWidget );

    profileSummary = new QWidget( header );
    nameSurnameLabel = new QLabel( "<h1>" + su->getName() + " " + su->getSurname() + "</h1>" );

    QVector<SmartLavoro> experiencesList = su->getExperiencesList();
    if( experiencesList.size() == 0 )
        lastExperienceLabel = new QLabel( "--" );
    else {
        SmartLavoro aux = experiencesList.last();
        lastExperienceLabel = new QLabel( aux->getTitle() + " at " + aux->getCompanyName() );
    }

    QVector<SmartTitolo> educationsList = su->getEducationsList();
    if( educationsList.size() == 0 )
        lastEducationLabel = new QLabel( "--" );
    else {
        SmartTitolo aux = educationsList.last();
        lastEducationLabel = new QLabel( aux->getFieldOfStudy() + " at " + aux->getSchool() );
    }

    QVector<SmartUtente> contactsList = su->getContactsList();
    connectionsNumber = new QLabel( QString::number( contactsList.size() ) + tr( " connections" ) );

    infoTabs = new QWidget( this );

    infoTabsButtonsWidget = new QWidget( infoTabs );
    backgroundTabButton = new QPushButton( tr( "Background" ), infoTabsButtonsWidget );
    connectionsTabButton = new QPushButton( tr( "Connections" ), infoTabsButtonsWidget );
    otherInfoTabButton = new QPushButton( tr( "Other info" ), infoTabsButtonsWidget );
    addContactButton = new QPushButton( infoTabsButtonsWidget );

    backgroundTab = new QWidget( infoTabs );

    experiencesLabel = new QLabel( tr( "Experiences" ), backgroundTab );
    experiencesWidget = new ExperiencesWidget( su, backgroundTab );

    educationsLabel = new QLabel( tr( "Educations" ), backgroundTab );
    educationsWidget = new EducationsWidget( su, backgroundTab );

    connectionsTab = new ConnectionsWidget( su, infoTabs );
    otherInfoTab = new QWidget( infoTabs );
}

// METODO ProfileWidget::setupUI
void ProfileWidget::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout( this );

    header->setStyleSheet( "background: white" );

    QHBoxLayout *headerLayout = new QHBoxLayout( header );

    profilePicWidget->setFixedSize( 140, 140 );

    QVBoxLayout *profilePicLayout = new QVBoxLayout( profilePicWidget );
    profilePicLayout->setMargin( 20 );

    profilePicLabel->setPixmap( QPixmap( ":/icons/icon/account-circle-100.png" ) );

    profilePicLayout->addWidget( profilePicLabel, 0, Qt::AlignCenter );

    QVBoxLayout *profileSummaryLayout = new QVBoxLayout( profileSummary );

    nameSurnameLabel->setStyleSheet( "color: rgba( 0, 0, 0, 0.87 )" );
    lastExperienceLabel->setStyleSheet( "color: rgba( 0, 0, 0, 0.54 );" );
    lastEducationLabel->setStyleSheet( "color: rgba( 0, 0, 0, 0.54 );" );

    QWidget *profileSummaryFiller = new QWidget( profileSummary );
    profileSummaryFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    profileSummaryLayout->addWidget( nameSurnameLabel );
    profileSummaryLayout->addWidget( lastExperienceLabel );
    profileSummaryLayout->addWidget( lastEducationLabel );
    profileSummaryLayout->addWidget( connectionsNumber, 0, Qt::AlignRight );
    profileSummaryLayout->addWidget( profileSummaryFiller );

    headerLayout->addWidget( profilePicWidget );
    headerLayout->addWidget( profileSummary );

    QVBoxLayout *infoTabLayout = new QVBoxLayout( infoTabs );
    infoTabLayout->setMargin( 0 );

    infoTabsButtonsWidget->setStyleSheet( "background: white" );

    QHBoxLayout *infoTabsButtonLayout = new QHBoxLayout( infoTabsButtonsWidget );

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
    setProfileButtonSelected( backgroundTabButton );

    QWidget *buttonsFiller = new QWidget( infoTabsButtonsWidget );
    buttonsFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    infoTabsButtonLayout->addWidget( backgroundTabButton );
    infoTabsButtonLayout->addWidget( connectionsTabButton );
    infoTabsButtonLayout->addWidget( otherInfoTabButton );
    infoTabsButtonLayout->addWidget( buttonsFiller );
    infoTabsButtonLayout->addWidget( addContactButton );

    QVBoxLayout *backgroundTabLayout = new QVBoxLayout( backgroundTab );
    backgroundTabLayout->setMargin( 0 );

    experiencesLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); padding-left: 10px; }" );
    educationsLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); padding-left: 10px; }" );

    backgroundTabLayout->addWidget( experiencesLabel );
    backgroundTabLayout->addWidget( experiencesWidget );
    backgroundTabLayout->addWidget( educationsLabel );
    backgroundTabLayout->addWidget( educationsWidget );

    connectionsTab->setVisible( false );
    otherInfoTab->setVisible( false );

    infoTabLayout->addWidget( infoTabsButtonsWidget );
    infoTabLayout->addWidget( backgroundTab );
    infoTabLayout->addWidget( connectionsTab );
    infoTabLayout->addWidget( otherInfoTab );

    layout->addWidget( header );
    layout->addWidget( infoTabs );

    setLayout( layout );
}

// METODO ProfileWidget::setProfileButtonProperties( QPushButton* )
void ProfileWidget::setProfileButtonProperties( QPushButton *button ) {
    button->setFixedHeight( 40 );
    button->setStyleSheet(
        "QPushButton { padding: 0 10px; border: 3px solid white; font: bold;"
            "color: rgba( 0, 0, 0, 0.54 ); outline: 0; }"
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
                    "color: rgba( 0, 0, 0, 0.54 ); outline: 0; }"
                "QPushButton:hover { border-bottom-color: #069; }"
            );
        } else {
            buttonSelected->setStyleSheet(
                "QPushButton { padding: 0 10px; border: 3px solid white; font: bold;"
                    "color: rgba( 0, 0, 0, 0.87 ); border-bottom-color: #069; outline: 0; }"
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
