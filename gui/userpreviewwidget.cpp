#include <QGridLayout>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "userpreviewwidget.h"
#include "utente.h"
#include "smartlavoro.h"

// COSTRUTTORE UserPreviewWidget
UserPreviewWidget::UserPreviewWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent )
{
    QHBoxLayout *layout = new QHBoxLayout( this );

    profilePicLabel = new QLabel( this );
    profilePicLabel->setPixmap( QPixmap( ":/icons/icon/account-circle.png" ) );

    QWidget *rightWidget = new QWidget( this );

    QVBoxLayout *rightLayout = new QVBoxLayout( rightWidget );
    rightLayout->setMargin( 0 );
    rightLayout->setSpacing( 0 );

    QWidget *infoPreviewWidget = new QWidget( rightWidget );

    QVBoxLayout *infoPreviewLayout = new QVBoxLayout( infoPreviewWidget );

    userLabel = new QLabel( su->getName() + " " + su->getSurname(), infoPreviewWidget );
    userLabel->setStyleSheet( "QLabel { font: bold; color: rgba(0,0,0,0.87); }" );

    QVector<SmartLavoro> experiencesList = su->getExperiencesList();
    if( experiencesList.size() == 0 )
        lastJobLabel = new QLabel( "--", infoPreviewWidget );
    else {
        SmartLavoro lastJob = experiencesList.last();
        lastJobLabel = new QLabel(
                    lastJob->getTitle() + " at " + lastJob->getCompanyName(), infoPreviewWidget );
    }

    infoPreviewLayout->addWidget( userLabel );
    infoPreviewLayout->addWidget( lastJobLabel );

    toolWidget = new QWidget( rightWidget );

    QHBoxLayout *toolLayout = new QHBoxLayout( toolWidget );
    toolLayout->setMargin( 0 );
    toolLayout->setSpacing( 0 );

    QWidget *toolFiller = new QWidget( toolWidget );
    toolFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );

    viewContactButton = new QPushButton( toolWidget );
    viewContactButton->setIcon( QIcon( QPixmap( ":/icons/icon/magnify-black.png" ) ) );
    viewContactButton->setFixedSize( 24, 24 );

    removeContactButton = new QPushButton( toolWidget );
    removeContactButton->setIcon( QIcon( QPixmap( ":/icons/icon/close-black.png" ) ) );
    removeContactButton->setFixedSize( 24, 24 );

    toolLayout->addWidget( toolFiller );
    toolLayout->addWidget( viewContactButton );
    toolLayout->addWidget( removeContactButton );

    rightLayout->addWidget( toolWidget );
    rightLayout->addWidget( infoPreviewWidget );

    layout->addWidget( profilePicLabel );
    layout->addWidget( rightWidget );
    layout->setMargin( 0 );

    setMaximumWidth( 350 );
    setStyleSheet( "background: red" );
}
