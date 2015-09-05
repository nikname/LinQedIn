#include "utente_executive.h"
#include "rete.h"

// COSTRUTTORE DI COPIA di UtenteExecutive
UtenteExecutive::UtenteExecutive( const Utente& u ) : UtentePagante( u ) {}

// METODO UtenteExecutive::getAccountType
QString UtenteExecutive::getAccountType() const {
    return "Executive";
}

// METODO UtenteExecutive::getUserInfo
QList<QString> UtenteExecutive::getUserInfo() const {
    QList<QString> l;
    l << "name" << "surname" << "personalInfo" << "educations" << "experiences";
    return l;
}
