#include <QBoxLayout>
#include <QLabel>
#include "jobwidget.h"
#include "lavoro.h"

// COSTRUTTORE JobWidget
JobWidget::JobWidget( const SmartLavoro& sl, QWidget *parent ) :
    QWidget( parent )
{
    initUI( sl );
    setupUI();
}

// METODO JobWidget::initUI
void JobWidget::initUI( const SmartLavoro& sl ) {
    jobIconLabel = new QLabel( this );

    companyNameLabel = new QLabel( sl->getCompanyName(), this );
    titleLabel = new QLabel( sl->getTitle(), this );
    periodLabel = new QLabel( sl->getBegin().toString( "yyyy/MM/dd" ) + " - " +
                              sl->getEnd().toString( "yyyy/MM/dd" ), this );
}

// METODO JobWidget::setupUI
void JobWidget::setupUI() {
    jobIconLabel->setPixmap( QPixmap( ":/icons/icon/factory.png" ) );
    jobIconLabel->setMargin( 10 );

    QWidget *rightWidget = new QWidget( this );

    companyNameLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.87 ); font: bold; }" );
    titleLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.87 ); }" );
    periodLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.54 ); }" );

    QWidget *moreInfoWidget = new QWidget( rightWidget );

    QWidget *moreInfoFiller = new QWidget( moreInfoWidget );
    moreInfoFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );

    QHBoxLayout *moreInfoLayout = new QHBoxLayout( moreInfoWidget );
    moreInfoLayout->addWidget( titleLabel );
    moreInfoLayout->addSpacing( 30 );
    moreInfoLayout->addWidget( periodLabel );
    moreInfoLayout->addWidget( moreInfoFiller );
    moreInfoLayout->setMargin( 0 );

    QVBoxLayout *rightLayout = new QVBoxLayout( rightWidget );
    rightLayout->addWidget( companyNameLabel );
    rightLayout->addWidget( moreInfoWidget );

    QHBoxLayout* layout = new QHBoxLayout( this );
    layout->addWidget( jobIconLabel );
    layout->addWidget( rightWidget );
}
