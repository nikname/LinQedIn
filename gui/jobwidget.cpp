#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
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

    removeJobButton = new QPushButton( this );
    editJobButton = new QPushButton( this );
}

// METODO JobWidget::setupUI
void JobWidget::setupUI() {
    jobIconLabel->setPixmap( QPixmap( ":/icons/icon/factory.png" ) );
    jobIconLabel->setMargin( 10 );

    QWidget *jobInfoWidget = new QWidget( this );

    companyNameLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.87 ); font: bold; }" );
    titleLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.87 ); }" );
    periodLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.54 ); }" );

    QWidget *moreInfoWidget = new QWidget( jobInfoWidget );

    QWidget *moreInfoFiller = new QWidget( moreInfoWidget );
    moreInfoFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );

    QHBoxLayout *moreInfoLayout = new QHBoxLayout( moreInfoWidget );
    moreInfoLayout->addWidget( titleLabel );
    moreInfoLayout->addSpacing( 30 );
    moreInfoLayout->addWidget( periodLabel );
    moreInfoLayout->addWidget( moreInfoFiller );
    moreInfoLayout->setMargin( 0 );

    QVBoxLayout *jobInfoLayout = new QVBoxLayout( jobInfoWidget );
    jobInfoLayout->addWidget( companyNameLabel );
    jobInfoLayout->addWidget( moreInfoWidget );

    QWidget *toolWidget = new QWidget( this );

    removeJobButton->setIcon( QIcon( QPixmap( ":/icons/icon/delete.png" ) ) );
    setToolButtonProperties( removeJobButton );
    editJobButton->setIcon( QIcon( QPixmap( ":/icons/icon/pencil.png" ) ) );
    setToolButtonProperties( editJobButton );

    QVBoxLayout *toolLayout = new QVBoxLayout( toolWidget );
    toolLayout->addWidget( removeJobButton );
    toolLayout->addWidget( editJobButton );
    toolLayout->setMargin( 0 );

    QHBoxLayout* layout = new QHBoxLayout( this );
    layout->addWidget( jobIconLabel );
    layout->addWidget( jobInfoWidget );
    layout->addWidget( toolWidget );
}

// METODO JobWidget::setToolButtonProperties
void JobWidget::setToolButtonProperties( QPushButton *button ) {
    button->setFixedSize( 24, 24 );
    button->setStyleSheet(
        "QPushButton { border-radius: 12px; outline: 0; }"
        "QPushButton:pressed { background: rgba(0,0,0,0.12); }"
    );
}
