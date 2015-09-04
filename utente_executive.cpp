#include "utente_executive.h"
#include "rete.h"

// COSTRUTTORE DI COPIA di UtenteExecutive
UtenteExecutive::UtenteExecutive( const Utente& u ) : UtentePagante( u ) {}

// METODO UtenteExecutive::clone
Utente *UtenteExecutive::clone() const {
    return new UtenteExecutive( username, profile, net->clone(),
                                educations->clone(), experiences->clone() );
}

// METODO UtenteExecutive::getAccountType
QString UtenteExecutive::getAccountType() const {
    return "Executive";
}

// METODO UtenteExecutive::searchUsers
QVector<SmartUtente> UtenteExecutive::searchUsers( QVector<SmartUtente> v ) const {
    QVector<SmartUtente> aux;
    for( int i = 0; i < v.size(); i++ ) {
        if( v[i]->getUsername() != getUsername() ) {
            FuntoreRicerca functor( 2 );
            aux.append( functor( v[i] ) );
        }
    }
    return aux;
}
