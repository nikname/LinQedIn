#include "utente_executive.h"

// COSTRUTTORE DI COPIA di UtenteExecutive
UtenteExecutive::UtenteExecutive( const Utente& u ) : UtentePagante( u ) {}

// METODO UtenteExecutive::getAccountType
QString UtenteExecutive::getAccountType() const {
    return "Executive";
}

// METODO UtenteExecutive::searchUsers
QVector<SmartUtente> UtenteExecutive::searchUsers( QVector<SmartUtente> v ) const {
    QVector<SmartUtente> aux;
    for( int i = 0; i < v.size(); i++ ) {
        FuntoreRicerca functor( 1 );
        aux.append( functor( v[i] ) );
    }
    return aux;
}
