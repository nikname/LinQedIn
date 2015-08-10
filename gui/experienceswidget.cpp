#include <QLabel>
#include <QVBoxLayout>
#include "experienceswidget.h"
#include "jobwidget.h"
#include "utente.h"

// COSTRUTTORE ExperiencesWidget
ExperiencesWidget::ExperiencesWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent )
{
    jobsList = su->getExperiencesList();

    initUI();
    setupUI();
}

// METODO ExperiencesWidget::initUI
void ExperiencesWidget::initUI() {
    for( int i = 0; i < jobsList.size(); i++ )
        jobWidgetsList.append( new JobWidget( jobsList[i], this ) );
}

// METODO ExperiencesWidget::setupUI
void ExperiencesWidget::setupUI() {
    QWidget *wrapper = new QWidget( this );
    wrapper->setStyleSheet( "background: white" );

    QVBoxLayout *wrapperLayout = new QVBoxLayout( wrapper );
    for( int i = jobWidgetsList.size() - 1; i >= 0; i-- ) {
        wrapperLayout->addWidget( jobWidgetsList[i] );
        if( i > 0 ) {
            QFrame *line = new QFrame( this );
            line->setFrameShape( QFrame::HLine );
            line->setStyleSheet( "color: rgba( 0, 0, 0, 0.12 )" );
            wrapperLayout->addWidget( line );
        }
    }

    QWidget *bottomFiller = new QWidget( this );
    bottomFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    QVBoxLayout *layout = new QVBoxLayout( this );
    layout->addWidget( wrapper );
    layout->addWidget( bottomFiller );
    layout->setMargin( 0 );
}
