#include "utente_basic.h"

// COSTRUTTORE DI COPIA di UtenteBasic
UtenteBasic::UtenteBasic( const Utente& u ) : UtenteGratis( u ) {}

// METODO UtenteBasic::clone
Utente *UtenteBasic::clone() const {
    Utente *aux = new UtenteBasic( getUsername(), getName(), getSurname() );
    return aux;
}

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
            aux.append( functor( SmartUtente( v[i]->clone() ) ) );
        }
    }
    return aux;
}
