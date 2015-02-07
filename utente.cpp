#include "utente.h"

// COSTRUTTORE DI COPIA di Utente
Utente::Utente( const Utente& u ) :
    username( u.username ),
    profile( u.profile ),
    net( u.net ),
    educations( u.educations ),
    experiences( u.experiences )
{
    net->user_ref++;
    educations->user_ref++;
    experiences->user_ref++;
}

// DISTRUTTORE Utente
Utente::~Utente() {
    net->user_ref--;
    if( net->user_ref == 0 )
        delete net;
    educations->user_ref--;
    if( educations->user_ref == 0 )
        delete educations;
    experiences->user_ref--;
    if( experiences->user_ref == 0 )
        delete experiences;
}

// METODO getUsername Utente
QString Utente::getUsername() {
    return username;
}

// METODO setLogin Utente
void Utente::setUsername( const QString& l ) {
    //TODO: controlla che non sia già utilizzato
    //try{
    //    if( db.findUser( l ) )
    //        throw new Exception( "Username non disponibile!" );
    //}catch( Exception e ){
    //    qDebug() << e;
    //}
    username = l;
}

// METODO getName Utente
QString Utente::getName() const {
    return profile.getName();
}

// METODO getSurname Utente
QString Utente::getSurname() const {
    return profile.getSurname();
}

// METODO getBirthday Utente
QDate Utente::getBirthday() const {
    return profile.getBirthday();
}

// METODO getMaritialStatus Utente
QString Utente::getMaritialStatus() const {
    return profile.getMaritialStatus();
}

// METODO setName Utente
void Utente::setName( const QString& n ) {
    profile.setName( n );
}

// METODO setSurname Utente
void Utente::setSurname( const QString& s ) {
    profile.setSurname( s );
}

// METODO setBirthday Utente
void Utente::setBirthday( const QDate& b ) {
    profile.setBirthday( b );
}

// METODO setMaritialStatus Utente
void Utente::setMaritialStatus( const QString& ms ) {
    profile.setMaritialStatus( ms );
}

// METODO addContact Utente
void Utente::addContact( const QString& un, Database* db ) {
    net->addContact( un, db );
}

// METODO removeContact Utente
void Utente::removeContact( const QString& un, Database* db ) {
    net->removeContact( un, db );
}

// METODO getContactsList Utente
QVector<SmartUtente> Utente::getContactsList() const {
    return net->getContactsList();
}



// OPERATOR () Utente
void Utente::FuntoreRicerca::operator ()( const SmartUtente& x ) const {
    // ...
}

// OPERATOR << Utente
QDebug operator <<( QDebug qdbg, const Utente& u ) {
    qdbg << "*** PROFILO UTENTE ***";
    // ...
    return qdbg;
}
