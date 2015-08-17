#include <QGridLayout>
#include <QBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
#include "userpreviewwidget.h"
#include "utente.h"
#include "smartlavoro.h"
#include "lavoro.h"

// COSTRUTTORE UserPreviewWidget
UserPreviewWidget::UserPreviewWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent )
{
    initUI( su );
    setupUI();
}

// METODO UserPreviewWidget::initUI
void UserPreviewWidget::initUI( const SmartUtente& su ) {
    profilePicLabel = new QLabel( this );

    userLabel = new QLabel( su->getName() + " " + su->getSurname(), this );

    QVector<SmartLavoro> experiencesList = su->getExperiencesList();
    if( experiencesList.size() == 0 )
        lastJobLabel = new QLabel( "--", this );
    else {
        SmartLavoro lastJob = experiencesList.last();
        lastJobLabel = new QLabel( lastJob->getTitle() + " at " + lastJob->getCompanyName(), this );
    }

    contactInfoButton = new QPushButton( this );
    removeContactButton = new QPushButton( this );
}

// METODO UserPreviewWidget::setupUI
void UserPreviewWidget::setupUI() {
    profilePicLabel->setPixmap( QPixmap( ":/icons/icon/account-circle.png" ) );
    profilePicLabel->setMargin( 10 );

    QWidget *infoPreviewWidget = new QWidget( this );

    userLabel->setStyleSheet( "QLabel { font: bold; color: rgba(0,0,0,0.87); }" );
    lastJobLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); }" );

    QVBoxLayout *infoPreviewLayout = new QVBoxLayout( infoPreviewWidget );
    infoPreviewLayout->addWidget( userLabel );
    infoPreviewLayout->addWidget( lastJobLabel );

    QWidget *toolWidget = new QWidget( this );

    contactInfoButton->setIcon( QIcon( QPixmap( ":/icons/icon/information-outline.png" ) ) );
    setToolButtonProperties( contactInfoButton );
    removeContactButton->setIcon( QIcon( QPixmap( ":/icons/icon/close-black.png" ) ) );
    setToolButtonProperties( removeContactButton );

    QVBoxLayout *toolLayout = new QVBoxLayout( toolWidget );
    toolLayout->addWidget( removeContactButton );
    toolLayout->addWidget( contactInfoButton );
    toolLayout->setMargin( 0 );

    QWidget *filler = new QWidget( this );
    filler->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );

    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->addWidget( profilePicLabel );
    layout->addWidget( infoPreviewWidget );
    layout->addWidget( filler );
    layout->addWidget( toolWidget );
    layout->setSpacing( 0 );

    setMaximumWidth( 350 );
    setStyleSheet( "background: white" );
}

// METODO UserPreviewWidget::setToolButtonProperties
void UserPreviewWidget::setToolButtonProperties( QPushButton *button ) {
    button->setFixedSize( 24, 24 );
    button->setStyleSheet(
        "QPushButton { border-radius: 12px; outline: 0; }"
        "QPushButton:pressed { background: rgba(0,0,0,0.12); }"
    );
}

// METODO UserPrwview::paintEvent
void UserPreviewWidget::paintEvent( QPaintEvent *) {
    QStyleOption opt;
    opt.init( this );
    QPainter p( this );
    style()->drawPrimitive( QStyle::PE_Widget, &opt, &p, this );
}
