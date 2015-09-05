#include "utente_basic.h"

// COSTRUTTORE DI COPIA di UtenteBasic
UtenteBasic::UtenteBasic( const Utente& u ) : UtenteGratis( u ) {}

// METODO UtenteBasic::getAccountType
QString UtenteBasic::getAccountType() const {
    return "Basic";
}

// METODO UtenteBasic::getUserInfo
QList<QString> UtenteBasic::getUserInfo() const {
    QList<QString> l;
    l << "name" << "surname" << "personalInfo";
    return l;
}
