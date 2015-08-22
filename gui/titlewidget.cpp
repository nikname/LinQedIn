#include <QBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
#include "edittitledialog.h"
#include "titlewidget.h"
#include "titolo.h"

// COSTRUTTORE TitleWidget
TitleWidget::TitleWidget( const SmartTitolo& st, QWidget *parent ) :
    QWidget( parent ),
    title( st )
{
    initUI();
    setupUI();
}

// METODO TitleWidget::initUI
void TitleWidget::initUI() {
    titleIconLabel = new QLabel( this );

    schoolLabel = new QLabel( title->getSchool() );
    fieldOfStudyLabel = new QLabel( title->getFieldOfStudy() );
    dateAttendedLabel = new QLabel( title->getDateAttended().toString( "yyyy/MM/dd" ) );

    removeTitleButton = new QPushButton( this );
    connect( removeTitleButton, SIGNAL( clicked() ), this, SLOT( removeTitle() ) );
    editTitleButton = new QPushButton( this );
    connect( editTitleButton, SIGNAL( clicked() ), this, SLOT( openEditTitleDialog() ) );
}

// METODO TitleWidget::setupUI
void TitleWidget::setupUI() {
    titleIconLabel->setPixmap( QPixmap( ":/icons/icon/school.png" ) );
    titleIconLabel->setMargin( 10 );

    QWidget *titleInfoWidget = new QWidget( this );

    schoolLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.87); font: bold; }" );
    fieldOfStudyLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.87); }" );
    dateAttendedLabel->setStyleSheet( "QLabel { color: rgba(0,0,0,0.54); }" );

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

    setStyleSheet( "TitleWidget { border: 1px solid rgba(0,0,0,0.12);"
                   "border-top: none; border-left: none; border-right: none; }" );
}

// METODO TitleWidget::paintEvent
void TitleWidget::paintEvent( QPaintEvent *) {
    QStyleOption opt;
    opt.init( this );
    QPainter p( this );
    style()->drawPrimitive( QStyle::PE_Widget, &opt, &p, this );
}

// METODO TitleWidget::setToolButtonProperties
void TitleWidget::setToolButtonProperties( QPushButton *button ) {
    button->setFixedSize( 24, 24 );
    button->setStyleSheet(
        "QPushButton { border-radius: 12px; outline: 0; }"
        "QPushButton:pressed { background: rgba(0,0,0,0.12); }"
    );
}

// METODO TitleWidget::getTitle
SmartTitolo TitleWidget::getTitle() {
    return title;
}

// SLOT TitleWidget::openEditTitleDialog
void TitleWidget::openEditTitleDialog() {
    EditTitleDialog *editTitleDialog = new EditTitleDialog( this );
    connect( editTitleDialog, SIGNAL( updateTitleInfoSignal( QString, int, int, int, QString ) ),
             this, SLOT( updateTitleInfoSlot( QString, int, int, int, QString ) ) );

    editTitleDialog->exec();
}

// SLOT TitleWidget::updateTitleInfoSlot( QString, int, int, int, QString )
void TitleWidget::updateTitleInfoSlot( const QString& s, int d, int m, int y, const QString& fos ) {
    title->setSchool( s );
    title->setDateAttended( QDate( y, m, d ) );
    title->setFieldOfStudy( fos );

    schoolLabel->setText( s );
    dateAttendedLabel->setText( QString::number( d ) + "/" +
                                QString::number( m ) + "/" +
                                QString::number( y ) );
    fieldOfStudyLabel->setText( fos );
}

// SLOT TitleWidget::removeTitle
void TitleWidget::removeTitle() {
    emit removeTitleSignal( title );
}
