#include "utente.h"

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

Formazione Utente::getEducations() const {
    return educations;
}

Esperienza Utente::getExperiences() const {
    return experiences;
}

QDebug operator <<( QDebug qdbg, const Utente& u ) {
    qdbg << "*** PROFILO UTENTE ***\n\n"
         << u.getUsername() << "\n"
         << u.getProfile() << "\n"
         << u.getNet() << "\n"
         << u.getEducations() << "\n"
         << u.getExperiences() << "\n";
    return qdbg;
}
