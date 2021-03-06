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
UserPreviewWidget::UserPreviewWidget( const SmartUtente& su, QList<QString> i, QWidget *parent ) :
    QWidget( parent ),
    user( su )
{
    initUI( i );
    setupUI();
}

// METODO UserPreviewWidget::initUI( QList<QString> )
void UserPreviewWidget::initUI( QList<QString> i ) {
    profilePicLabel = new QLabel( this );

    userLabel = new QLabel( user->getName() + " " + user->getSurname(), this );

    if( i.contains( "experiences" ) ) {
        QVector<SmartLavoro> experiencesList = user->getExperiencesList();
        if( experiencesList.size() == 0 )
            lastJobLabel = new QLabel( "--", this );
        else {
            SmartLavoro lastJob = experiencesList.last();
            lastJobLabel = new QLabel( lastJob->getTitle() + " at " + lastJob->getCompanyName(), this );
        }
    } else {
        lastJobLabel = 0;
    }

    userInfoButton = new QPushButton( this );
    connect( userInfoButton, SIGNAL( clicked() ), this, SLOT( showUser() ) );
    removeUserButton = new QPushButton( this );
    connect( removeUserButton, SIGNAL( clicked() ), this, SLOT( removeUser() ) );
}

// METODO UserPreviewWidget::setupUI
void UserPreviewWidget::setupUI() {
    profilePicLabel->setPixmap( QPixmap( ":/icons/icon/account-circle.png" ) );
    profilePicLabel->setMargin( 10 );

    QWidget *infoPreviewWidget = new QWidget( this );

    userLabel->setStyleSheet( "QLabel { font: bold; color: rgba(0,0,0,0.87); }" );
    if( lastJobLabel ) lastJobLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); }" );

    QVBoxLayout *infoPreviewLayout = new QVBoxLayout( infoPreviewWidget );
    infoPreviewLayout->addWidget( userLabel );
    if( lastJobLabel ) infoPreviewLayout->addWidget( lastJobLabel );

    QWidget *toolWidget = new QWidget( this );

    userInfoButton->setIcon( QIcon( QPixmap( ":/icons/icon/information-outline.png" ) ) );
    setToolButtonProperties( userInfoButton );
    removeUserButton->setIcon( QIcon( QPixmap( ":/icons/icon/close-black.png" ) ) );
    setToolButtonProperties( removeUserButton );

    QVBoxLayout *toolLayout = new QVBoxLayout( toolWidget );
    toolLayout->addWidget( removeUserButton );
    toolLayout->addWidget( userInfoButton );
    toolLayout->setMargin( 0 );

    QWidget *filler = new QWidget( this );
    filler->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );

    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->addWidget( profilePicLabel );
    layout->addWidget( infoPreviewWidget );
    layout->addWidget( filler );
    layout->addWidget( toolWidget );
    layout->setSpacing( 0 );

    setStyleSheet( "background: white" );
}

// METODO UserPreviewWidget::setToolButtonProperties( QPushButton * )
void UserPreviewWidget::setToolButtonProperties( QPushButton *button ) {
    button->setFixedSize( 24, 24 );
    button->setStyleSheet(
        "QPushButton { border-radius: 12px; outline: 0; }"
        "QPushButton:pressed { background: rgba(0,0,0,0.12); }"
    );
}

// METODO UserPreviewWidget::paintEvent( QPaintEvent * )
void UserPreviewWidget::paintEvent( QPaintEvent *) {
    QStyleOption opt;
    opt.init( this );
    QPainter p( this );
    style()->drawPrimitive( QStyle::PE_Widget, &opt, &p, this );
}

// METODO UserPreviewWidget::getUser
SmartUtente UserPreviewWidget::getUser() {
    return user;
}

// METODO UserPreviewWidget::hideRemoveUserButton
void UserPreviewWidget::hideRemoveUserButton() const {
    removeUserButton->setVisible( false );
}

// SLOT UserPreviewWidget::removeUser
void UserPreviewWidget::removeUser() {
    emit removeUserSignal( user );
}

// SLOT UserPreviewWidget::showUser
void UserPreviewWidget::showUser() {
    emit showUserSignal( user );
}
