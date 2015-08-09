#include <QVBoxLayout>
#include <QLabel>
#include "titlewidget.h"
#include "titolo.h"

// COSTRUTTORE TitleWidget
TitleWidget::TitleWidget( const SmartTitolo& st, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout( this );

    schoolLabel = new QLabel( st->getSchool() );
    schoolLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.87 ); font: bold; }" );
    fieldOfStudyLabel = new QLabel( st->getFieldOfStudy() );
    fieldOfStudyLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.87 ); }" );
    dateAttendedLabel = new QLabel( st->getDateAttended().toString( "yyyy/MM/dd" ) );
    dateAttendedLabel->setStyleSheet( "QLabel { color: rgba( 0, 0, 0, 0.54 ); }" );
    degreeLabel = new QLabel( st->getDegree() );
    gradeLabel = new QLabel( st->getGrade() );

    QWidget *moreInfoWidget = new QWidget( this );

    QHBoxLayout *moreInfoLayout = new QHBoxLayout( moreInfoWidget );
    moreInfoLayout->setMargin( 0 );

    QWidget *moreInfoFiller = new QWidget( moreInfoWidget );
    moreInfoFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

    moreInfoLayout->addWidget( fieldOfStudyLabel );
    moreInfoLayout->addSpacing( 30 );
    moreInfoLayout->addWidget( dateAttendedLabel );
    moreInfoLayout->addWidget( moreInfoFiller );

    layout->addWidget( schoolLabel );
    layout->addWidget( moreInfoWidget );

    setLayout( layout );
}
