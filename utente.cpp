#include "utente.h"

using std::ostream;

Utente::Utente( Username u, Profilo p, Rete* r ) :
    username( u ), profile( p ), net( r ) {}

Utente::~Utente() {
    //delete net;
}

Username Utente::getUsername() const {
    return username;
}

Profilo Utente::getProfile() const {
    return profile;
}

Rete* Utente::getNet() const {
    return net;
}

void Utente::addContact( Username u ) {
    //TODO: controlla la presenza dell'utente nel database
    net->add( u );
}

void Utente::removeContact( Username u ) {
    net->remove( u );
}

ostream& operator<< ( ostream& os, Utente u ) {
    return os << "*** PROFILO UTENTE ***\n\n"
              << u.getUsername() << "\n"
              << u.getProfile() << "\n"
              << u.getNet();
}
