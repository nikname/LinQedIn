#include <QBoxLayout>
#include <QLabel>
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
}

// METODO TitleWidget::setupUI
void TitleWidget::setupUI() {
    titleIconLabel->setPixmap( QPixmap( ":/icons/icon/school.png" ) );
    titleIconLabel->setMargin( 10 );

    QWidget *rightWidget = new QWidget( this );

    schoolLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.87 ); font: bold; }" );
    fieldOfStudyLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.87 ); }" );
    dateAttendedLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.54 ); }" );

    QWidget *moreInfoWidget = new QWidget( rightWidget );

    QWidget *moreInfoFiller = new QWidget( moreInfoWidget );
    moreInfoFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );

    QHBoxLayout *moreInfoLayout = new QHBoxLayout( moreInfoWidget );
    moreInfoLayout->addWidget( fieldOfStudyLabel );
    moreInfoLayout->addSpacing( 30 );
    moreInfoLayout->addWidget( dateAttendedLabel );
    moreInfoLayout->addWidget( moreInfoFiller );
    moreInfoLayout->setMargin( 0 );

    QVBoxLayout *rightLayout = new QVBoxLayout( rightWidget );
    rightLayout->addWidget( schoolLabel );
    rightLayout->addWidget( moreInfoWidget );

    QHBoxLayout *layout = new QHBoxLayout( this );
    layout->addWidget( titleIconLabel );
    layout->addWidget( rightWidget );
}
