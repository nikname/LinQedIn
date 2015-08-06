#include <QVBoxLayout>
#include <QLabel>
#include "profilewidget.h"
#include "utente.h"
#include <QDebug>

// COSTRUTTORE ProfileWidget
ProfileWidget::ProfileWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout( this );

    setStyleSheet( "background: white; color: black;" );
    setLayout( layout );
}
