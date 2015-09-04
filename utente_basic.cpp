#include "utente_basic.h"
#include "profilo.h"
#include "rete.h"
#include "formazione.h"
#include "esperienza.h"

// COSTRUTTORE DI COPIA di UtenteBasic
UtenteBasic::UtenteBasic( const Utente& u ) : UtenteGratis( u ) {}

// METODO UtenteBasic::clone
Utente *UtenteBasic::clone() const {
    return new UtenteBasic( username, profile, net->clone(), 0, experiences->clone() );
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
            aux.append( functor( v[i] ) );
        }
    }
    return aux;
}
