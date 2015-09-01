#include "utente_basic.h"

// COSTRUTTORE DI COPIA di UtenteBasic
UtenteBasic::UtenteBasic( const Utente& u ) : UtenteGratis( u ) {}

// METODO UtenteBasic::getUserInfo
QMap<QString, void *> UtenteBasic::getUserInfo( const SmartUtente& su ) const {
    QMap<QString, void *> m;
    m.insert( "username", new QString( su->getUsername() ) );
    m.insert( "name", new QString( su->getName() ) );
    m.insert( "surname", new QString( su->getSurname() ) );
    m.insert( "birtday", new QDate( su->getBirthday() ) );
    m.insert( "maritialStatus", new QString( su->getMaritialStatus() ) );

    return m;
}

// METODO UtenteBasic::getAccountType
QString UtenteBasic::getAccountType() const {
    return "Basic";
}
