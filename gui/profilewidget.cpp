#include <QVBoxLayout>
#include <QLabel>
#include "profilewidget.h"
#include "utente.h"

// COSTRUTTORE ProfileWidget
ProfileWidget::ProfileWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout( this );

    header = new QWidget( this );

    QHBoxLayout *headerLayout = new QHBoxLayout( header );

    profilePicWidget = new QWidget( header );
    profilePicWidget->setFixedSize( 150, 150 );

    QVBoxLayout *profilePicLayout = new QVBoxLayout( profilePicWidget );
    profilePicLayout->setMargin( 0 );

    profilePicLabel = new QLabel( profilePicWidget );
    profilePicLabel->setPixmap( QPixmap( ":/icons/icon/account-circle.png" ) );

    profilePicLayout->addWidget( profilePicLabel, 0, Qt::AlignCenter );

    profilePicWidget->setLayout( profilePicLayout );

    profileSummary = new QWidget( header );

    QVBoxLayout *profileSummaryLayout = new QVBoxLayout( profileSummary );

    nameSurnameLabel = new QLabel( "<h1>" + su->getName() + " " + su->getSurname() + "</h1>" );
    lastEducationLabel = new QLabel( "Scuola" );
    lastExperienceLabel = new QLabel( "Azienda" );

    profileSummaryLayout->addWidget( nameSurnameLabel );
    profileSummaryLayout->addWidget( lastEducationLabel );
    profileSummaryLayout->addWidget( lastExperienceLabel );

    profileSummary->setLayout( profileSummaryLayout );

    headerLayout->addWidget( profilePicWidget );
    headerLayout->addWidget( profileSummary );

    header->setLayout( headerLayout );
    header->setFixedHeight( 200 );

    layout->addWidget( header );

    setStyleSheet( "background: white; color: black;" );
    setLayout( layout );
}
