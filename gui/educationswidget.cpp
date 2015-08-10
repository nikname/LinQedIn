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

    educationsList = su->getEducationsList();
    for( int i = 0; i < educationsList.size(); i++ ) {
        TitleWidget *aux = new TitleWidget( educationsList[i], this );
        titlesList.append( aux );
        wrapperLayout->addWidget( aux );
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
    layout->setMargin( 0 );

    setLayout( layout );
}
