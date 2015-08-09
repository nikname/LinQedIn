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
    dateAttendedLabel = new QLabel( st->getDateAttended().toString( "yyyy/MM/dd" ) );
    degreeLabel = new QLabel( st->getDegree() );
    fieldOfStudyLabel = new QLabel( st->getFieldOfStudy() );
    gradeLabel = new QLabel( st->getGrade() );

    layout->addWidget( schoolLabel );
    layout->addWidget( dateAttendedLabel );
    layout->addWidget( degreeLabel );
    layout->addWidget( fieldOfStudyLabel );
    layout->addWidget( gradeLabel );

    setLayout( layout );
}
