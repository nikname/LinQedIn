#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
#include <QVBoxLayout>
#include "addtitledialog.h"
#include "educationswidget.h"
#include "titlewidget.h"
#include "utente.h"
#include "titolo.h"

// COSTRUTTORE EducationsWidget
EducationsWidget::EducationsWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent ),
    titlesList( su->getEducationsList() )
{
    initUI();
    setupUI();
}

// METODO EducationsWidget::initUI
void EducationsWidget::initUI() {
    for( int i = 0; i < titlesList.size(); i++ )
        titleWidgetsList.append( new TitleWidget( titlesList[i], this ) );

    addTitleButton = new QPushButton( this );
    connect( addTitleButton, SIGNAL( clicked() ), this, SLOT( openAddTitleDialog() ) );
}

// METODO EducationsWidget::setupUI
void EducationsWidget::setupUI() {
    titleWidgetsLayout = new QVBoxLayout( this );
    titleWidgetsLayout->setSpacing( 0 ); /* *** */
    for( int i = titleWidgetsList.size() - 1; i >= 0; i-- )
        addTitleWidget( titleWidgetsList[i] );

    addTitleButton->setIcon( QIcon( QPixmap( ":/icons/icon/plus-black.png" ) ) );
    addTitleButton->setFixedSize( 24, 24 );
    addTitleButton->setStyleSheet(
        "QPushButton { border-radius: 12px; outline: none; }"
        "QPushButton:pressed { background: rgba(0,0,0,0.12); }"
    );

    dynamic_cast<QVBoxLayout *>( titleWidgetsLayout )->addSpacing( 10 );
    dynamic_cast<QVBoxLayout *>( titleWidgetsLayout )->addWidget( addTitleButton, 0, Qt::AlignCenter );

    setStyleSheet( "background: white" );
}

// METODO EducationsWidget::paintEvent
void EducationsWidget::paintEvent( QPaintEvent *) {
    QStyleOption opt;
    opt.init( this );
    QPainter p( this );
    style()->drawPrimitive( QStyle::PE_Widget, &opt, &p, this );
}

// METODO EducationsWidget::addTitleWidget
void EducationsWidget::addTitleWidget( TitleWidget *widget ) {
    titleWidgetsLayout->addWidget( widget );
    connect( widget, SIGNAL( removeTitleSignal( SmartTitolo ) ),
             this, SLOT( removeTitleSlot( SmartTitolo ) ) );
    connect( widget, SIGNAL( updateTitleInfoSignal( SmartTitolo ) ),
             this, SLOT( updateTitleInfoSlot( SmartTitolo ) ) );
}

// METODO EducationsWidget::insertTitleWidget
void EducationsWidget::insertTitleWidget( int pos, TitleWidget *widget ) {
    dynamic_cast<QVBoxLayout *>( titleWidgetsLayout )->insertWidget( pos, widget );
    connect( widget, SIGNAL( removeTitleSignal( SmartTitolo ) ),
             this, SLOT( removeTitleSlot( SmartTitolo ) ) );
    connect( widget, SIGNAL( updateTitleInfoSignal( SmartTitolo ) ),
             this, SLOT( updateTitleInfoSlot( SmartTitolo ) ) );
}

// SLOT EducationsWidget::openAddTitleDialog
void EducationsWidget::openAddTitleDialog() {
    AddTitleDialog *addTitleDialog = new AddTitleDialog( this );
    connect( addTitleDialog, SIGNAL( addNewTitleSignal( QString, int, int, int, QString ) ),
             this, SLOT( addNewTitleSlot( QString, int, int, int, QString ) ) );

    addTitleDialog->exec();
}

// SLOT EducationsWidget::addNewTitleSlot
void EducationsWidget::addNewTitleSlot( const QString& s, int d, int m, int y, const QString& fos ) {
    SmartTitolo aux = SmartTitolo( new Titolo( s, QDate( y, m, d ), "", fos, "" ) );

    titlesList.append( aux );
    titleWidgetsList.append( new TitleWidget( aux, this ) );
    insertTitleWidget( 0, titleWidgetsList.last() );

    emit titleToAddSignal( aux );
}

// SLOT EducationsWidget::removeTitleSlot
void EducationsWidget::removeTitleSlot( const SmartTitolo& st ) {
    int pos = titlesList.indexOf( st );
    if( pos > -1 )
        titlesList.remove( pos );

    for( int i = 0; i < titleWidgetsList.size(); i++ ) {
        if( titleWidgetsList[i]->getTitle() == st ) {
            QVBoxLayout *layout = dynamic_cast<QVBoxLayout *>( titleWidgetsLayout );
            layout->removeWidget( titleWidgetsList[i] );

            TitleWidget *aux = titleWidgetsList.takeAt( i );
            delete aux;
        }
    }

    emit titleToRemoveSignal( st );
}

// SLOT EducationsWidget::updateTitleInfoSlot
void EducationsWidget::updateTitleInfoSlot( const SmartTitolo& st ) {
    if( titlesList.last() == st )
        emit updateLastTitleInfoSignal( st );
}
