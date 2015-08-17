#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QStyleOption>
#include <QVBoxLayout>
#include "educationswidget.h"
#include "titlewidget.h"
#include "utente.h"

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

    addTitleButton = new QPushButton( this );
}

// METODO EducationsWidget::setupUI
void EducationsWidget::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout( this );
    for( int i = titleWidgetsList.size() - 1; i >= 0; i-- ) {
        connect( titleWidgetsList[i], SIGNAL( updateEducationsSignal() ),
                 this, SIGNAL( updateEducationsSignal() ) );
        layout->addWidget( titleWidgetsList[i] );

        QFrame *line = new QFrame( this );
        line->setFrameShape( QFrame::HLine );
        line->setStyleSheet( "color: rgba(0,0,0,0.12)" );
        layout->addWidget( line );
    }

    addTitleButton->setIcon( QIcon( QPixmap( ":/icons/icon/plus-black.png" ) ) );
    addTitleButton->setFixedSize( 25, 25 );
    addTitleButton->setStyleSheet(
        "QPushButton { border-radius: 12px; outline: none; }"
        "QPushButton:pressed { background: rgba(0,0,0,0.12); }"
    );

    layout->addWidget( addTitleButton, 0, Qt::AlignCenter );

    setStyleSheet( "background: white" );
}

// METODO EducationsWidget::paintEvent
void EducationsWidget::paintEvent( QPaintEvent *) {
    QStyleOption opt;
    opt.init( this );
    QPainter p( this );
    style()->drawPrimitive( QStyle::PE_Widget, &opt, &p, this );
}
