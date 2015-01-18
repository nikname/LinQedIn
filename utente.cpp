#include "utente.h"

// Deve essere definito anche se classe astratta.
Utente::~Utente() {}

Username Utente::getUsername() {
    return username;
}

Profilo Utente::getProfile() {
    return profile;
}

Rete* Utente::getNet() {
    return net;
}

Formazione* Utente::getEducations() {
    return educations;
}

Esperienza* Utente::getExperiences() {
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
