#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "usergridwidget.h"
#include "utente.h"
#include "smartlavoro.h"

// COSTRUTTORE UserGridWidget
UserGridWidget::UserGridWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent )
{

    QGridLayout *gridLayout = new QGridLayout( this );

    profilePicLabel = new QLabel( this );
    profilePicLabel->setPixmap( QPixmap( ":/icons/icon/account-circle.png" ) );

    userLabel = new QLabel( su->getName() + " " + su->getSurname() );

    QVector<SmartLavoro> experiencesList = su->getExperiencesList();
    if( experiencesList.size() == 0 )
        lastJobLabel = new QLabel( "--" );
    else {
        SmartLavoro lastJob = experiencesList.last();
        lastJobLabel = new QLabel( lastJob->getTitle() + " at " + lastJob->getCompanyName() );
    }

    toolWidget = new QWidget( this );

    QHBoxLayout *toolLayout = new QHBoxLayout( toolWidget );
    toolLayout->setMargin( 0 );

    QWidget *toolFiller = new QWidget( toolWidget );
    toolFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );

    viewContactButton = new QPushButton( toolWidget );
    viewContactButton->setIcon( QIcon( QPixmap( ":/icons/icon/magnify.png" ) ) );
    viewContactButton->setFixedSize( 20, 20 );
    viewContactButton->setFlat( true );

    removeContactButton = new QPushButton( toolWidget );
    removeContactButton->setIcon( QIcon( QPixmap( ":/icons/icon/close.png" ) ) );
    removeContactButton->setFixedSize( 20, 20 );
    removeContactButton->setFlat( true );

    toolLayout->addWidget( toolFiller );
    toolLayout->addWidget( viewContactButton );
    toolLayout->addWidget( removeContactButton );

    gridLayout->addWidget( profilePicLabel, 0, 0, 3, 1 );
    gridLayout->addWidget( toolWidget, 0, 1, 1, 4 );
    gridLayout->addWidget( userLabel, 1, 1, 1, 4 );
    gridLayout->addWidget( lastJobLabel, 2, 1, 4, 4 );


    setStyleSheet( "background: red" );
}
