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
    for( int i = jobWidgetsList.size() - 1; i >= 0; i-- )
        addJobWidget( jobWidgetsList[i] );

    addJobButton->setIcon( QIcon( QPixmap( ":/icons/icon/plus-black.png" ) ) );
    addJobButton->setFixedSize( 24, 24 );
    addJobButton->setStyleSheet(
        "QPushButton { border-radius: 12px; outline: none; }"
        "QPushButton:pressed { background: rgba(0,0,0,0.12); }"
    );

    dynamic_cast<QVBoxLayout *>( jobWidgetsLayout )->addSpacing( 10 );
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
}

// METODO ExperiencesWidget::insertJobWidget
void ExperiencesWidget::insertJobWidget( int pos, JobWidget *widget ) {
    dynamic_cast<QVBoxLayout *>( jobWidgetsLayout )->insertWidget( pos, widget );
    connect( widget, SIGNAL( removeJobSignal( SmartLavoro ) ),
             this, SLOT( removeJobSlot( SmartLavoro ) ) );
}

// SLOT ExperiencesWidget::openAddJobDialog
void ExperiencesWidget::openAddJobDialog() {
    AddJobDialog *addJobDialog = new AddJobDialog( this );
    connect( addJobDialog, SIGNAL( addNewJobSignal( QString, QString, int, int ) ),
             this, SLOT( addNewJobSlot( QString, QString, int, int ) ) );

    addJobDialog->exec();
}

// SLOT ExperiencesWidget::addNewJobSlot
void ExperiencesWidget::addNewJobSlot( const QString& cn, const QString& t, int b, int e ) {
    SmartLavoro aux = SmartLavoro( new Lavoro( cn, t, "", QDate( b, 1, 1 ), QDate( e, 1, 1 ) ) );

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
