#include <QVBoxLayout>
#include "profilewidget.h"

// COSTRUTTORE ProfileWidget
ProfileWidget::ProfileWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout( this );

    setLayout( layout );
}
