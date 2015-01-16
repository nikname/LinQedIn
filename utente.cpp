#include "utente.h"

// Deve essere definito anche se classe astratta.
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

void Utente::FuntoreRicerca::operator ()( const SmartUtente& x ) const {
    // Da definire.
    qDebug() << x.getUser()->getProfile();
}

// Nessuna definizione del metodo virtuale puro userSearch( const Database& )

QDebug operator <<( QDebug qdbg, Utente* u ) {
    qdbg << "*** PROFILO UTENTE ***\n\n"
         << u->getUsername() << "\n"
         << u->getProfile() << "\n"
         << u->getNet() << "\n"
         << u->getEducations() << "\n"
         << u->getExperiences() << "\n";
    return qdbg;
}
