#include <QLabel>
#include <QPushButton>
#include "connectionswidget.h"
#include "educationswidget.h"
#include "experienceswidget.h"
#include "profilewidget.h"
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

// DISTRUTTORE ProfileWidget
ProfileWidget::~ProfileWidget() {}

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

    backgroundTabButton = new QPushButton( tr( "Background" ), this );
    connect( backgroundTabButton, SIGNAL( clicked() ), this, SLOT( showBackgroundTab() ) );
    connectionsTabButton = new QPushButton( tr( "Connections" ), this );
    connect( connectionsTabButton, SIGNAL( clicked() ), this, SLOT( showConnectionsTab() ) );
    otherInfoTabButton = new QPushButton( tr( "Other info" ), this );
    connect( otherInfoTabButton, SIGNAL( clicked() ), this, SLOT( showOtherInfoTab() ) );

    tabButtons.append( backgroundTabButton );
    tabButtons.append( connectionsTabButton );
    tabButtons.append( otherInfoTabButton );

    backgroundTab = new QWidget( this );

    experiencesLabel = new QLabel( tr( "Experiences" ), backgroundTab );
    experiencesWidget = new ExperiencesWidget( user, backgroundTab );

    educationsLabel = new QLabel( tr( "Educations" ), backgroundTab );
    educationsWidget = new EducationsWidget( user, backgroundTab );

    connectionsTab = new ConnectionsWidget( user, this );
    connect( connectionsTab, SIGNAL( showContactSignal( SmartUtente ) ),
             this, SIGNAL( showContactSignal( SmartUtente ) ) );

    otherInfoTab = new QWidget( this );
}

// METODO ProfileWidget::setupUI
void ProfileWidget::setupUI() {
    profilePicLabel->setPixmap( QPixmap( ":/icons/icon/account-circle-100.png" ) );
    profilePicLabel->setMargin( 20 );

    nameSurnameLabel->setStyleSheet( "color: rgba(0,0,0,0.87)" );
    lastExperienceLabel->setStyleSheet( "color: rgba(0,0,0,0.54);" );
    lastEducationLabel->setStyleSheet( "color: rgba(0,0,0,0.54);" );

    setProfileButtonProperties( backgroundTabButton );
    setProfileButtonProperties( connectionsTabButton );
    setProfileButtonProperties( otherInfoTabButton );

    setProfileButtonSelected( backgroundTabButton );

    experiencesLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); padding-left: 10px; }" );
    educationsLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); padding-left: 10px; }" );

    connectionsTab->setVisible( false );
    otherInfoTab->setVisible( false );
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
