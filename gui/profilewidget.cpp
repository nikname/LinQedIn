#include <QVBoxLayout>
#include <QLabel>
#include "profilewidget.h"
#include "utente.h"
#include "smartlavoro.h"
#include "smarttitolo.h"

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

    profilePicWidget->setLayout( profilePicLayout );

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
    numberOfConnections = new QLabel( QString::number( contactsList.size() ) + tr( " connections" ) );

    QWidget *profileSummaryFiller = new QWidget( profileSummary );
    profileSummaryFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    profileSummaryLayout->addWidget( nameSurnameLabel );
    profileSummaryLayout->addWidget( lastExperienceLabel );
    profileSummaryLayout->addWidget( lastEducationLabel );
    profileSummaryLayout->addWidget( numberOfConnections, 0, Qt::AlignRight );
    profileSummaryLayout->addWidget( profileSummaryFiller );

    profileSummary->setLayout( profileSummaryLayout );

    headerLayout->addWidget( profilePicWidget );
    headerLayout->addWidget( profileSummary );

    header->setLayout( headerLayout );

    layout->addWidget( header );

    setStyleSheet( "background: white; color: black;" );
    setLayout( layout );
}
