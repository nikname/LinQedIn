#include "utente_business.h"

// COSTRUTTORE DI COPIA di UtenteBusiness
UtenteBusiness::UtenteBusiness( const Utente& u ) : UtentePagante( u ) {}

// METODO UtenteBusiness::getUserInfo
QMap<QString, void *> UtenteBusiness::getUserInfo( const SmartUtente& su ) const {
    QMap<QString, void *> m;
    m.insert( "username", new QString( su->getUsername() ) );
    m.insert( "name", new QString( su->getName() ) );
    m.insert( "surname", new QString( su->getSurname() ) );
    m.insert( "birtday", new QDate( su->getBirthday() ) );
    m.insert( "maritialStatus", new QString( su->getMaritialStatus() ) );
    m.insert( "experiences", new QVector<SmartLavoro>( su->getExperiencesList() ) );
    m.insert( "educations", new QVector<SmartTitolo>( su->getEducationsList() ) );
    m.insert( "connections", new QVector<SmartUtente>( su->getContactsList() ) );

    return m;
}

// METODO UtenteBusiness::getAccountType
QString UtenteBusiness::getAccountType() const {
    return "Business";
}
