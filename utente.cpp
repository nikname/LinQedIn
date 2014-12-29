#include "utente.h"

using std::ostream;

Utente::Utente( const Username& u,
                const Profilo& p ) :
    username( u ),
    profile( p ) {}

Utente::~Utente() {}

Username Utente::getUsername() const {
    return username;
}

Profilo Utente::getProfile() const {
    return profile;
}

Rete Utente::getNet() const {
    return net;
}

Formazione Utente::getEucations() const {
    return educations;
}

Esperienza Utente::getExperiences() const {
    return experiences;
}

ostream& operator<< ( ostream& os, Utente u ) {
    return os << "*** PROFILO UTENTE ***\n\n"
              << u.getUsername() << "\n"
              << u.getProfile() << "\n"
              << u.getNet() << "\n"
              << u.getEucations() << "\n"
              << u.getExperiences();
}
