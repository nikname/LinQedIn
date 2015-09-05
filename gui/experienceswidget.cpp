#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
#include <QVBoxLayout>
#include "addjobdialog.h"
#include "experienceswidget.h"
#include "jobwidget.h"
#include "utente.h"
#include "lavoro.h"

// COSTRUTTORE ExperiencesWidget
ExperiencesWidget::ExperiencesWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent ),
    jobsList( su->getExperiencesList() )
{
    initUI();
    setupUI();
}

// METODO ExperiencesWidget::initUI
void ExperiencesWidget::initUI() {
    for( int i = 0; i < jobsList.size(); i++ )
        jobWidgetsList.append( new JobWidget( jobsList[i], this ) );

    addJobButton = new QPushButton( this );
    connect( addJobButton, SIGNAL( clicked() ), this, SLOT( openAddJobDialog() ) );
}

// METODO ExperiencesWidget::setupUI
void ExperiencesWidget::setupUI() {
    jobWidgetsLayout = new QVBoxLayout( this );
    jobWidgetsLayout->setSpacing( 0 );
    jobWidgetsLayout->setMargin( 0 );
    for( int i = jobWidgetsList.size() - 1; i >= 0; i-- )
        addJobWidget( jobWidgetsList[i] );

    addJobButton->setIcon( QIcon( QPixmap( ":/icons/icon/plus-black.png" ) ) );
    addJobButton->setFixedSize( 24, 24 );
    addJobButton->setStyleSheet(
        "QPushButton { border-radius: 12px; outline: none; }"
        "QPushButton:pressed { background: rgba(0,0,0,0.12); }"
    );

    dynamic_cast<QVBoxLayout *>( jobWidgetsLayout )->addWidget( addJobButton, 0, Qt::AlignCenter );

    setStyleSheet( "background: white" );
}

// METODO ExperiencesWidget::paintEvent
void ExperiencesWidget::paintEvent( QPaintEvent *) {
    QStyleOption opt;
    opt.init( this );
    QPainter p( this );
    style()->drawPrimitive( QStyle::PE_Widget, &opt, &p, this );
}

// METODO ExperiencesWidget::addJobWidget
void ExperiencesWidget::addJobWidget( JobWidget *widget ) {
    jobWidgetsLayout->addWidget( widget );
    connect( widget, SIGNAL( removeJobSignal( SmartLavoro ) ),
             this, SLOT( removeJobSlot( SmartLavoro ) ) );
    connect( widget, SIGNAL( updateJobInfoSignal( SmartLavoro ) ),
             this, SLOT( updateJobInfoSlot( SmartLavoro ) ) );
}

// METODO ExperiencesWidget::insertJobWidget
void ExperiencesWidget::insertJobWidget( int pos, JobWidget *widget ) {
    dynamic_cast<QVBoxLayout *>( jobWidgetsLayout )->insertWidget( pos, widget );
    connect( widget, SIGNAL( removeJobSignal( SmartLavoro ) ),
             this, SLOT( removeJobSlot( SmartLavoro ) ) );
    connect( widget, SIGNAL( updateJobInfoSignal( SmartLavoro ) ),
             this, SLOT( updateJobInfoSlot( SmartLavoro ) ) );
}

// SLOT ExperiencesWidget::hideToolsButtons
void ExperiencesWidget::hideToolsButtons() {
    for( int i = 0; i < jobWidgetsList.size(); i++ )
        jobWidgetsList[i]->hideToolsButtons();
    addJobButton->setVisible( false );
}

// SLOT ExperiencesWidget::openAddJobDialog
void ExperiencesWidget::openAddJobDialog() {
    AddJobDialog *addJobDialog = new AddJobDialog( this );
    connect( addJobDialog, SIGNAL( addNewJobSignal( QString, QString, QDate, QDate ) ),
             this, SLOT( addNewJobSlot( QString, QString, QDate, QDate ) ) );

    addJobDialog->exec();
}

// SLOT ExperiencesWidget::addNewJobSlot
void ExperiencesWidget::addNewJobSlot( const QString& cn, const QString& t,
                                       const QDate& b, const QDate& e ) {
    SmartLavoro aux = SmartLavoro( new Lavoro( cn, t, b, e ) );

    jobsList.append( aux );
    jobWidgetsList.append( new JobWidget( aux, this ) );
    insertJobWidget( 0, jobWidgetsList.last() );

    emit jobToAddSignal( aux );
}

// SLOT ExperiencesWidget::removeJobSlot
void ExperiencesWidget::removeJobSlot( const SmartLavoro& sl ) {
    int pos = jobsList.indexOf( sl );
    if( pos > -1 )
        jobsList.remove( pos );

    for( int i = 0; i < jobWidgetsList.size(); i++ ) {
        if( jobWidgetsList[i]->getJob() == sl ) {
            QVBoxLayout *layout = dynamic_cast<QVBoxLayout *>( jobWidgetsLayout );
            layout->removeWidget( jobWidgetsList[i] );

            JobWidget *aux = jobWidgetsList.takeAt( i );
            delete aux;
        }
    }

    emit jobToRemoveSignal( sl );
}

// SLOT ExperiencesWidget::updateJobInfoSlot
void ExperiencesWidget::updateJobInfoSlot( const SmartLavoro& sl ) {
    if( jobsList.last() == sl )
        emit updateLastJobInfoSignal( sl );
}
