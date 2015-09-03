#include "rete.h"
#include <QList>
#include <QListIterator>
#include "smartutente.h"
#include "utente.h"
#include "database.h"

// CLASSE Rete_rapp
class Rete::Rete_rapp {
public:
    QList<SmartUtente> contactsList;

    /** Costruttore di default.
     *  Inizializza il campo contactsList con una QList di SmartUtente vuota.
     */
    Rete_rapp() :
        contactsList( QList<SmartUtente>() ) {}

    /** Distruttore Rete_rapp.
     *  Invoca il metodo clear() sulla lista dei contatti dell'utente.
     *
     * @param void* p  Puntatore all'oggetto Rete_rapp.
     */
    void operator delete( void* p ) {
        if( p ) {
            Rete_rapp* p_aux = static_cast<Rete_rapp*>( p );
            if( !p_aux->contactsList.isEmpty() )
                p_aux->contactsList.clear();
        }
    }
};

// COSTRUTTORE Rete
Rete::Rete() :
    contacts( new Rete_rapp ),
    user_ref( 1 ) {}

// METODO addContact di Rete
void Rete::addContact( const SmartUtente& su ) {
    if( !isContact( su ) )
        contacts->contactsList.append( su );
}

// METODO removeContact di Rete
void Rete::removeContact( const SmartUtente& su ) {
    if( isContact( su ) )
        contacts->contactsList.removeOne( su );
}

// METODO Rete::isContact
bool Rete::isContact( const SmartUtente& c ) {
    return contacts->contactsList.contains( c );
}

// METODO getContactsList di Rete
QVector<SmartUtente> Rete::getContactsList() const {
    QVector<SmartUtente> v;
    QListIterator<SmartUtente> it( contacts->contactsList );
    while( it.hasNext() )
        v.push_back( it.next() );
    return v;
}

// METODO Rete::setContactsList
void Rete::setContactsList( QVector<SmartUtente> v ) {
    if( contacts->contactsList.size() ) {
        delete contacts;
        contacts = 0;
    }
    contacts = new Rete_rapp();
    for( int i = 0; i < v.size(); i++ )
        addContact( v[i] );
}

// OPERATOR delete di Rete
void Rete::operator delete( void* p ) {
    if( p ) {
        Rete* p_aux = static_cast<Rete*>( p );
        p_aux->user_ref--;
        if( p_aux->user_ref == 0 )
            delete p_aux->contacts;
    }
}
