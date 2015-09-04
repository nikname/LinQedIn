#include <QBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
#include "editjobdialog.h"
#include "jobwidget.h"
#include "lavoro.h"

// COSTRUTTORE JobWidget
JobWidget::JobWidget( const SmartLavoro& sl, QWidget *parent ) :
    QWidget( parent ),
    job( sl )
{
    initUI();
    setupUI();
}

// METODO JobWidget::initUI
void JobWidget::initUI() {
    jobIconLabel = new QLabel( this );

    companyNameLabel = new QLabel( job->getCompanyName(), this );
    titleLabel = new QLabel( job->getTitle(), this );
    periodLabel = new QLabel( job->getBegin().toString( "dd/MM/yyyy" ) + " - " +
                              job->getEnd().toString( "dd/MM/yyyy" ), this );

    removeJobButton = new QPushButton( this );
    connect( removeJobButton, SIGNAL( clicked() ), this, SLOT( removeJob() ) );
    editJobButton = new QPushButton( this );
    connect( editJobButton, SIGNAL( clicked() ), this, SLOT( openEditJobDialog() ) );
}

// METODO JobWidget::setupUI
void JobWidget::setupUI() {
    jobIconLabel->setPixmap( QPixmap( ":/icons/icon/factory.png" ) );
    jobIconLabel->setMargin( 10 );

    QWidget *jobInfoWidget = new QWidget( this );

    companyNameLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.87); font: bold; }" );
    titleLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.87); }" );
    periodLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); }" );

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

    setStyleSheet( "JobWidget { border: 1px solid rgba(0,0,0,0.12);"
                   "border-top: none; border-left: none; border-right: none; }" );
}

// METODO JobWidget::paintEvent
void JobWidget::paintEvent( QPaintEvent *) {
    QStyleOption opt;
    opt.init( this );
    QPainter p( this );
    style()->drawPrimitive( QStyle::PE_Widget, &opt, &p, this );
}

// METODO JobWidget::setToolButtonProperties
void JobWidget::setToolButtonProperties( QPushButton *button ) {
    button->setFixedSize( 24, 24 );
    button->setStyleSheet(
        "QPushButton { border-radius: 12px; outline: 0; }"
        "QPushButton:pressed { background: rgba(0,0,0,0.12); }"
    );
}

// METODO JobWidget::getJob
SmartLavoro JobWidget::getJob() {
    return job;
}

// METODO JobWidget::hideToolsButtons
void JobWidget::hideToolsButtons() {
    removeJobButton->setVisible( false );
    editJobButton->setVisible( false );
}

// SLOT JobWidget::openEditJobDialog
void JobWidget::openEditJobDialog() {
    EditJobDialog *editJobDialog = new EditJobDialog( this );
    connect( editJobDialog, SIGNAL( updateJobInfoSignal( QString, QString, int, int ) ),
             this, SLOT( updateJobInfoSlot( QString, QString, int, int ) ) );

    editJobDialog->exec();
}

// SLOT JobWidget::updateJobInfoSlot
void JobWidget::updateJobInfoSlot( const QString& cn, const QString& t, int b, int e ) {
    job->setCompanyName( cn );
    job->setTitle( t );
    job->setBegin( QDate( b, 1, 1 ) );
    job->setEnd( QDate( e, 1, 1 ) );

    companyNameLabel->setText( cn );
    titleLabel->setText( t );
    periodLabel->setText( QString::number( b ) + " - " + QString::number( e ) );

    emit updateJobInfoSignal( job );
}

// SLOT JobWidget::removeJob
void JobWidget::removeJob() {
    emit removeJobSignal( job );
}
