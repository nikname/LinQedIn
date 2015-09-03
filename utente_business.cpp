#include "utente_business.h"

// COSTRUTTORE DI COPIA di UtenteBusiness
UtenteBusiness::UtenteBusiness( const Utente& u ) : UtentePagante( u ) {}

// METODO UtenteBusiness::getAccountType
QString UtenteBusiness::getAccountType() const {
    return "Business";
}

// METODO UtenteBusiness::searchUsers
QVector<SmartUtente> UtenteBusiness::searchUsers( QVector<SmartUtente> v ) const {
    QVector<SmartUtente> aux;
    for( int i = 0; i < v.size(); i++ ) {
        FuntoreRicerca functor( 3 );
        aux.append( functor( v[i] ) );
    }
    return aux;
}
