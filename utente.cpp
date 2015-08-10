#include "utente.h"
#include "rete.h"
#include "smartutente.h"
#include "formazione.h"
#include "titolo.h"
#include "esperienza.h"
#include "lavoro.h"
#include "database.h"

// COSTRUTTORE Utente
Utente::Utente( const QString& un,
                const QString& name,
                const QString& surname ) :
    username( un ),
    profile( name, surname ),
    net( new Rete ),
    educations( new Formazione ),
    experiences( new Esperienza ),
    references( 1 ) {}

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

// METODO getContactsList Utente
QVector<SmartUtente> Utente::getContactsList() const {
    return net->getContactsList();
}

// METODO addEducation Utente
void Utente::addEducation( Titolo* t ) {
    educations->addEducation( t );
}

// METODO removeEducation Utente
void Utente::removeEducation( Titolo* t ) {
    educations->removeEducation( t );
}

// METODO getEducationsList Utente
QVector<SmartTitolo> Utente::getEducationsList() const {
    return educations->getEducationsList();
}

// METODO getEducationsIterator
Formazione::Iteratore Utente::getEducationsIterator() const {
    return educations->begin();
}

// METODO addExperience Utente
void Utente::addExperience( Lavoro* l ) {
    experiences->addExperience( l );
}

// METODO removeExperience Utente
void Utente::removeExperience( Lavoro* l ) {
    experiences->removeExperience( l );
}

// METODO getExperiencesList Utente
QVector<SmartLavoro> Utente::getExperiencesList() const {
    return experiences->getExperiencesList();
}

// METODO getExperiecesIterator Utente
Esperienza::Iteratore Utente::getExperiencesIterator() const {
    return experiences->begin();
}

// OPERATOR () Utente
void Utente::FuntoreRicerca::operator ()( const SmartUtente& x ) const {}

// OPERATOR << Utente
QDebug operator <<( QDebug qdbg, const Utente& u ) {
    qdbg << "*** PROFILO UTENTE ***" << "\n";
    qdbg << "USERNAME: " << u.getUsername() << "\n";
    qdbg << "PROFILO:" << "\n";
    qdbg << " Nome: " << u.getName() << "\n";
    qdbg << " Cognome: " << u.getSurname() << "\n";
    qdbg << " Data di nascita: " << u.getBirthday().toString( "dd/MM/yyyy" ) << "\n";
    qdbg << " Stato civile: " << u.getMaritialStatus() << "\n";
    qdbg << "CONTATTI: " << "\n";
    QVector<SmartUtente> c = u.getContactsList();
    if( c.size() == 0 )
        qdbg << " ** Nessun contatto! **" << "\n";
    else {
        for( int i = 0; i < c.size(); i++ )
            qdbg << " " << c[i]->getName() << c[i]->getSurname() << "\n";
    }
    qdbg << "FORMAZIONE: " << "\n";
    QVector<SmartTitolo> ed = u.getEducationsList();
    if( ed.size() == 0 )
        qdbg << " ** Nessun titolo di studio! **" << "\n";
    else {
        for( int i = 0; i < ed.size(); i++ ) {
            qdbg << " Scuola: " << ed[i]->getSchool() << "\n";
            qdbg << " Data diploma: " <<
                    ed[i]->getDateAttended().toString( "yyyy" ) << "\n";
            qdbg << " Laurea: " << ed[i]->getDegree() << "\n";
            qdbg << " Campo di studio: " << ed[i]->getFieldOfStudy() << "\n";
            qdbg << " Votazione: " << ed[i]->getGrade() << "\n";
        }
    }
    qdbg << "ESPERIENZE: " << "\n";
    QVector<SmartLavoro> ex = u.getExperiencesList();
    if( ex.size() == 0 )
        qdbg << " ** Nessuna esperienza lavorativa! **" << "\n";
    else {
        for( int i = 0; i < ex.size(); i++ ) {
            qdbg << " Azienda: " << ex[i]->getCompanyName() << "\n";
            qdbg << " Ruolo: " << ex[i]->getTitle() << "\n";
            qdbg << " Luogo: " << ex[i]->getLocation() << "\n";
            qdbg << " Inizio: " << ex[i]->getBegin().toString( "dd/MM/yyyy" ) << "\n";
            qdbg << " Fine: " << ex[i]->getEnd().toString( "dd/MM/yyyy" ) << "\n";
        }
    }
    return qdbg;
}
