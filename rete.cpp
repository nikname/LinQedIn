#include "rete.h"

using std::ostream;
using std::string;

class Rete::SmartUtente {
public:
    Username username;
    SmartUtente* next;

    /** Costruttore a 2 parametri.
     *  Costruttore di default non disponibile.
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
    first = new SmartUtente( u, first );
    std::cout << first->username.getLogin() << std::endl;
}

void Rete::remove( Username u ) {
    for( Rete::Iteratore it = begin(); it != end(); ++it ) {
        if( (*this)[it].getLogin() == u.getLogin() ) {
           //delete it;
        }
    }
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

Username& Rete::operator []( Rete::Iteratore it ) const {
    return ( ( it.punt )->username );
}

ostream& operator <<( ostream& os, Rete r ) {
    string out;
    for( Rete::Iteratore it = r.begin(); it != r.end(); ++it ) {
        if( ( it.punt )->next ) {
            out += r[it].getLogin();
            out += ", ";
        } else out += r[it].getLogin();
    }
    return os << "CONTATTI: " << out;
}
