#include <QVBoxLayout>
#include <QLabel>
#include "educationswidget.h"
#include "utente.h"
#include "titlewidget.h"

// COSTRUTTORE EducationsWidget
EducationsWidget::EducationsWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout( this );

    widgetsWrapper = new QWidget( this );
    widgetsWrapper->setStyleSheet( "background: white" );

    QVBoxLayout *wrapperLayout = new QVBoxLayout( widgetsWrapper );

    educationsLabel = new QLabel( tr( "Educations" ), this );
    educationsLabel->setStyleSheet( "color: rgba( 0, 0, 0, 0.54 )" );

    wrapperLayout->addWidget( educationsLabel );

    educationsList = su->getEducationsList();
    for( int i = 0; i < educationsList.size(); i++ ) {
        wrapperLayout->addWidget( new TitleWidget( educationsList[i], this ) );
        if( i < educationsList.size() - 1 ) {
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
