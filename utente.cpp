#include "utente.h"

// COSTRUTTORE DI COPIA di Utente
Utente::Utente( const Utente& u ) :
    username( u.username ),
    profile( u.profile ),
    net( u.net ), // memoria condivisa!
    educations( u.educations ), // memoria condivisa!
    experiences( u.experiences ) // memoria condivisa!
{
    net->references++;
    //educations->references++;
    //experiences->references++;
}

// DISTRUTTORE Utente
Utente::~Utente() {
    net->references--;
    if( !net->references )
        delete net;
    //educations->references--;
    //if( !educations->references )
        delete educations;
    //experiences->references--;
    //if( !experiences->references )
        delete experiences;
}

// METODO getUsername Utente
QString Utente::getUsername() {
    return username;
}

// METODO setLogin Utente
void Utente::setUsername( const QString& l ) {
    //TODO: controlla che non sia già utilizzato
    username = l;
}

// METODO getProfile Utente
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
