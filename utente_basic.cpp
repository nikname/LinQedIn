#include "utente_basic.h"
#include "database.h"

// COSTRUTTORE DI COPIA di UtenteBasic
UtenteBasic::UtenteBasic( const Utente& u ) : UtenteGratis( u ) {}

// METODO userSearch UtenteBasic
void UtenteBasic::userSearch( const Database& d ) const {
    // ...
}

// METODO UtenteBasic::getAccountType
QString UtenteBasic::getAccountType() const {
    return "Basic";
}
