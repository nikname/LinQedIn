#include "utente.h"

// DISTRUTTORE Utente
Utente::~Utente() {
    qDebug() << "** DISTRUTTORE Utente **";
    delete net;
    delete educations;
    delete experiences;
}

// METODO getUsername Utente
Username Utente::getUsername() {
    return username;
}

// METOD getProfile Utente
Profilo Utente::getProfile() {
    return profile;
}

// METODO getNet Utente
Rete* Utente::getNet() {
    return net;
}

// METODO getEducations Utente
Formazione* Utente::getEducations() {
    return educations;
}

// METODO getExperiences Utente
Esperienza* Utente::getExperiences() {
    return experiences;
}

// Overloading OPERATOR () Utente
void Utente::FuntoreRicerca::operator ()( const SmartUtente& x ) const {
    // ...
    qDebug() << x.getUser()->getProfile();
}

// Overloading OPERATOR << QDebug
QDebug operator <<( QDebug qdbg, Utente* u ) {
    qdbg << "*** PROFILO UTENTE ***\n\n"
         << u->getUsername() << "\n"
         << u->getProfile() << "\n"
         << *( u->getNet() ) << "\n"
         << *( u->getEducations() ) << "\n"
         << *( u->getExperiences() ) << "\n";
    return qdbg;
}
