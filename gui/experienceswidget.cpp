#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
#include <QVBoxLayout>
#include "addjobdialog.h"
#include "experienceswidget.h"
#include "jobwidget.h"
#include "utente.h"

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
}

// METODO ExperiencesWidget::setupUI
void ExperiencesWidget::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout( this );
    for( int i = jobWidgetsList.size() - 1; i >= 0; i-- ) {
        layout->addWidget( jobWidgetsList[i] );

        QFrame *line = new QFrame( this );
        line->setFrameShape( QFrame::HLine );
        line->setStyleSheet( "color: rgba(0,0,0,0.12)" );
        layout->addWidget( line );
    }

    addJobButton->setIcon( QIcon( QPixmap( ":/icons/icon/plus-black.png" ) ) );
    addJobButton->setFixedSize( 24, 24 );
    addJobButton->setStyleSheet(
        "QPushButton { border-radius: 12px; outline: none; }"
        "QPushButton:pressed { background: rgba(0,0,0,0.12); }"
    );
    connect( addJobButton, SIGNAL( clicked() ), this, SLOT( openAddJobDialog() ) );

    layout->addWidget( addJobButton, 0, Qt::AlignCenter );

    setStyleSheet( "background: white" );
}

// METODO ExperiencesWidget::paintEvent
void ExperiencesWidget::paintEvent( QPaintEvent *) {
    QStyleOption opt;
    opt.init( this );
    QPainter p( this );
    style()->drawPrimitive( QStyle::PE_Widget, &opt, &p, this );
}

// SLOT ExperiencesWidget::openAddJobDialog
void ExperiencesWidget::openAddJobDialog() {
    AddJobDialog *addJobDialog = new AddJobDialog( this );
    connect( addJobDialog, SIGNAL( addNewJobSignal( QString, QString, int, int ) ),
             this, SIGNAL( addNewJobSignal( QString, QString, int, int ) ) );

    addJobDialog->exec();
}
