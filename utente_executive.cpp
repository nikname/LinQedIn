#include "utente_executive.h"

// COSTRUTTORE DI COPIA di UtenteExecutive
UtenteExecutive::UtenteExecutive( const Utente& u ) : UtentePagante( u ) {}

// METODO UtenteExecutive::getUserInfo
SmartUtente UtenteExecutive::getUserInfo( const SmartUtente& su ) const {
    SmartUtente aux( su );
    aux->unsetContactsList();

    return aux;
}

// METODO UtenteExecutive::getAccountType
QString UtenteExecutive::getAccountType() const {
    return "Executive";
}
