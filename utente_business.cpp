#include "utente_business.h"

// COSTRUTTORE DI COPIA di UtenteBusiness
UtenteBusiness::UtenteBusiness( const Utente& u ) : UtentePagante( u ) {}

// METODO UtenteBusiness::getUserInfo
SmartUtente UtenteBusiness::getUserInfo( const SmartUtente& su ) const {
    SmartUtente aux( su );

    return aux;
}

// METODO UtenteBusiness::getAccountType
QString UtenteBusiness::getAccountType() const {
    return "Business";
}
