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

// CLASSE Iteratore_rapp
class Rete::Iteratore::Iteratore_rapp {
public:
    QListIterator<SmartUtente> it;

    /** Costruttore ad 1 parametro.
     *  Costruttore di default non disponibile.
     *
     * @param QList<SmartUtente>  Lista di Utenti sulla quale iterare.
     */
    Iteratore_rapp( QList<SmartUtente> list ) : it( list ) {}
};

// METODO hasNext Iteratore
bool Rete::Iteratore::hasNext() const {
    if( iterator )
        return iterator->it.hasNext();
    return false;
}

// METODO next Iteratore
Utente* Rete::Iteratore::next() {
    return iterator->it.next().operator ->();
}

// METODO begin Iteratore
Rete::Iteratore Rete::begin() const {
    Iteratore aux;
    aux.iterator = new Iteratore::Iteratore_rapp( contacts->contactsList );
    return aux;
}

// COSTRUTTORE Rete
Rete::Rete() :
    contacts( new Rete_rapp ),
    user_ref( 1 ) {}

// METODO addContact di Rete
void Rete::addContact( Utente* u, Database* db ) {
    if( !u )
        return;
    if( db->contains( u->getUsername() ) )
        return;
    contacts->contactsList.append( SmartUtente( u ) );
}

// METODO removeContact di Rete
void Rete::removeContact( Utente* u, Database* db ) {
    if( !u )
        return;
    if( !db->contains( u->getUsername() ) )
        return;
    contacts->contactsList.removeOne( SmartUtente( u ) );
}

// METODO getContactsList di Rete
QVector<SmartUtente> Rete::getContactsList() const {
    QVector<SmartUtente> v;
    QListIterator<SmartUtente> it( contacts->contactsList );
    while( it.hasNext() )
        v.push_back( it.next() ); // Costruttore di copia di SmartUtente
    return v;
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
