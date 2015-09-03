#include "utente_basic.h"

// COSTRUTTORE DI COPIA di UtenteBasic
UtenteBasic::UtenteBasic( const Utente& u ) : UtenteGratis( u ) {}

// METODO UtenteBasic::getUserInfo
SmartUtente UtenteBasic::getUserInfo( const SmartUtente& su ) const {
    SmartUtente aux( su );
    aux->unsetContactsList();
    aux->unsetEducationsList();
    aux->unsetExperiencesList();

    return aux;
}

// METODO UtenteBasic::getAccountType
QString UtenteBasic::getAccountType() const {
    return "Basic";
}
