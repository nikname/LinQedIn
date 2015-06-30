#include "tabrete.h"
#include "utente.h"
#include <QVBoxLayout>

// COSTRUTTORE TabRete
TabRete::TabRete( SmartUtente su, Database *db, QWidget *parent ) :
    QWidget( parent )
{
    QVBoxLayout *tabLayout = new QVBoxLayout( this );

    QVector<SmartUtente> contacts;
    QVector<QString> aux = su->getContactsList();
    for( int i = 0; i < aux.size(); i++ ) {
        if( db->contains( aux[i] ) ) {
            SmartUtente su = db->find( aux[i] );
            contacts.append( su );
        } // else su->removeContact( v[i] );
    }

    contactList = new UserListWidget( contacts, this );
    contactList->hideColumn( 3 );
    contactList->hideColumn( 4 );
    contactList->hideColumn( 5 );

    connect( contactList, SIGNAL( updateContactsSignal( const QString& ) ),
             this, SIGNAL( updateContactsSignal( const QString& ) ) );

    tabLayout->addWidget( contactList );

    setLayout( tabLayout );
}
