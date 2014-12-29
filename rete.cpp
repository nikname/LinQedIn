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

Rete::Rete() : first( 0 ) {}

ostream& operator <<( ostream& os, Rete r ) {
    string out = "";
    // ...
    return os << "CONTATTI: " << out;
}
