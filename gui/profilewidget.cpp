#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "profilewidget.h"
#include "utente.h"
#include "smartlavoro.h"
#include "smarttitolo.h"
#include "experienceswidget.h"

// COSTRUTTORE ProfileWidget
ProfileWidget::ProfileWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout( this );

    header = new QWidget( this );

    QHBoxLayout *headerLayout = new QHBoxLayout( header );

    profilePicWidget = new QWidget( header );
    profilePicWidget->setFixedSize( 140, 140 );

    QVBoxLayout *profilePicLayout = new QVBoxLayout( profilePicWidget );
    profilePicLayout->setMargin( 20 );

    profilePicLabel = new QLabel( profilePicWidget );
    profilePicLabel->setPixmap( QPixmap( ":/icons/icon/account-circle.png" ) );

    profilePicLayout->addWidget( profilePicLabel, 0, Qt::AlignCenter );

    profileSummary = new QWidget( header );

    QVBoxLayout *profileSummaryLayout = new QVBoxLayout( profileSummary );

    nameSurnameLabel = new QLabel( "<h1>" + su->getName() + " " + su->getSurname() + "</h1>" );
    nameSurnameLabel->setStyleSheet( "color: rgba( 0, 0, 0, 0.87 )" );

    QVector<SmartLavoro> experiencesList = su->getExperiencesList();
    if( experiencesList.size() == 0 )
        lastExperienceLabel = new QLabel( "--" );
    else {
        SmartLavoro aux = experiencesList.last();
        lastExperienceLabel = new QLabel( aux->getTitle() + " at " + aux->getCompanyName() );
    }
    lastExperienceLabel->setStyleSheet( "color: rgba( 0, 0, 0, 0.54 );" );

    QVector<SmartTitolo> educationsList = su->getEducationsList();
    if( educationsList.size() == 0 )
        lastEducationLabel = new QLabel( "" );
    else {
        SmartTitolo aux = educationsList.last();
        lastEducationLabel = new QLabel(
            "Eduction: " + aux->getFieldOfStudy() + " at " + aux->getSchool() );
    }
    lastEducationLabel->setStyleSheet( "color: rgba( 0, 0, 0, 0.54 );" );

    QVector<QString> contactsList = su->getContactsList();
    connectionsNumber = new QLabel( QString::number( contactsList.size() ) + tr( " connections" ) );

    QWidget *profileSummaryFiller = new QWidget( profileSummary );
    profileSummaryFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    profileSummaryLayout->addWidget( nameSurnameLabel );
    profileSummaryLayout->addWidget( lastExperienceLabel );
    profileSummaryLayout->addWidget( lastEducationLabel );
    profileSummaryLayout->addWidget( connectionsNumber, 0, Qt::AlignRight );
    profileSummaryLayout->addWidget( profileSummaryFiller );

    headerLayout->addWidget( profilePicWidget );
    headerLayout->addWidget( profileSummary );

    infoTabs = new QWidget( this );

    QVBoxLayout *infoTabLayout = new QVBoxLayout( infoTabs );

    infoTabsButtonsWidget = new QWidget( infoTabs );

    QHBoxLayout *infoTabsButtonLayout = new QHBoxLayout( infoTabsButtonsWidget );

    backgroundTabButton = new QPushButton( tr( "Background" ), infoTabsButtonsWidget );
    setProfileButtonProperties( backgroundTabButton );
    connectionsTabButton = new QPushButton( tr( "Connections" ), infoTabsButtonsWidget );
    setProfileButtonProperties( connectionsTabButton );
    otherInfoTabButton = new QPushButton( tr( "Other info" ), infoTabsButtonsWidget );
    setProfileButtonProperties( otherInfoTabButton );
    addContactButton = new QPushButton( infoTabsButtonsWidget );
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

    experiencesWidget = new ExperiencesWidget( su, infoTabs );

    infoTabLayout->addWidget( infoTabsButtonsWidget );
    infoTabLayout->addWidget( experiencesWidget );

    layout->addWidget( header );
    layout->addWidget( infoTabs );

    setStyleSheet( "background: white; color: black;" );
    setLayout( layout );
}


// METODO ProfileWidget::setProfileButtonProperties( QPushButton* )
void ProfileWidget::setProfileButtonProperties( QPushButton *button ) {
    button->setFixedHeight( 40 );
    button->setStyleSheet(
        "QPushButton {"
            "padding: 0 10px;"
            "border: 3px solid white;"
            "font: bold;"
            "color: rgba( 0, 0, 0, 0.54 );"
            "outline: 0;"
        "}"
        "QPushButton:hover {"
            "border-bottom-color: #069;"
        "}"
    );
}

// METODO ProfileWidget::setProfileButtonSelected( QPushButton* )
void ProfileWidget::setProfileButtonSelected( QPushButton *buttonSelected ) {
    QPushButton* buttons[3] = { backgroundTabButton, connectionsTabButton, otherInfoTabButton };
    for( int i = 0; i < 3; i++ ) {
        if( buttonSelected != buttons[i] ) {
            buttons[i]->setStyleSheet(
                "QPushButton {"
                    "padding: 0 10px;"
                    "border: 3px solid white;"
                    "font: bold;"
                    "color: rgba( 0, 0, 0, 0.54 );"
                    "outline: 0;"
                "}"
                "QPushButton:hover {"
                    "border-bottom-color: #069;"
                "}"
            );
        } else {
            buttonSelected->setStyleSheet(
                "QPushButton {"
                    "padding: 0 10px;"
                    "border: 3px solid white;"
                    "font: bold;"
                    "color: rgba( 0, 0, 0, 0.87 );"
                    "border-bottom-color: #069;"
                    "outline: 0;"
                "}"
            );
        }
    }
}
