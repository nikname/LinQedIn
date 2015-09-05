#include "utente_business.h"

// COSTRUTTORE DI COPIA di UtenteBusiness
UtenteBusiness::UtenteBusiness( const Utente& u ) : UtentePagante( u ) {}

// METODO UtenteBusiness::getAccountType
QString UtenteBusiness::getAccountType() const {
    return "Business";
}

// METODO UtenteBusiness::getUserInfo
QList<QString> UtenteBusiness::getUserInfo() const {
    QList<QString> l;
    l << "name" << "surname" << "personalInfo" << "contacts" << "educations" << "experiences";
    return l;
}
