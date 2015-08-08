#include <QVBoxLayout>
#include <QLabel>
#include "experienceswidget.h"
#include "utente.h"
#include "jobwidget.h"

// COSTRUTTORE ExperiencesWidget
ExperiencesWidget::ExperiencesWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout( this );

    widgetsWrapper = new QWidget( this );
    widgetsWrapper->setStyleSheet( "background: white" );

    QVBoxLayout *wrapperLayout = new QVBoxLayout( widgetsWrapper );

    experiencesLabel = new QLabel( tr( "Experiences" ), this );
    experiencesLabel->setStyleSheet( "color: rgba( 0, 0, 0, 0.54 )" );

    wrapperLayout->addWidget( experiencesLabel );

    experiencesList = su->getExperiencesList();
    for( int i = 0; i < experiencesList.size(); i++ ) {
        wrapperLayout->addWidget( new JobWidget( experiencesList[i], this ) );
        if( i < experiencesList.size() - 1 ) {
            QFrame *line = new QFrame( this );
            line->setFrameShape( QFrame::HLine );
            line->setStyleSheet( "color: rgba( 0, 0, 0, 0.12 )" );
            wrapperLayout->addWidget( line );
        }
    }

    QWidget *bottomFiller = new QWidget( this );
    bottomFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    wrapperLayout->addWidget( bottomFiller );

    layout->addWidget( widgetsWrapper );

    setLayout( layout );
}
