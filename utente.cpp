#include "lavoro.h"
#include "rete.h"
#include "titolo.h"
#include "utente.h"

// COSTRUTTORE Utente
Utente::Utente( const QString& un, const QString& name, const QString& surname ) :
    username( un ),
    profile( name, surname ),
    net( new Rete() ),
    educations( new Formazione ),
    experiences( new Esperienza ),
    references( 1 )
{}

// COSTRUTTORE DI COPIA Utente
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
    if( net ) {
        net->user_ref--;
        if( net->user_ref == 0 )
            delete net;
    }
    if( educations ) {
        educations->user_ref--;
        if( educations->user_ref == 0 )
            delete educations;
    }
    if( experiences ) {
        experiences->user_ref--;
        if( experiences->user_ref == 0 )
            delete experiences;
    }
}

// METODO Utente::getUsername
QString Utente::getUsername() const {
    return username;
}

// METODO Utente::getName
QString Utente::getName() const {
    return profile.getName();
}

// METODO Utente::getSurname
QString Utente::getSurname() const {
    return profile.getSurname();
}

// METODO Utente::getBirthday
QDate Utente::getBirthday() const {
    return profile.getBirthday();
}

// METODO Utente::getMaritialStatus
QString Utente::getMaritialStatus() const {
    return profile.getMaritialStatus();
}

// METODO Utente::setName( QString )
void Utente::setName( const QString& n ) {
    profile.setName( n );
}

// METODO Utente::setSurname( QString )
void Utente::setSurname( const QString& s ) {
    profile.setSurname( s );
}

// METODO Utente::setBirthday( QDate )
void Utente::setBirthday( const QDate& b ) {
    profile.setBirthday( b );
}

// METODO Utente::setMaritialStatus( QString )
void Utente::setMaritialStatus( const QString& ms ) {
    profile.setMaritialStatus( ms );
}

// METODO Utente::addContact( SmartUtente )
void Utente::addContact( const SmartUtente& su ) {
    net->addContact( su );
}

// METODO Utente::removeContact( SmartUtente )
void Utente::removeContact( const SmartUtente& su ) {
    net->removeContact( su );
}

// METODO Utente::isContact( SmartUtente )
bool Utente::isContact( const SmartUtente& su ) {
    return net->isContact( su );
}

// METODO Utente::getContactsList
QVector<SmartUtente> Utente::getContactsList() const {
    return net->getContactsList();
}

// METODO Utente::addEducation( SmartTitolo )
void Utente::addEducation( const SmartTitolo& t ) {
    educations->addEducation( t );
}

// METODO removeEducation Utente
void Utente::removeEducation( const SmartTitolo& t ) {
    educations->removeEducation( t );
}

// METODO getEducationsList Utente
QVector<SmartTitolo> Utente::getEducationsList() const {
    return educations->getEducationsList();
}

// METODO Utente::getEducationsIterator
Formazione::Iteratore Utente::getEducationsIterator() const {
    return educations->begin();
}

// METODO Utente::addExperience( SmartLavoro )
void Utente::addExperience( const SmartLavoro& l ) {
    experiences->addExperience( l );
}

// METODO Utente::removeExperience( SmartLavoro )
void Utente::removeExperience( const SmartLavoro& l ) {
    experiences->removeExperience( l );
}

// METODO Utente::getExperiencesList
QVector<SmartLavoro> Utente::getExperiencesList() const {
    return experiences->getExperiencesList();
}

// METODO getExperiecesIterator Utente
Esperienza::Iteratore Utente::getExperiencesIterator() const {
    return experiences->begin();
}

// OPERATOR << Utente
QDebug& operator <<( QDebug& qdbg, const Utente& u ) {
    qdbg << "*** PROFILO UTENTE ***" << "\n";
    qdbg << "USERNAME: " << u.getUsername() << "\n";
    qdbg << "PROFILO:" << "\n";
    qdbg << " Nome: " << u.getName() << "\n";
    qdbg << " Cognome: " << u.getSurname() << "\n";
    qdbg << " Data di nascita: " << u.getBirthday().toString( "dd/MM/yyyy" ) << "\n";
    qdbg << " Stato civile: " << u.getMaritialStatus() << "\n";
    if( u.net ) qdbg << *( u.net );
    if( u.educations ) qdbg << *( u.educations );
    if( u.experiences ) qdbg << *( u.experiences );
    return qdbg;
}
