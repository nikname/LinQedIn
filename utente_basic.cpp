#include "utente_basic.h"

// COSTRUTTORE DI COPIA di UtenteBasic
UtenteBasic::UtenteBasic( const Utente& u ) : UtenteGratis( u ) {}

// METODO UtenteBasic::getAccountType
QString UtenteBasic::getAccountType() const {
    return "Basic";
}

// METODO UtenteBasic::searchUsers
QVector<SmartUtente> UtenteBasic::searchUsers( QVector<SmartUtente> v ) const {
    QVector<SmartUtente> aux;
    for( int i = 0; i < v.size(); i++ ) {
        if( v[i]->getUsername() != getUsername() ) {
            FuntoreRicerca functor( 1 );
            aux.append( functor( v[i] ) );
        }
    }
    return aux;
}
