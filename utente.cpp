#include "utente.h"

// COSTRUTTORE DI COPIA di Utente
Utente::Utente( const Utente& u ) :
    username( u.username ),
    profile( u.profile ),
    net( u.net ), // memoria condivisa!
    educations( u.educations ), // memoria condivisa!
    experiences( u.experiences ) // memoria condivisa!
{
    net->references++;
    //educations->references++;
    //experiences->references++;
}

// DISTRUTTORE Utente
Utente::~Utente() {
    net->references--;
    if( !net->references )
        delete net;
    //educations->references--;
    //if( !educations->references )
        delete educations;
    //experiences->references--;
    //if( !experiences->references )
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
QString Utente::getBirthday() const {
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
QVector<QString> Utente::getContactsList() const {
    return net->getContactsList();
}



// Overloading OPERATOR () Utente
void Utente::FuntoreRicerca::operator ()( const SmartUtente& x ) const {
    // ...
    qDebug() << x.getUser()->getProfile();
}

// Overloading OPERATOR << QDebug
QDebug operator <<( QDebug qdbg, Utente* u ) {
    qdbg << "*** PROFILO UTENTE ***\n\n"
         << u->getUsername() << "\n"
         << u->getProfile() << "\n"
         << *( u->getNet() ) << "\n"
         << *( u->getEducations() ) << "\n"
         << *( u->getExperiences() ) << "\n";
    return qdbg;
}
