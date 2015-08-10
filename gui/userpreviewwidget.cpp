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
    QVBoxLayout *layout = new QVBoxLayout( this );

    QWidget *wrapper = new QWidget( this );

    QHBoxLayout *wrapperLayout = new QHBoxLayout( wrapper );

    QWidget *profilePicWidget = new QWidget( wrapper );
    profilePicWidget->setFixedSize( 100, 100 );

    QVBoxLayout *profilePicLayout = new QVBoxLayout( profilePicWidget );

    profilePicLabel = new QLabel( profilePicWidget );
    profilePicLabel->setPixmap( QPixmap( ":/icons/icon/account-circle.png" ) );

    profilePicLayout->addWidget( profilePicLabel, 0, Qt::AlignCenter );

    QWidget *rightWidget = new QWidget( wrapper );

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
    lastJobLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); }" );

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
    setToolButtonProperties( viewContactButton );

    removeContactButton = new QPushButton( toolWidget );
    removeContactButton->setIcon( QIcon( QPixmap( ":/icons/icon/close-black.png" ) ) );
    setToolButtonProperties( removeContactButton );

    toolLayout->addWidget( toolFiller );
    toolLayout->addWidget( viewContactButton );
    toolLayout->addWidget( removeContactButton );

    rightLayout->addWidget( toolWidget );
    rightLayout->addWidget( infoPreviewWidget );

    wrapperLayout->addWidget( profilePicWidget );
    wrapperLayout->addWidget( rightWidget );
    wrapperLayout->setMargin( 0 );

    layout->addWidget( wrapper );

    wrapper->setStyleSheet( "background: white" );

    setMaximumWidth( 350 );
}

// METODO UserPreviewWidget::setToolButtonProperties
void UserPreviewWidget::setToolButtonProperties( QPushButton* button ) {
    button->setFixedSize( 24, 24 );
    button->setStyleSheet(
        "QPushButton { border-radius: 12px; outline: 0; }"
        "QPushButton:pressed { background: rgba(0,0,0,0.12); }"
    );
}
