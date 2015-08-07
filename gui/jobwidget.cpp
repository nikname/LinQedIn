#include <QVBoxLayout>
#include <QLabel>
#include "jobwidget.h"
#include "lavoro.h"

// COSTRUTTORE JobWidget
JobWidget::JobWidget( const SmartLavoro& sl, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout* layout = new QVBoxLayout( this );

    companyNameLabel = new QLabel( sl->getCompanyName() );
    companyNameLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.87 ); font: bold; }" );
    titleLabel = new QLabel( sl->getTitle() );
    titleLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.87 ); }" );
    locationLabel = new QLabel( sl->getLocation() );
    periodLabel = new QLabel( sl->getBegin().toString( "yyyy/MM/dd" ) + " - " +
                              sl->getEnd().toString( "yyyy/MM/dd" ) );
    periodLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.54 ); }" );

    QWidget *moreInfoWidget = new QWidget( this );

    QHBoxLayout *moreInfoLayout = new QHBoxLayout( moreInfoWidget );
    moreInfoLayout->setMargin( 0 );

    QWidget *moreInfoFiller = new QWidget( moreInfoWidget );
    moreInfoFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    moreInfoLayout->addWidget( titleLabel );
    moreInfoLayout->addSpacing( 30 );
    moreInfoLayout->addWidget( periodLabel );
    moreInfoLayout->addWidget( moreInfoFiller );

    layout->addWidget( companyNameLabel );
    layout->addWidget( moreInfoWidget );

    setLayout( layout );
}
