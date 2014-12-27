#include "rete.h"

using std::ostream;
using std::string;

class Rete::SmartUtente {
public:
    Username username;
    SmartUtente* next;

    /** Costruttore di default. */
    SmartUtente() : username( "" ), next( 0 ) {}

    /** Costruttore a 2 parametri.
     *
     * @param Username  Username dell'utente da aggiungere alla lista.
     */
    SmartUtente( const Username& un, SmartUtente* n ) : username( un ), next( n ) {}

    void operator delete( void* p ) {
        if( p ) {
            SmartUtente* su = static_cast<SmartUtente*>( p );
            if( su->next ) {

            }
        }
    }
};

bool Rete::Iteratore::operator ==( Iteratore it ) const {
    return punt == it.punt;
}

bool Rete::Iteratore::operator !=( Iteratore it ) const {
    return punt != it.punt;
}

Rete::Iteratore& Rete::Iteratore::operator ++() {
    if( punt )
        punt = punt->next;
    return *this;
}

Rete::Iteratore& Rete::Iteratore::operator ++( int ) {
    Iteratore aux = *this;
    if( punt )
        punt = punt->next;
    return aux;
}

Rete::Rete() : first( 0 ) {}

void Rete::add( Username u ) {
    first = new Rete::SmartUtente( u, first );
}

void Rete::remove( Username u ) {
    for( Rete::Iteratore it = begin(); it != end(); ++it ) {
        //if( this[it] == u.getLogin() ) {
           //delete it;
        //}
    }
}

string Rete::getContactsList() const {
    //TODO: Creare la lista dei contatti separati da ","
    return string();
}

Rete::Iteratore Rete::begin() const {
    Iteratore aux;
    aux.punt = first;
    return aux;
}

Rete::Iteratore Rete::end() const {
    Iteratore aux;
    aux.punt = 0;
    return aux;
}

Username Rete::operator []( Rete::Iteratore it ) const {
    //TODO: if( it.punt )
    return ( it.punt )->username;
}

ostream& operator <<( ostream& os, Rete* r ) {
    return os << "CONTATTI: " << r->getContactsList();
}
