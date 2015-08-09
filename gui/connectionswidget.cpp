#include <QLabel>
#include <QVBoxLayout>
#include "connectionswidget.h"
#include "database.h"
#include "utente.h"

// COSTRUTTORE ConnectionsWidget
ConnectionsWidget::ConnectionsWidget( const SmartUtente& su, Database *db, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout( this );

    QVector<QString> aux = su->getContactsList();
    for( int i = 0; i < aux.size(); i++ ) {
        if( db->contains( aux[i] ) ) {
            SmartUtente su = db->find( aux[i] );
            layout->addWidget( new QLabel( su->getName() + " " + su->getSurname() ) );
        }
    }

    setLayout( layout );
}
