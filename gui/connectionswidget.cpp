#include <QLabel>
#include <QVBoxLayout>
#include "connectionswidget.h"
#include "database.h"
#include "utente.h"

// COSTRUTTORE ConnectionsWidget
ConnectionsWidget::ConnectionsWidget( const SmartUtente& su, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout( this );

    QVector<SmartUtente> aux = su->getContactsList();
    for( int i = 0; i < aux.size(); i++ ) {
        layout->addWidget( new QLabel( aux[i]->getName() + " " + aux[i]->getSurname() ) );
    }

    setLayout( layout );
}
