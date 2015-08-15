#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
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

    addJobButton = new QPushButton( this );
}

// METODO ExperiencesWidget::setupUI
void ExperiencesWidget::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout( this );
    for( int i = jobWidgetsList.size() - 1; i >= 0; i-- ) {
        connect( jobWidgetsList[i], SIGNAL( updateExperiencesSignal() ),
                 this, SIGNAL( updateExperiencesSignal() ) );
        layout->addWidget( jobWidgetsList[i] );

        QFrame *line = new QFrame( this );
        line->setFrameShape( QFrame::HLine );
        line->setStyleSheet( "color: rgba(0,0,0,0.12)" );
        layout->addWidget( line );
    }

    addJobButton->setIcon( QIcon( QPixmap( ":/icons/icon/plus.png" ) ) );
    addJobButton->setFixedSize( 50, 50 );
    addJobButton->setStyleSheet(
        "QPushButton { background: #003D5C; border-radius: 25px; outline: none; }"
        "QPushButton:pressed { background: #3385AD; outline: none; }"
    );

    layout->addWidget( addJobButton, 0, Qt::AlignRight );

    setStyleSheet( "background: white" );
}

// METODO ExperiencesWidget::paintEvent
void ExperiencesWidget::paintEvent( QPaintEvent *) {
    QStyleOption opt;
    opt.init( this );
    QPainter p( this );
    style()->drawPrimitive( QStyle::PE_Widget, &opt, &p, this );
}
