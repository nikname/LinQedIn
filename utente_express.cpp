#include "utente_express.h"

// COSTRUTTORE DI COPIA di UtenteExpress
UtenteExpress::UtenteExpress( const Utente& u ) : UtentePagante( u ) {}

// METODO userSearch UtenteExpress
void UtenteExpress::userSearch( const Database& d ) const {
    // ...
}

// METODO UtenteExpress::getAccountType
QString UtenteExpress::getAccountType() const {
    return "Express";
}
