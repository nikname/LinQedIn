#include "utente.h"
#include "rete.h"
#include "smartutente.h"
#include "formazione.h"
#include "titolo.h"
#include "esperienza.h"
#include "lavoro.h"
#include "database.h"

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

// METODO getUsername Utente
QString Utente::getUsername() const {
    return username;
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
void Utente::addContact( const SmartUtente& su ) {
    net->addContact( su );
}

// METODO removeContact Utente
void Utente::removeContact( const SmartUtente& su ) {
    net->removeContact( su );
}

// METODO Utente::isContact
bool Utente::isContact( const SmartUtente& su ) {
    return net->isContact( su );
}

// METODO getContactsList Utente
QVector<SmartUtente> Utente::getContactsList() const {
    return net->getContactsList();
}

// METODO addEducation Utente
void Utente::addEducation( SmartTitolo t ) {
    educations->addEducation( t );
}

// METODO removeEducation Utente
void Utente::removeEducation( SmartTitolo t ) {
    educations->removeEducation( t );
}

// METODO getEducationsList Utente
QVector<SmartTitolo> Utente::getEducationsList() const {
    return educations->getEducationsList();
}

// METODO Utente::setEducationsList
void Utente::setEducationsList( QVector<SmartTitolo> v ) {
    educations->setEducationsList( v );
}

// METODO getEducationsIterator
Formazione::Iteratore Utente::getEducationsIterator() const {
    return educations->begin();
}

// METODO addExperience Utente
void Utente::addExperience( SmartLavoro l ) {
    experiences->addExperience( l );
}

// METODO removeExperience Utente
void Utente::removeExperience( SmartLavoro l ) {
    experiences->removeExperience( l );
}

// METODO getExperiencesList Utente
QVector<SmartLavoro> Utente::getExperiencesList() const {
    return experiences->getExperiencesList();
}

// METODO Utente::setExperiencesList
void Utente::setExperiencesList( QVector<SmartLavoro> v ) {
    experiences->setExperiencesList( v );
}

// METODO getExperiecesIterator Utente
Esperienza::Iteratore Utente::getExperiencesIterator() const {
    return experiences->begin();
}

// OPERATOR << Utente
QDebug operator <<( QDebug qdbg, const Utente& u ) {
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
