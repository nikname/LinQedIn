#include <QLabel>
#include <QVBoxLayout>
#include "educationswidget.h"
#include "utente.h"
#include "titlewidget.h"

// COSTRUTTORE EducationsWidget
EducationsWidget::EducationsWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent )
{
    titlesList = su->getEducationsList();

    initUI();
    setupUI();
}

// METODO EducationsWidget::initUI
void EducationsWidget::initUI() {
    for( int i = 0; i < titlesList.size(); i++ )
        titleWidgetsList.append( new TitleWidget( titlesList[i], this ) );
}

// METODO EducationsWidget::setupUI
void EducationsWidget::setupUI() {
    QWidget *wrapper = new QWidget( this );
    wrapper->setStyleSheet( "background: white" );

    QVBoxLayout *wrapperLayout = new QVBoxLayout( wrapper );
    for( int i = titleWidgetsList.size() - 1; i >= 0; i-- ) {
        wrapperLayout->addWidget( titleWidgetsList[i] );
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
