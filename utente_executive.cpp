#include "utente_executive.h"

// COSTRUTTORE DI COPIA di UtenteExecutive
UtenteExecutive::UtenteExecutive( const Utente& u ) : UtentePagante( u ) {}

// METODO UtenteExecutive::getUserInfo
QMap<QString, void *> UtenteExecutive::getUserInfo( const SmartUtente& su ) const {
    QMap<QString, void *> m;
    m.insert( "username", new QString( su->getUsername() ) );
    m.insert( "name", new QString( su->getName() ) );
    m.insert( "surname", new QString( su->getSurname() ) );
    m.insert( "birtday", new QDate( su->getBirthday() ) );
    m.insert( "maritialStatus", new QString( su->getMaritialStatus() ) );
    m.insert( "experiences", new QVector<SmartLavoro>( su->getExperiencesList() ) );
    m.insert( "educations", new QVector<SmartTitolo>( su->getEducationsList() ) );

    return m;
}

// METODO UtenteExecutive::getAccountType
QString UtenteExecutive::getAccountType() const {
    return "Executive";
}
