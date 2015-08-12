#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "titlewidget.h"
#include "titolo.h"

// COSTRUTTORE TitleWidget
TitleWidget::TitleWidget( const SmartTitolo& st, QWidget *parent ) :
    QWidget( parent )
{
    initUI( st );
    setupUI();
}

// METODO TitleWidget::initUI
void TitleWidget::initUI( const SmartTitolo& st ) {
    titleIconLabel = new QLabel( this );

    schoolLabel = new QLabel( st->getSchool() );
    fieldOfStudyLabel = new QLabel( st->getFieldOfStudy() );
    dateAttendedLabel = new QLabel( st->getDateAttended().toString( "yyyy/MM/dd" ) );

    removeTitleButton = new QPushButton( this );
    editTitleButton = new QPushButton( this );
}

// METODO TitleWidget::setupUI
void TitleWidget::setupUI() {
    titleIconLabel->setPixmap( QPixmap( ":/icons/icon/school.png" ) );
    titleIconLabel->setMargin( 10 );

    QWidget *titleInfoWidget = new QWidget( this );

    schoolLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.87 ); font: bold; }" );
    fieldOfStudyLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.87 ); }" );
    dateAttendedLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.54 ); }" );

    QWidget *moreInfoWidget = new QWidget( titleInfoWidget );

    QWidget *moreInfoFiller = new QWidget( moreInfoWidget );
    moreInfoFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );

    QHBoxLayout *moreInfoLayout = new QHBoxLayout( moreInfoWidget );
    moreInfoLayout->addWidget( fieldOfStudyLabel );
    moreInfoLayout->addSpacing( 30 );
    moreInfoLayout->addWidget( dateAttendedLabel );
    moreInfoLayout->addWidget( moreInfoFiller );
    moreInfoLayout->setMargin( 0 );

    QVBoxLayout *titleInfoLayout = new QVBoxLayout( titleInfoWidget );
    titleInfoLayout->addWidget( schoolLabel );
    titleInfoLayout->addWidget( moreInfoWidget );

    QWidget *toolWidget = new QWidget( this );

    removeTitleButton->setIcon( QIcon( QPixmap( ":/icons/icon/delete.png" ) ) );
    setToolButtonProperties( removeTitleButton );
    editTitleButton->setIcon( QIcon( QPixmap( ":/icons/icon/pencil.png" ) ) );
    setToolButtonProperties( editTitleButton );

    QVBoxLayout *toolLayout = new QVBoxLayout( toolWidget );
    toolLayout->addWidget( removeTitleButton );
    toolLayout->addWidget( editTitleButton );
    toolLayout->setMargin( 0 );

    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->addWidget( titleIconLabel );
    layout->addWidget( titleInfoWidget );
    layout->addWidget( toolWidget );
}

// METODO TitleWidget::setToolButtonProperties
void TitleWidget::setToolButtonProperties( QPushButton *button ) {
    button->setFixedSize( 24, 24 );
    button->setStyleSheet(
        "QPushButton { border-radius: 12px; outline: 0; }"
        "QPushButton:pressed { background: rgba(0,0,0,0.12); }"
    );
}
